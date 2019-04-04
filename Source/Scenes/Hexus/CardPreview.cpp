#include "CardPreview.h"

#include "cocos/base/CCDirector.h"

#include "Engine/Input/ClickableTextNode.h"
#include "Engine/Localization/ConstantString.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/Localization/LocalizedString.h"
#include "Engine/Utils/HackUtils.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardRow.h"
#include "Scenes/Hexus/Config.h"
#include "Scenes/Hexus/GameState.h"

#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

#include "Strings/Generics/Empty.h"
#include "Strings/Hexus/BinLabel.h"
#include "Strings/Hexus/CardDescriptions/Absorb.h"
#include "Strings/Hexus/CardDescriptions/Addition.h"
#include "Strings/Hexus/CardDescriptions/BonusMoves.h"
#include "Strings/Hexus/CardDescriptions/Clear.h"
#include "Strings/Hexus/CardDescriptions/Drank.h"
#include "Strings/Hexus/CardDescriptions/DrawEffect.h"
#include "Strings/Hexus/CardDescriptions/Flip1.h"
#include "Strings/Hexus/CardDescriptions/Flip2.h"
#include "Strings/Hexus/CardDescriptions/Flip3.h"
#include "Strings/Hexus/CardDescriptions/Flip4.h"
#include "Strings/Hexus/CardDescriptions/Greed.h"
#include "Strings/Hexus/CardDescriptions/Heal.h"
#include "Strings/Hexus/CardDescriptions/Inverse.h"
#include "Strings/Hexus/CardDescriptions/Kill.h"
#include "Strings/Hexus/CardDescriptions/LogicalAnd.h"
#include "Strings/Hexus/CardDescriptions/LogicalOr.h"
#include "Strings/Hexus/CardDescriptions/LogicalXor.h"
#include "Strings/Hexus/CardDescriptions/Mov.h"
#include "Strings/Hexus/CardDescriptions/Peek.h"
#include "Strings/Hexus/CardDescriptions/Poison.h"
#include "Strings/Hexus/CardDescriptions/ReturnToHand.h"
#include "Strings/Hexus/CardDescriptions/ShiftLeft.h"
#include "Strings/Hexus/CardDescriptions/ShiftRight.h"
#include "Strings/Hexus/CardDescriptions/Steal.h"
#include "Strings/Hexus/CardDescriptions/Subtract.h"
#include "Strings/Hexus/CardDescriptions/SuddenDeath.h"
#include "Strings/Hexus/DecLabel.h"
#include "Strings/Hexus/HexLabel.h"
#include "Strings/Menus/Help.h"

using namespace cocos2d;

CardPreview* CardPreview::create()
{
	CardPreview* instance = new CardPreview();

	instance->autorelease();

	return instance;
}

CardPreview::CardPreview()
{
	this->cardPad = Sprite::create(HexusResources::CardPad);
	this->previewPanel = Node::create();
	this->currentPreviewCard = nullptr;

	LocalizedLabel* helpLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::H3, Strings::Menus_Help::create());
	LocalizedLabel* helpLabelSelected = helpLabel->clone();

	helpLabel->enableOutline(Color4B::BLACK, 2);
	helpLabelSelected->enableOutline(Color4B::BLACK, 2);

	this->helpButton = ClickableTextNode::create(
		helpLabel,
		helpLabelSelected,
		UIResources::Menus_Buttons_SmallGenericButton,
		UIResources::Menus_Buttons_SmallGenericButtonSelected
	);

	this->addChild(this->cardPad);
	this->addChild(this->previewPanel);
	this->addChild(this->helpButton);
}

CardPreview::~CardPreview()
{
}

void CardPreview::onEnter()
{
	super::onEnter();

	this->clearPreview();
}

void CardPreview::initializePositions()
{
	super::initializePositions();

	this->helpButton->setPosition(Vec2(0.0f, -212.0f));
}

void CardPreview::clearPreview()
{
	this->previewCard(nullptr);
}

void CardPreview::previewCard(Card* card)
{
	if (card == nullptr || card != this->currentPreviewCard)
	{
		this->currentPreviewCard = card;
		this->previewPanel->removeAllChildren();

		if (card == nullptr)
		{
			this->helpButton->setVisible(false);
			return;
		}

		Sprite* previewSprite = Sprite::create(card->cardData->cardResourceFile);
		this->previewPanel->addChild(previewSprite);
		this->helpButton->setVisible(true);

		switch (card->cardData->cardType)
		{
			case CardData::CardType::Decimal:
			case CardData::CardType::Binary:
			case CardData::CardType::Hexidecimal:
			{
				int attack = card->getAttack();

				// Show special effects for 0 cards
				if (card->getOriginalAttack() == 0)
				{
					LocalizedLabel* specialLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::P, Strings::Hexus_CardDescriptions_DrawEffect::create());

					specialLabel->setAnchorPoint(Vec2(0.0f, 1.0f));
					specialLabel->setTextColor(Card::specialColor);
					specialLabel->enableOutline(Color4B::BLACK, 2);
					specialLabel->setPosition(Vec2(-previewSprite->getContentSize().width / 2.0f + 8.0f, 160.0f));
					specialLabel->setDimensions(previewSprite->getContentSize().width - 16.0f, 0.0f);

					this->previewPanel->addChild(specialLabel);
				}

				LocalizedLabel* binaryLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Coding, LocalizedLabel::FontSize::H2, Strings::Hexus_BinLabel::create());
				LocalizedLabel* decimalLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Coding, LocalizedLabel::FontSize::H2, Strings::Hexus_DecLabel::create());
				LocalizedLabel* hexLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Coding, LocalizedLabel::FontSize::H2, Strings::Hexus_HexLabel::create());

				ConstantString* binaryString = ConstantString::create(HackUtils::toBinary4(attack));
				ConstantString* decimalString = ConstantString::create(std::to_string(attack));
				ConstantString* hexString = ConstantString::create(HackUtils::toHex(attack));

				binaryLabel->setStringReplacementVariables(binaryString);
				decimalLabel->setStringReplacementVariables(decimalString);
				hexLabel->setStringReplacementVariables(hexString);

				binaryLabel->setAnchorPoint(Vec2::ZERO);
				decimalLabel->setAnchorPoint(Vec2::ZERO);
				hexLabel->setAnchorPoint(Vec2::ZERO);

				binaryLabel->setTextColor(Card::binaryColor);
				decimalLabel->setTextColor(Card::decimalColor);
				hexLabel->setTextColor(Card::hexColor);

				binaryLabel->enableOutline(Color4B::BLACK, 3);
				decimalLabel->enableOutline(Color4B::BLACK, 3);
				hexLabel->enableOutline(Color4B::BLACK, 3);

				const float yOffset = -72.0f;

				binaryLabel->setPosition(Vec2(-previewSprite->getContentSize().width / 2.0f + 8.0f, yOffset));
				decimalLabel->setPosition(Vec2(-previewSprite->getContentSize().width / 2.0f + 8.0f, yOffset - 40.0f));
				hexLabel->setPosition(Vec2(-previewSprite->getContentSize().width / 2.0f + 8.0f, yOffset - 80.0f));

				this->previewPanel->addChild(binaryLabel);
				this->previewPanel->addChild(decimalLabel);
				this->previewPanel->addChild(hexLabel);

				break;
			}
			default:
			{
				LocalizedLabel* specialLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::P, Strings::Generics_Empty::create());

				specialLabel->setAnchorPoint(Vec2(0.0f, 0.0f));
				specialLabel->setTextColor(Card::specialColor);
				specialLabel->enableOutline(Color4B::BLACK, 2);
				specialLabel->setPosition(Vec2(-previewSprite->getContentSize().width / 2.0f + 8.0f, -160.0f));
				specialLabel->setDimensions(previewSprite->getContentSize().width - 16.0f, 0.0f);

				// TODO: Not a fan of allocating memory at runtime like this by calling create, maybe this is fine though
				switch (card->cardData->cardType)
				{
					case CardData::CardType::Special_MOV:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Mov::create());
						break;
					}
					case CardData::CardType::Special_AND:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_LogicalAnd::create());
						break;
					}
					case CardData::CardType::Special_OR:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_LogicalOr::create());
						break;
					}
					case CardData::CardType::Special_XOR:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_LogicalXor::create());
						break;
					}
					case CardData::CardType::Special_SHL:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_ShiftLeft::create());
						break;
					}
					case CardData::CardType::Special_SHR:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_ShiftRight::create());
						break;
					}
					case CardData::CardType::Special_INV:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Inverse::create());
						break;
					}
					case CardData::CardType::Special_FLIP1:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Flip1::create());
						break;
					}
					case CardData::CardType::Special_FLIP2:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Flip2::create());
						break;
					}
					case CardData::CardType::Special_FLIP3:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Flip3::create());
						break;
					}
					case CardData::CardType::Special_FLIP4:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Flip4::create());
						break;
					}
					case CardData::CardType::Special_ADD:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Addition::create());
						break;
					}
					case CardData::CardType::Special_SUB:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Subtract::create());
						break;
					}
					case CardData::CardType::Special_CLEAR:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Clear::create());
						break;
					}
					case CardData::CardType::Special_SUDDEN_DEATH:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_SuddenDeath::create());
						break;
					}
					case CardData::CardType::Special_GREED:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Greed::create());
						break;
					}
					case CardData::CardType::Special_ABSORB:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Absorb::create());
						break;
					}
					case CardData::CardType::Special_KILL:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Kill::create());
						break;
					}
					case CardData::CardType::Special_RETURN_TO_HAND:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_ReturnToHand::create());
						break;
					}
					case CardData::CardType::Special_STEAL:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Steal::create());
						break;
					}
					case CardData::CardType::Special_BONUS_MOVES:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_BonusMoves::create());
						break;
					}
					case CardData::CardType::Special_PEEK:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Peek::create());
						break;
					}
					case CardData::CardType::Special_HEAL:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Heal::create());
						break;
					}
					case CardData::CardType::Special_POISON:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Poison::create());
						break;
					}
					case CardData::CardType::Special_DRANK:
					{
						specialLabel->setLocalizedString(Strings::Hexus_CardDescriptions_Drank::create());
						break;
					}
					default:
					{
						break;
					}
				}

				this->previewPanel->addChild(specialLabel);
				break;
			}
		}
	}
}