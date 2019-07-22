#pragma once

#include "Objects/Platformer/Breakables/CagedAnimals/CagedAnimal.h"

namespace cocos2d
{
	class Sprite;
};

class CagedTucan : public CagedAnimal
{
public:
	static CagedTucan* create(cocos2d::ValueMap& initProperties);

	static const std::string MapKeyCagedTucan;

protected:
	CagedTucan(cocos2d::ValueMap& initProperties);
	virtual ~CagedTucan();

	void initializePositions() override;

private:
	typedef CagedAnimal super;

	cocos2d::Sprite* animalSprite;
};
