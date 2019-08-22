#include "Lycan.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/EntityResources.h"
#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string Lycan::MapKeyLycan = "lycan";
HexusOpponentData* Lycan::HexusOpponentDataInstance = nullptr;
const std::string Lycan::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_LYCAN";

Lycan* Lycan::deserialize(ValueMap& properties)
{
	Lycan* instance = new Lycan(properties);

	instance->autorelease();

	return instance;
}

Lycan::Lycan(ValueMap& properties) : super(properties,
	Lycan::MapKeyLycan,
	EntityResources::Npcs_EndianForest_Lycan_Animations,
	EntityResources::Npcs_EndianForest_Lycan_Emblem,
	Size(112.0f, 160.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Lycan::getHexusOpponentData();
}

Lycan::~Lycan()
{
}

Vec2 Lycan::getDialogueOffset()
{
	return Vec2(-32.0f, -112.0f);
}

HexusOpponentData* Lycan::getHexusOpponentData()
{
	if (Lycan::HexusOpponentDataInstance == nullptr)
	{
		Lycan::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Npcs_EndianForest_Lycan_Animations,
			HexusResources::Menus_HexusFrameEndianForest,
			1.0f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			Lycan::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Earth,
			0.071f,
			HexusOpponentData::generateDeck(32, 0.071f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip2),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip1),

			}),
			nullptr
		);
	}

	return Lycan::HexusOpponentDataInstance;
}