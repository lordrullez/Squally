#include "SkeletalCleaver.h"

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

const std::string SkeletalCleaver::MapKey = "skeletal-cleaver";
HexusOpponentData* SkeletalCleaver::HexusOpponentDataInstance = nullptr;
const std::string SkeletalCleaver::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_SKELETAL_CLEAVER";

SkeletalCleaver* SkeletalCleaver::deserialize(ValueMap& properties)
{
	SkeletalCleaver* instance = new SkeletalCleaver(properties);

	instance->autorelease();

	return instance;
}

SkeletalCleaver::SkeletalCleaver(ValueMap& properties) : super(properties,
	SkeletalCleaver::MapKey,
	EntityResources::Enemies_LambdaCrypts_SkeletalCleaver_Animations,
	EntityResources::Enemies_LambdaCrypts_SkeletalCleaver_Emblem,
	Size(128.0f, 312.0f),
	0.8f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = SkeletalCleaver::getHexusOpponentData();
}

SkeletalCleaver::~SkeletalCleaver()
{
}

Vec2 SkeletalCleaver::getDialogueOffset()
{
	return Vec2(0.0f, 0.0f);
}

LocalizedString* SkeletalCleaver::getEntityName()
{
	return Strings::Platformer_Entities_Names_Enemies_LambdaCrypts_SkeletalCleaver::create();
}

HexusOpponentData* SkeletalCleaver::getHexusOpponentData()
{
	if (SkeletalCleaver::HexusOpponentDataInstance == nullptr)
	{
		SkeletalCleaver::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameLambdaCrypts,
			Vec2(-32.0f, -112.0f),
			SkeletalCleaver::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			HexusOpponentData::generateDeck(32, 0.667f,
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

	return SkeletalCleaver::HexusOpponentDataInstance;
}