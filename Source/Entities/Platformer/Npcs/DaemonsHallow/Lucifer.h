#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;

class Lucifer : public PlatformerFriendly
{
public:
	static Lucifer* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyLucifer;

private:
	typedef PlatformerFriendly super;
	Lucifer(cocos2d::ValueMap& properties);
	~Lucifer();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
