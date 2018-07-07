#include "LionMan.h"

const std::string LionMan::KeyEnemyLionMan = "lion_man";

LionMan* LionMan::deserialize(ValueMap* initProperties)
{
	LionMan* instance = new LionMan(initProperties);

	instance->autorelease();

	return instance;
}

LionMan::LionMan(ValueMap* initProperties) : PlatformerEnemy(initProperties,
	Resources::Entities_Platformer_Environment_Ruins_LionMan_Animations,
	false,
	Size(256.0f, 326.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
}

LionMan::~LionMan()
{
}