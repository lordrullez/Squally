#include "CagedBat.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Scenes/Platformer/Save/SaveKeys.h"

#include "Resources/ObjectResources.h"

using namespace cocos2d;

const std::string CagedBat::MapKeyCagedBat = "caged-bat";

CagedBat* CagedBat::create(ValueMap& initProperties)
{
	CagedBat* instance = new CagedBat(initProperties);

	instance->autorelease();

	return instance;
}

CagedBat::CagedBat(ValueMap& initProperties) : super(initProperties, SaveKeys::SaveKeyCollectableAnimalBat)
{
	this->animalSprite = Sprite::create(ObjectResources::Collectables_Animals_Bat);

	this->animalNode->addChild(this->animalSprite);
}

CagedBat::~CagedBat()
{
}

void CagedBat::initializePositions()
{
	super::initializePositions();

	this->animalSprite->setPosition(Vec2(0.0f, -16.0f));
}
