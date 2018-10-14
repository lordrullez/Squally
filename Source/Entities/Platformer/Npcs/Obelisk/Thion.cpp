#include "Thion.h"

const std::string Thion::MapKeyNpcThion = "thion";

Thion* Thion::deserialize(ValueMap* initProperties)
{
	Thion* instance = new Thion(initProperties);

	instance->autorelease();

	return instance;
}

Thion::Thion(ValueMap* initProperties) : NpcBase(initProperties,
	Resources::Entities_Platformer_Environment_Obelisk_Npcs_Thion_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Thion::~Thion()
{
}