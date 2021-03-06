#include "TargetSelectionMenu.h"

#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCEventListenerKeyboard.h"
#include "cocos/base/CCValue.h"

#include "Engine/Events/ObjectEvents.h"
#include "Engine/Input/ClickableTextNode.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/Utils/GameUtils.h"
#include "Entities/Platformer/PlatformerEnemy.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Entities/Platformer/PlatformerFriendly.h"
#include "Events/CombatEvents.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/EntitySelectionBehavior.h"
#include "Scenes/Platformer/Level/Combat/Menus/ChooseTargetMenu.h"
#include "Scenes/Platformer/Level/Combat/Timeline.h"
#include "Scenes/Platformer/Level/Combat/TimelineEntry.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/UIResources.h"

using namespace cocos2d;

TargetSelectionMenu* TargetSelectionMenu::create(Timeline* timelineRef)
{
	TargetSelectionMenu* instance = new TargetSelectionMenu(timelineRef);

	instance->autorelease();

	return instance;
}

TargetSelectionMenu::TargetSelectionMenu(Timeline* timelineRef)
{
	this->timelineRef = timelineRef;
	this->selectedEntity = nullptr;
	this->allowedSelection = AllowedSelection::None;
	this->chooseTargetMenu = ChooseTargetMenu::create();

	this->addChild(this->chooseTargetMenu);
}

void TargetSelectionMenu::onEnter()
{
	super::onEnter();

	this->setVisible(false);

	this->scheduleUpdate();
}

void TargetSelectionMenu::initializePositions()
{
	super::initializePositions();
}

void TargetSelectionMenu::initializeListeners()
{
	super::initializeListeners();

	this->addEventListenerIgnorePause(EventListenerCustom::create(CombatEvents::EventChangeMenuState, [=](EventCustom* args)
	{
		CombatEvents::MenuStateArgs* combatArgs = static_cast<CombatEvents::MenuStateArgs*>(args->getUserData());

		if (combatArgs != nullptr)
		{
			switch (combatArgs->currentMenu)
			{
				case CombatEvents::MenuStateArgs::CurrentMenu::DefendSelect:
				{
					// For now, there is no defend select menu. Just wait for this state to pass.
					break;
				}
				case CombatEvents::MenuStateArgs::CurrentMenu::ActionSelect:
				case CombatEvents::MenuStateArgs::CurrentMenu::ItemSelect:
				case CombatEvents::MenuStateArgs::CurrentMenu::AttackSelect:
				{
					this->allowedSelection = AllowedSelection::None;
					this->clearEntityClickCallbacks();
					this->selectEntity(combatArgs->entry == nullptr ? nullptr : combatArgs->entry->getEntity());

					this->setVisible(true);

					break;
				}
				case CombatEvents::MenuStateArgs::CurrentMenu::ChooseAttackTarget:
				{
					this->allowedSelection = AllowedSelection::Enemy;
					this->isActive = true;

					this->setEntityClickCallbacks();
					this->selectEntity(nullptr);
					this->selectNext(false);

					this->setVisible(true);
					break;
				}
				case CombatEvents::MenuStateArgs::CurrentMenu::ChooseBuffTarget:
				{
					this->allowedSelection = AllowedSelection::Player;
					this->isActive = true;

					this->setEntityClickCallbacks();
					this->selectEntity(nullptr);
					this->selectNext(false);
					
					this->setVisible(true);
					break;
				}
				default:
				{
					this->selectEntity(nullptr);
					this->allowedSelection = AllowedSelection::None;
					this->clearEntityClickCallbacks();
					break;
				}
			}
		}
	}));

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_A, EventKeyboard::KeyCode::KEY_LEFT_ARROW }, [=](InputEvents::InputArgs* args)
	{
		this->selectNext(true);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_D, EventKeyboard::KeyCode::KEY_RIGHT_ARROW }, [=](InputEvents::InputArgs* args)
	{
		this->selectNext(false);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_ENTER, EventKeyboard::KeyCode::KEY_SPACE }, [=](InputEvents::InputArgs* args)
	{
		this->chooseCurrentTarget();
	});
}

void TargetSelectionMenu::update(float dt)
{
	super::update(dt);
}

void TargetSelectionMenu::chooseCurrentTarget()
{
	if (!this->isActive || this->selectedEntity == nullptr)
	{
		return;
	}

	CombatEvents::TriggerSelectCastTarget(CombatEvents::CastTargetArgs(this->selectedEntity));
	CombatEvents::TriggerMenuStateChange(CombatEvents::MenuStateArgs(CombatEvents::MenuStateArgs::CurrentMenu::Closed, nullptr));
}

void TargetSelectionMenu::selectEntity(PlatformerEntity* entity)
{
	this->selectedEntity = entity;
	
	CombatEvents::TriggerSelectionChanged(CombatEvents::SelectionArgs(this->selectedEntity));
}

void TargetSelectionMenu::selectNext(bool directionIsLeft)
{
	if (!this->isActive || this->allowedSelection == AllowedSelection::None)
	{
		return;
	}

	std::vector<PlatformerEntity*> targetEntityGroup = std::vector<PlatformerEntity*>();

	for (auto next : timelineRef->getEntries())
	{
		PlatformerEntity* entity = next->getEntity();

		if (entity->getStateOrDefaultBool(StateKeys::IsAlive, true))
		{
			if (this->allowedSelection == AllowedSelection::Either
				|| (next->isPlayerEntry() && this->allowedSelection == AllowedSelection::Player)
				|| (!next->isPlayerEntry() && this->allowedSelection == AllowedSelection::Enemy))
			{
				targetEntityGroup.push_back(entity);
			}
		}
	}

	if (targetEntityGroup.empty())
	{
		return;
	}

	auto entityPosition = std::find(targetEntityGroup.begin(), targetEntityGroup.end(), this->selectedEntity);

	if (this->selectedEntity == nullptr)
	{
		this->selectEntity(targetEntityGroup.front());
	}
	else if (entityPosition != std::end(targetEntityGroup))
	{
		if (directionIsLeft)
		{
			// Looping disabled -- just go back if cycled through all entities
			if (*entityPosition == targetEntityGroup.front())
			{
				CombatEvents::TriggerMenuGoBack();
				return;
			}

			PlatformerEntity* nextEntity = (*entityPosition == targetEntityGroup.front()) ? targetEntityGroup.back() : *std::prev(entityPosition);

			this->selectEntity(nextEntity);
		}
		else
		{
			auto next = std::next(entityPosition);

			// Looping disabled -- just go back if cycled through all entities
			// Edit: Nvm, looping actually feels more natural when scrolling right, whereas going back is more natural when scrolling left
			/*
			if (next == std::end(targetEntityGroup))
			{
				CombatEvents::TriggerMenuGoBack();
				return;
			}
			*/

			PlatformerEntity* nextEntity = (next != std::end(targetEntityGroup)) ? *next : targetEntityGroup.front();

			this->selectEntity(nextEntity);
		}
	}
	else
	{
		this->selectEntity(nullptr);
	}
}

void TargetSelectionMenu::setEntityClickCallbacks()
{
	for (auto next : timelineRef->getEntries())
	{
		this->setEntityClickCallbacks(next->getEntity());
	}
}

void TargetSelectionMenu::setEntityClickCallbacks(PlatformerEntity* entity)
{
	entity->getAttachedBehavior<EntitySelectionBehavior>([=](EntitySelectionBehavior* selection)
	{
		if (!entity->getStateOrDefaultBool(StateKeys::IsAlive, true)
			|| (this->allowedSelection == AllowedSelection::Player && dynamic_cast<PlatformerFriendly*>(entity) == nullptr)
			|| (this->allowedSelection == AllowedSelection::Enemy && dynamic_cast<PlatformerEnemy*>(entity) == nullptr))
		{
			return;
		}

		PlatformerEntity* entityRef = entity;

		selection->setEntityClickCallbacks([=]()
		{
			CombatEvents::TriggerSelectCastTarget(CombatEvents::CastTargetArgs(entityRef));
			CombatEvents::TriggerMenuStateChange(CombatEvents::MenuStateArgs(CombatEvents::MenuStateArgs::CurrentMenu::Closed, nullptr));
		},
		[=]()
		{
			this->selectEntity(entityRef);
		});
	});
}

void TargetSelectionMenu::clearEntityClickCallbacks()
{
	for (auto next : timelineRef->getEntries())
	{
		EntitySelectionBehavior* selection = next->getEntity()->getAttachedBehavior<EntitySelectionBehavior>();
		
		if (selection != nullptr)
		{
			selection->clearEntityClickCallbacks();
		}
	}
}
