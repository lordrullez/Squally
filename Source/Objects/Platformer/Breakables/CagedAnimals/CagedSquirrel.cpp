#include "CagedSquirrel.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Scenes/Platformer/Save/SaveKeys.h"

#include "Resources/ObjectResources.h"

using namespace cocos2d;

const std::string CagedSquirrel::MapKeyCagedSquirrel = "caged-squirrel";

CagedSquirrel* CagedSquirrel::create(ValueMap& initProperties)
{
	CagedSquirrel* instance = new CagedSquirrel(initProperties);

	instance->autorelease();

	return instance;
}

CagedSquirrel::CagedSquirrel(ValueMap& initProperties) : super(initProperties, SaveKeys::SaveKeyCollectableAnimalSquirrel)
{
	this->animalSprite = Sprite::create(ObjectResources::Collectables_Animals_Squirrel);

	this->animalNode->addChild(this->animalSprite);
}

CagedSquirrel::~CagedSquirrel()
{
}

void CagedSquirrel::initializePositions()
{
	super::initializePositions();

	this->animalSprite->setPosition(Vec2(0.0f, -16.0f));
}
