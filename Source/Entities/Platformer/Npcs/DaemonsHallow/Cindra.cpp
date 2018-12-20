////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "Cindra.h"

#include "Resources/EntityResources.h"

const std::string Cindra::MapKeyCindra = "cindra";

Cindra* Cindra::deserialize(cocos2d::ValueMap* initProperties)
{
	Cindra* instance = new Cindra(initProperties);

	instance->autorelease();

	return instance;
}

Cindra::Cindra(cocos2d::ValueMap* initProperties) : NpcBase(initProperties,
	EntityResources::Npcs_DaemonsHallow_Cindra_Animations,
	PlatformerCollisionType::FriendlyNpc,
	cocos2d::Size(112.0f, 160.0f),
	1.0f,
	cocos2d::Vec2(0.0f, 0.0f))
{
}

Cindra::~Cindra()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////