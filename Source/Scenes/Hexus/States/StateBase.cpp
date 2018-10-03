#include "StateBase.h"

StateBase::StateBase(GameState::StateType stateType)
{
	this->stateType = stateType;
}

StateBase::~StateBase()
{
}

void StateBase::initializeListeners()
{
	SmartNode::initializeListeners();

	EventListenerCustom* beforeStateUpdateListener = EventListenerCustom::create(GameState::beforeStateUpdateEvent, CC_CALLBACK_1(StateBase::onBeforeStateChangeEvent, this));
	EventListenerCustom* onStateUpdateListener = EventListenerCustom::create(GameState::onStateUpdateEvent, CC_CALLBACK_1(StateBase::onStateChangeEvent, this));

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(beforeStateUpdateListener, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(onStateUpdateListener, this);
}

void StateBase::onBeforeStateChangeEvent(EventCustom* eventCustom)
{
	GameState* gameState = (GameState*)(eventCustom->getUserData());

	if (gameState->stateType == this->stateType && gameState->previousStateType != this->stateType)
	{
		this->onBeforeStateEnter(gameState);
	}
	else if (gameState->stateType != this->stateType && gameState->previousStateType == this->stateType)
	{
		this->onStateExit(gameState);
	}
}

void StateBase::onStateChangeEvent(EventCustom* eventCustom)
{
	GameState* gameState = (GameState*)(eventCustom->getUserData());

	if (gameState->stateType == this->stateType)
	{
		if (gameState->previousStateType == this->stateType)
		{
			this->onStateReload(gameState);
		}
		else
		{
			this->onStateEnter(gameState);
		}
	}
}

void StateBase::onBeforeStateEnter(GameState* gameState)
{
}

void StateBase::onStateEnter(GameState* gameState)
{
	/*
	gameState->playerBinaryCards->disableRowCardInteraction();
	gameState->playerBinaryCards->disableRowCardSelection();
	gameState->playerBinaryCards->disableRowSelection();

	gameState->playerDecimalCards->disableRowCardInteraction();
	gameState->playerDecimalCards->disableRowCardSelection();
	gameState->playerDecimalCards->disableRowSelection();

	gameState->playerHexCards->disableRowCardInteraction();
	gameState->playerHexCards->disableRowCardSelection();
	gameState->playerHexCards->disableRowSelection();

	gameState->enemyBinaryCards->disableRowCardInteraction();
	gameState->enemyBinaryCards->disableRowCardSelection();
	gameState->enemyBinaryCards->disableRowSelection();

	gameState->enemyDecimalCards->disableRowCardInteraction();
	gameState->enemyDecimalCards->disableRowCardSelection();
	gameState->enemyDecimalCards->disableRowSelection();

	gameState->enemyHexCards->disableRowCardInteraction();
	gameState->enemyHexCards->disableRowCardSelection();
	gameState->enemyHexCards->disableRowSelection();
	*/
}

void StateBase::onStateReload(GameState* gameState)
{
}

void StateBase::onStateExit(GameState* gameState)
{
}