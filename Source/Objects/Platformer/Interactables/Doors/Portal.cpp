#include "Portal.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCValue.h"

#include "Engine/Events/NavigationEvents.h"
#include "Engine/Input/ClickableNode.h"
#include "Engine/Localization/ConstantString.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/StrUtils.h"
#include "Events/PlatformerEvents.h"
#include "Menus/Interact/InteractMenu.h"
#include "Scenes/Platformer/Level/PlatformerMap.h"
#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"

#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string Portal::MapKey = "portal";
const std::string Portal::MapKeyPortalTransition = "transition";
const std::string Portal::MapKeyPortalMap = "map";

Portal* Portal::create(ValueMap& properties)
{
	Portal* instance = new Portal(properties, Size(properties.at(GameObject::MapKeyWidth).asFloat(), properties.at(GameObject::MapKeyHeight).asFloat()));

	instance->autorelease();

	return instance;
}

Portal::Portal(ValueMap& properties, Size size, Vec2 offset) : super(properties, InteractObject::InteractType::Input, size, offset)
{
	this->mapFile = GameUtils::getKeyOrDefault(this->properties, Portal::MapKeyPortalMap, Value("")).asString();
	this->transition = GameUtils::getKeyOrDefault(this->properties, Portal::MapKeyPortalTransition, Value("")).asString();

	if (this->mapFile.empty())
	{
		this->setInteractType(InteractType::None);
	}
}

Portal::~Portal()
{
}

void Portal::onEnter()
{
	super::onEnter();

	if (!this->getListenEvent().empty())
	{
		this->lock(false);

		this->listenForMapEvent(this->getListenEvent(), [=](ValueMap args)
		{
			this->unlock(true);
		});
	}
}

void Portal::initializePositions()
{
	super::initializePositions();
}

void Portal::initializeListeners()
{
	super::initializeListeners();
}

void Portal::onInteract()
{
	super::onInteract();

	this->loadMap();
}

void Portal::loadMap()
{
	if (this->disabled || this->mapFile.empty() || this->wasTripped)
	{
		return;
	}

	this->wasTripped = true;

	// Load new map after a short delay -- changing scenes in the middle of a collision causes a crash
	// (not sure why, changing to a combat map is fine)
	this->runAction(Sequence::create(
		DelayTime::create(0.1f),
		CallFunc::create([=]()
		{
			NavigationEvents::LoadScene(NavigationEvents::LoadSceneArgs([=]()
			{
				PlatformerEvents::TriggerBeforePlatformerMapChange();
				PlatformerMap* map = PlatformerMap::create("Public/Platformer/Maps/" + this->mapFile + ".tmx", this->transition);

				return map;
			}));
		}),
		nullptr
	));
}
