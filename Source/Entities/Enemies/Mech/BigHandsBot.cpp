#include "BigHandsBot.h"

BigHandsBot* BigHandsBot::create()
{
	BigHandsBot* instance = new BigHandsBot();

	instance->autorelease();

	return instance;
}

BigHandsBot::BigHandsBot() : Enemy::Enemy(
	Resources::Entities_Environment_Mech_BigHandsBot_Animations,
	false)
{
}

BigHandsBot::~BigHandsBot()
{
}