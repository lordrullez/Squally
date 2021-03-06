#include "Piper.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"

#include "Resources/EntityResources.h"
#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string Piper::MapKey = "piper";
HexusOpponentData* Piper::HexusOpponentDataInstance = nullptr;
const std::string Piper::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_PIPER";

Piper* Piper::deserialize(ValueMap& properties)
{
	Piper* instance = new Piper(properties);

	instance->autorelease();

	return instance;
}

Piper::Piper(ValueMap& properties) : super(properties,
	Piper::MapKey,
	EntityResources::Npcs_VoidStar_Piper_Animations,
	EntityResources::Npcs_VoidStar_Piper_Emblem,
	Size(112.0f, 160.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Piper::getHexusOpponentData();
}

Piper::~Piper()
{
}

Vec2 Piper::getDialogueOffset()
{
	return Vec2(0.0f, 0.0f);
}

LocalizedString* Piper::getEntityName()
{
	return Strings::Platformer_Entities_Names_Npcs_VoidStar_Piper::create();
}

HexusOpponentData* Piper::getHexusOpponentData()
{
	if (Piper::HexusOpponentDataInstance == nullptr)
	{
		Piper::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameVoidStar,
			Vec2(-32.0f, -112.0f),
			Piper::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			HexusOpponentData::generateDeck(32, 0.942f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::Subtraction),
				CardList::getInstance()->cardListByName.at(CardKeys::Kill),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalAnd),
				CardList::getInstance()->cardListByName.at(CardKeys::BonusMoves),
				CardList::getInstance()->cardListByName.at(CardKeys::Inverse),
				CardList::getInstance()->cardListByName.at(CardKeys::ReturnToHand),
				CardList::getInstance()->cardListByName.at(CardKeys::Subtraction),
			}),
			nullptr,
			nullptr
		);
	}

	return Piper::HexusOpponentDataInstance;
}