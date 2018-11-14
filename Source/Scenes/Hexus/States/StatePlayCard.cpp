#include "StatePlayCard.h"

StatePlayCard* StatePlayCard::create()
{
	StatePlayCard* instance = new StatePlayCard();

	instance->autorelease();

	return instance;
}

StatePlayCard::StatePlayCard() : StateBase(GameState::StateType::PlayCard)
{
}

StatePlayCard::~StatePlayCard()
{
}

void StatePlayCard::onBeforeStateEnter(GameState* gameState)
{
	StateBase::onBeforeStateEnter(gameState);
}

void StatePlayCard::onStateEnter(GameState* gameState)
{
	StateBase::onStateEnter(gameState);

	if (gameState->selectedHandCard == nullptr)
	{
		this->passFromError(gameState);
		return;
	}

	CardRow* selfHand = nullptr;
	CardRow* selfBinaryRow = nullptr;
	CardRow* selfDecimalRow = nullptr;
	CardRow* selfHexRow = nullptr;
	Deck* selfGraveyard = nullptr;

	switch (gameState->turn)
	{
		case GameState::Turn::Player:
		{
			selfHand = gameState->playerHand;
			selfBinaryRow = gameState->playerBinaryCards;
			selfDecimalRow = gameState->playerDecimalCards;
			selfHexRow = gameState->playerHexCards;
			selfGraveyard = gameState->playerGraveyard;
			break;
		}
		case GameState::Turn::Enemy:
		{
			selfHand = gameState->enemyHand;
			selfBinaryRow = gameState->enemyBinaryCards;
			selfDecimalRow = gameState->enemyDecimalCards;
			selfHexRow = gameState->enemyHexCards;
			selfGraveyard = gameState->enemyGraveyard;
			break;
		}
		default:
		{
			this->passFromError(gameState);
			return;
		}
	}

	switch (gameState->selectedHandCard->cardData->cardType)
	{
		case CardData::CardType::Binary:
		case CardData::CardType::Decimal:
		case CardData::CardType::Hexidecimal:
		{
			if (gameState->selectedRow == nullptr)
			{
				this->passFromError(gameState);
				return;
			}

			selfHand->removeCard(gameState->selectedHandCard);
			gameState->selectedRow->insertCard(gameState->selectedHandCard, Config::insertDelay);
			SoundManager::playSoundResource(Resources::Sounds_Hexus_CardMovement);
			break;
		}
		case CardData::CardType::Special_SHL:
		case CardData::CardType::Special_SHR:
		case CardData::CardType::Special_FLIP1:
		case CardData::CardType::Special_FLIP2:
		case CardData::CardType::Special_FLIP3:
		case CardData::CardType::Special_FLIP4:
		{
			if (gameState->selectedRow == nullptr)
			{
				this->passFromError(gameState);
				return;
			}

			selfHand->removeCard(gameState->selectedHandCard);
			selfGraveyard->insertCardTop(gameState->selectedHandCard, true, Config::insertDelay);

			Card::Operation operation = Card::toOperation(gameState->selectedHandCard->cardData->cardType, 0);

			for (auto it = gameState->selectedRow->rowCards.begin(); it != gameState->selectedRow->rowCards.end(); it++)
			{
				Card* card = *it;

				card->addOperation(operation);
			}

			// Decide which effect and sounds to play
			switch (gameState->selectedHandCard->cardData->cardType)
			{
				case CardData::CardType::Special_SHL:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::MeteorPurple);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_GlitterSpell);
					break;
				}
				case CardData::CardType::Special_SHR:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::MeteorBlue);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Downgrade);
					break;
				}
				case CardData::CardType::Special_FLIP1:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::TargetPulse);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_MagicSlash);
					break;
				}
				case CardData::CardType::Special_FLIP2:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::FrostCirlce);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Freeze);
					break;
				}
				case CardData::CardType::Special_FLIP3:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::RadialGalaxy);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_WindReverse);
					break;
				}
				case CardData::CardType::Special_FLIP4:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::RadialFire);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_BurningStrong);
					break;
				}
				default:
				{
					break;
				}
			}

			break;
		}
		case CardData::CardType::Special_MOV:
		case CardData::CardType::Special_AND:
		case CardData::CardType::Special_OR:
		case CardData::CardType::Special_XOR:
		case CardData::CardType::Special_ADD:
		case CardData::CardType::Special_SUB:
		{
			if (gameState->selectedSourceCard == nullptr || gameState->selectedDestinationCard == nullptr)
			{
				this->passFromError(gameState);
				return;
			}

			selfHand->removeCard(gameState->selectedHandCard);
			selfGraveyard->insertCardTop(gameState->selectedHandCard, true, Config::insertDelay);

			Card::Operation operation = Card::toOperation(
				gameState->selectedHandCard->cardData->cardType,
				gameState->selectedSourceCard->getAttack()
			);

			gameState->selectedDestinationCard->addOperation(operation);

			// Decide which effect and sounds to play
			switch (gameState->selectedHandCard->cardData->cardType)
			{
				case CardData::CardType::Special_MOV:
				{
					gameState->selectedDestinationCard->cardEffects->runEffect(CardEffects::CardEffect::DustPoof);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Shimmer);
					break;
				}
				case CardData::CardType::Special_AND:
				{
					gameState->selectedDestinationCard->cardEffects->runEffect(CardEffects::CardEffect::FireBlast);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Burning);
					break;
				}
				case CardData::CardType::Special_OR:
				{
					gameState->selectedDestinationCard->cardEffects->runEffect(CardEffects::CardEffect::Lightning);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Energy);
					break;
				}
				case CardData::CardType::Special_XOR:
				{
					gameState->selectedDestinationCard->cardEffects->runEffect(CardEffects::CardEffect::RadialStorm);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_GenericSpell);
					break;
				}
				case CardData::CardType::Special_ADD:
				{
					gameState->selectedDestinationCard->cardEffects->runEffect(CardEffects::CardEffect::MagicBurst);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_ChimeShimmer);
					break;
				}
				case CardData::CardType::Special_SUB:
				{
					gameState->selectedDestinationCard->cardEffects->runEffect(CardEffects::CardEffect::StarHit);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_AcidHit);
					break;
				}
				default:
				{
					break;
				}
			}

			break;
		}
		case CardData::CardType::Special_INV:
		{
			if (gameState->selectedDestinationCard == nullptr)
			{
				this->passFromError(gameState);
				return;
			}

			selfHand->removeCard(gameState->selectedHandCard);
			selfGraveyard->insertCardTop(gameState->selectedHandCard, true, Config::insertDelay);

			Card::Operation operation = Card::toOperation(
				gameState->selectedHandCard->cardData->cardType,
				gameState->selectedDestinationCard->getAttack()
			);

			gameState->selectedDestinationCard->addOperation(operation);

			gameState->selectedDestinationCard->cardEffects->runEffect(CardEffects::CardEffect::Bite);
			SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_DemonWhisper);

			break;
		}
		default:
		{
			this->passFromError(gameState);
			return;
		}
	}

	gameState->playableCardsThisTurn = std::max(0, gameState->playableCardsThisTurn - 1);
	gameState->selectedHandCard = nullptr;
	CallFunc* stateTransition = nullptr;

	if (gameState->turn == GameState::Turn::Player)
	{
		if (gameState->playerHand->getCardCount() <= 0)
		{
			stateTransition = CallFunc::create([=]()
			{
				GameState::updateState(gameState, GameState::StateType::Pass);
			});
		}
		else
		{
			if (!gameState->playerPassed && !gameState->enemyPassed && gameState->playableCardsThisTurn <= 0)
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::TurnEnd);
				});
			}
			else
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::Neutral);
				});
			}
		}
	}
	else
	{
		if (gameState->enemyHand->getCardCount() <= 0)
		{
			stateTransition = CallFunc::create([=]()
			{
				GameState::updateState(gameState, GameState::StateType::Pass);
			});
		}
		else
		{
			if (!gameState->playerPassed && !gameState->enemyPassed && gameState->playableCardsThisTurn <= 0)
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::TurnEnd);
				});
			}
			else
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::AIDecidePass);
				});
			}
		}
	}

	this->runAction(Sequence::create(
		DelayTime::create(0.5f),
		stateTransition,
		nullptr
	));
}

void StatePlayCard::onStateReload(GameState* gameState)
{
	StateBase::onStateReload(gameState);
}

void StatePlayCard::onStateExit(GameState* gameState)
{
	StateBase::onStateExit(gameState);

	gameState->selectedSourceCard = nullptr;
	gameState->selectedDestinationCard = nullptr;
}

void StatePlayCard::passFromError(GameState* gameState)
{
	this->runAction(Sequence::create(
		DelayTime::create(0.5f),
		CallFunc::create([=]()
		{
			GameState::updateState(gameState, GameState::StateType::Pass);
		}),
		nullptr
	));
}
