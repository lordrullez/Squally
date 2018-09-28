#include "HexusOpponentJungleGeezer.h"

const std::string HexusOpponentJungleGeezer::StringKeyOpponentName = "Squally_Npc_Names_Jungle_Geezer";
HexusOpponentJungleGeezer* HexusOpponentJungleGeezer::instance = nullptr;

HexusOpponentJungleGeezer* HexusOpponentJungleGeezer::getInstance()
{
	if (HexusOpponentJungleGeezer::instance == nullptr)
	{
		HexusOpponentJungleGeezer::instance = new HexusOpponentJungleGeezer();
	}

	return HexusOpponentJungleGeezer::instance;
}

HexusOpponentJungleGeezer::HexusOpponentJungleGeezer() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Jungle_Npcs_Geezer_Animations,
	1.0f,
	Vec2(0.0f, -48.0f),
	HexusOpponentJungleGeezer::StringKeyOpponentName, Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Binary0),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary1),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary2),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary3),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary4),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary5),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary6),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary7),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary8),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary9),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary10),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary11),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary12),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary13),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary14),
		CardList::getInstance()->cardListByName->at(CardKeys::Binary15),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal0),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal1),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal2),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal3),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal5),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal6),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal7),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal8),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal9),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal10),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal11),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal12),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal13),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal14),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal15),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex0),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex1),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex2),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex3),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex5),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex6),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex7),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex8),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex9),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex10),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex11),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex12),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex13),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex14),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex15),
		CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
		CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalOr),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalXor),
		CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
		CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		CardList::getInstance()->cardListByName->at(CardKeys::Flip1),
		CardList::getInstance()->cardListByName->at(CardKeys::Flip2),
		CardList::getInstance()->cardListByName->at(CardKeys::Flip3),
		CardList::getInstance()->cardListByName->at(CardKeys::Flip4),
		CardList::getInstance()->cardListByName->at(CardKeys::Inverse),
		CardList::getInstance()->cardListByName->at(CardKeys::Inverse),
		CardList::getInstance()->cardListByName->at(CardKeys::Inverse),
		CardList::getInstance()->cardListByName->at(CardKeys::Addition),
		CardList::getInstance()->cardListByName->at(CardKeys::Subtraction),
	})
{
}

HexusOpponentJungleGeezer::~HexusOpponentJungleGeezer()
{
}