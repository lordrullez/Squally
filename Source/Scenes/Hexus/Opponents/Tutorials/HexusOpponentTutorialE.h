#pragma once
#include "cocos2d.h"

#include "Resources/EntityResources.h"
#include "Resources/UIResources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"

using namespace cocos2d;

class HexusOpponentTutorialE : public HexusOpponentData
{
public:
	static HexusOpponentTutorialE* getInstance();

private:
	HexusOpponentTutorialE();
	~HexusOpponentTutorialE();

	static const std::string OpponentSaveKey;
	static HexusOpponentTutorialE* instance;
};
