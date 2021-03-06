#include "DispelIllusionBehavior.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Hackables/HackActivatedAbility.h"
#include "Engine/Utils/GameUtils.h"
#include "Events/PlatformerEvents.h"
#include "Objects/Platformer/Interactables/Doors/Portal.h"
#include "Scenes/Platformer/Hackables/HackFlags.h"

#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string DispelIllusionBehavior::MapKey = "dispel-illusion";
const std::string DispelIllusionBehavior::PropertyGroup = "illusion-group";

DispelIllusionBehavior* DispelIllusionBehavior::create(GameObject* owner)
{
	DispelIllusionBehavior* instance = new DispelIllusionBehavior(owner);

	instance->autorelease();

	return instance;
}

DispelIllusionBehavior::DispelIllusionBehavior(GameObject* owner) : super(owner)
{
	this->object = owner;
	this->group = GameUtils::getKeyOrDefault(this->properties, DispelIllusionBehavior::PropertyGroup, Value("")).asString();

	if (this->object == nullptr)
	{
		this->invalidate();
	}
}

DispelIllusionBehavior::~DispelIllusionBehavior()
{
}

void DispelIllusionBehavior::onLoad()
{
}

void DispelIllusionBehavior::onDisable()
{
	super::onDisable();
}

void DispelIllusionBehavior::registerHackables()
{
	super::registerHackables();

	this->registerHackAbility(HackActivatedAbility::create(
		[=]()
		{
			this->onDispelActivated();
		},
		[=]()
		{
		},
		int(HackFlags::None),
		0.0f,
		UIResources::Menus_Icons_Eye,
		Strings::Menus_Hacking_Abilities_DispelIllusion::create(),
		nullptr
	));
}

void DispelIllusionBehavior::onDispelActivated()
{
	this->toggleHackable(false);

	PlatformerEvents::TriggerDispelIllusion(PlatformerEvents::DispelIllusionArgs(this->group));

	if (this->object != nullptr)
	{
		this->object->runAction(FadeTo::create(0.25f, 0));
	}
}
