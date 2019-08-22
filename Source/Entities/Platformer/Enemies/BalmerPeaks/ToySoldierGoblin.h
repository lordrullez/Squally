#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;

class ToySoldierGoblin : public PlatformerEnemy
{
public:
	static ToySoldierGoblin* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyToySoldierGoblin;

private:
	typedef PlatformerEnemy super;
	ToySoldierGoblin(cocos2d::ValueMap& properties);
	~ToySoldierGoblin();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
