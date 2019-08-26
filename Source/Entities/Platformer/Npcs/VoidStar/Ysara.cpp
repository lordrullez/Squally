#include "Ysara.h"

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

#include "Strings/Platformer/Entities/Names/Npcs/VoidStar/Ysara.h"

using namespace cocos2d;

const std::string Ysara::MapKeyYsara = "ysara";
HexusOpponentData* Ysara::HexusOpponentDataInstance = nullptr;
const std::string Ysara::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_YSARA";

Ysara* Ysara::deserialize(ValueMap& properties)
{
	Ysara* instance = new Ysara(properties);

	instance->autorelease();

	return instance;
}

Ysara::Ysara(ValueMap& properties) : super(properties,
	Ysara::MapKeyYsara,
	EntityResources::Npcs_VoidStar_Ysara_Animations,
	EntityResources::Npcs_VoidStar_Ysara_Emblem,
	Size(112.0f, 160.0f),
	0.85f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Ysara::getHexusOpponentData();
}

Ysara::~Ysara()
{
}

Vec2 Ysara::getDialogueOffset()
{
	return Vec2(0.0f, -32.0f);
}

LocalizedString* Ysara::getEntityName()
{
	return Strings::Platformer_Entities_Names_Npcs_VoidStar_Ysara::create();
}

HexusOpponentData* Ysara::getHexusOpponentData()
{
	if (Ysara::HexusOpponentDataInstance == nullptr)
	{
		Ysara::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Npcs_VoidStar_Ysara_Animations,
			HexusResources::Menus_HexusFrameVoidStar,
			0.85f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			Ysara::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			0.885f,
			HexusOpponentData::generateDeck(32, 0.885f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Addition),
				CardList::getInstance()->cardListByName.at(CardKeys::Inverse),
				CardList::getInstance()->cardListByName.at(CardKeys::ReturnToHand),
				CardList::getInstance()->cardListByName.at(CardKeys::Absorb),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip3),
				CardList::getInstance()->cardListByName.at(CardKeys::Kill),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip4),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),

			}),
			nullptr
		);
	}

	return Ysara::HexusOpponentDataInstance;
}