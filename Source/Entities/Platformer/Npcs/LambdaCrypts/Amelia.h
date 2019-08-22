#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;

class Amelia : public PlatformerFriendly
{
public:
	static Amelia* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyAmelia;

private:
	typedef PlatformerFriendly super;
	Amelia(cocos2d::ValueMap& properties);
	~Amelia();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
