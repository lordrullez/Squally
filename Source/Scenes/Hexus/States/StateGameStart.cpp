#include "StateGameStart.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"

#include "Scenes/Hexus/Deck.h"

using namespace cocos2d;

StateGameStart* StateGameStart::create()
{
	StateGameStart* instance = new StateGameStart();

	instance->autorelease();

	return instance;
}

StateGameStart::StateGameStart() : super(GameState::StateType::GameStart)
{
}

StateGameStart::~StateGameStart()
{
}

void StateGameStart::onBeforeStateEnter(GameState* gameState)
{
	super::onBeforeStateEnter(gameState);

	// Clear all state variables before game start
	gameState->playerLosses = 0;
	gameState->enemyLosses = 0;
	gameState->cardReplaceCount = 0;
	gameState->playerCardsDrawnNextRound = 0;
	gameState->enemyCardsDrawnNextRound = 0;
	gameState->roundNumber = 0;
	gameState->turnNumber = 0;
	gameState->playerPassed = false;
	gameState->enemyPassed = false;
	gameState->playableCardsThisTurn = 0;
}

void StateGameStart::onStateEnter(GameState* gameState)
{
	super::onStateEnter(gameState);

	if (gameState->opponentData->stateOverride != nullptr)
	{
		GameState::updateState(gameState, GameState::StateType::LoadInitialState);
	}
	else
	{
		gameState->playerDeck->shuffle();
		gameState->enemyDeck->shuffle();

		this->runAction(Sequence::create(
			DelayTime::create(0.5f),
			CallFunc::create([=]()
			{
				GameState::updateState(gameState, GameState::StateType::RoundStart);
			}),
			nullptr
		));
	}
}

void StateGameStart::onStateReload(GameState* gameState)
{
	super::onStateReload(gameState);
}

void StateGameStart::onStateExit(GameState* gameState)
{
	super::onStateExit(gameState);
}
