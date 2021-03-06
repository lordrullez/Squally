#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class Ghost : public PlatformerFriendly
{
public:
	static Ghost* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKey;
	
protected:
	Ghost(cocos2d::ValueMap& properties);
	virtual ~Ghost();

private:
	typedef PlatformerFriendly super;

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
