#include "Mummy.h"

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

const std::string Mummy::MapKey = "mummy";
HexusOpponentData* Mummy::HexusOpponentDataInstance = nullptr;
const std::string Mummy::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_MUMMY";

Mummy* Mummy::deserialize(ValueMap& properties)
{
	Mummy* instance = new Mummy(properties);

	instance->autorelease();

	return instance;
}

Mummy::Mummy(ValueMap& properties) : super(properties,
	Mummy::MapKey,
	EntityResources::Helpers_UnderflowRuins_Mummy_Animations,
	EntityResources::Helpers_UnderflowRuins_Mummy_Emblem,
	Size(224.0f, 440.0f),
	0.3f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Mummy::getHexusOpponentData();
}

Mummy::~Mummy()
{
}

Vec2 Mummy::getDialogueOffset()
{
	return Vec2(0.0f, 0.0f);
}

LocalizedString* Mummy::getEntityName()
{
	return Strings::Platformer_Entities_Names_Helpers_UnderflowRuins_Mummy::create();
}

HexusOpponentData* Mummy::getHexusOpponentData()
{
	if (Mummy::HexusOpponentDataInstance == nullptr)
	{
		Mummy::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameUnderflowRuins,
			Vec2(-32.0f, -112.0f),
			Mummy::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Light,
			HexusOpponentData::generateDeck(32, 1.000f,
			{

			}),
			nullptr,
			StateOverride::create(
				// Player losses
				1,
				// Enemy losses
				1,
				// Player's turn
				true,
				// Player passed
				true,
				// Enemy passed
				true,
				// Player deck
				std::vector<CardData*>
				{
					
				},
				// Enemy deck
				std::vector<CardData*>
				{
					
				},
				// Player hand
				std::vector<CardData*>
				{
					
				},
				// Enemy hand
				std::vector<CardData*>
				{
					
				},
				// Player binary cards
				std::vector<CardData*>
				{
					
				},
				// Player decimal cards
				std::vector<CardData*>
				{
					
				},
				// Player hex cards
				std::vector<CardData*>
				{
					
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					
				}
			)
		);
	}

	return Mummy::HexusOpponentDataInstance;
}