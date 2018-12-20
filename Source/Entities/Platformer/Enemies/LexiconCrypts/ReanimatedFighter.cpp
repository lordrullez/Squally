////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "ReanimatedFighter.h"

#include "Resources/EntityResources.h"

const std::string ReanimatedFighter::MapKeyReanimatedFighter = "reanimated-fighter";

ReanimatedFighter* ReanimatedFighter::deserialize(cocos2d::ValueMap* initProperties)
{
	ReanimatedFighter* instance = new ReanimatedFighter(initProperties);

	instance->autorelease();

	return instance;
}

ReanimatedFighter::ReanimatedFighter(cocos2d::ValueMap* initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_LexiconCrypts_ReanimatedFighter_Animations,
	PlatformerCollisionType::Enemy,
	cocos2d::Size(256.0f, 248.0f),
	1.0f,
	cocos2d::Vec2(0.0f, 0.0f))
{
}

ReanimatedFighter::~ReanimatedFighter()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////