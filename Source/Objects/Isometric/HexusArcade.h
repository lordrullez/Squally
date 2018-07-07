#pragma once
#include "cocos2d.h"

#include "Engine/Objects/Hackables/HackableObject.h"

using namespace cocos2d;

class HexusArcade : public HackableObject
{
public:
	static HexusArcade* create(ValueMap* initProperties);

protected:
	HexusArcade(ValueMap* initProperties);
	~HexusArcade();

private:
	void registerHackables();

	Sprite* arcadeMachine;
};