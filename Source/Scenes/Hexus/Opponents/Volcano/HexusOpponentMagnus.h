#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentMagnus : public HexusOpponentData
{
public:
	static HexusOpponentMagnus* getInstance();

private:
	HexusOpponentMagnus();
	~HexusOpponentMagnus();

	static const std::string OpponentSaveKey;
	static HexusOpponentMagnus* instance;
};