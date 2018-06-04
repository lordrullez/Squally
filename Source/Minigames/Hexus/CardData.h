#pragma once
#include "cocos2d.h"
#include "Resources.h"

using namespace cocos2d;

class CardData
{
public:
	std::string getCardTypeString();

	static std::map<std::string, CardData*> cardListByName;
	static std::map<int, CardData*> cardListById;

	// Note: Hard code enum values to allow for future proofing if we ever remove an id
	enum CardType {
		Binary = 0,
		Decimal = 1,
		Hexidecimal = 2,
		Special_AND = 3,
		Special_OR = 4,
		Special_XOR = 5,
		Special_SHL = 6,
		Special_SHR = 7,
		Special_INV = 8,
		Special_FLIP1 = 9,
		Special_FLIP2 = 10,
		Special_FLIP3 = 11,
		Special_FLIP4 = 12,
		Special_ADD = 13,
		Special_SUB = 14,
	};

	std::string cardResourceFile;
	std::string cardName;
	CardType cardType;
	unsigned int attack;

	static const std::string Binary0;
	static const std::string Binary1;
	static const std::string Binary2;
	static const std::string Binary3;
	static const std::string Binary4;
	static const std::string Binary5;
	static const std::string Binary6;
	static const std::string Binary7;
	static const std::string Binary8;
	static const std::string Binary9;
	static const std::string Binary10;
	static const std::string Binary11;
	static const std::string Binary12;
	static const std::string Binary13;
	static const std::string Binary14;
	static const std::string Binary15;
	static const std::string Decimal0;
	static const std::string Decimal1;
	static const std::string Decimal2;
	static const std::string Decimal3;
	static const std::string Decimal4;
	static const std::string Decimal5;
	static const std::string Decimal6;
	static const std::string Decimal7;
	static const std::string Decimal8;
	static const std::string Decimal9;
	static const std::string Decimal10;
	static const std::string Decimal11;
	static const std::string Decimal12;
	static const std::string Decimal13;
	static const std::string Decimal14;
	static const std::string Decimal15;
	static const std::string Hex0;
	static const std::string Hex1;
	static const std::string Hex2;
	static const std::string Hex3;
	static const std::string Hex4;
	static const std::string Hex5;
	static const std::string Hex6;
	static const std::string Hex7;
	static const std::string Hex8;
	static const std::string Hex9;
	static const std::string Hex10;
	static const std::string Hex11;
	static const std::string Hex12;
	static const std::string Hex13;
	static const std::string Hex14;
	static const std::string Hex15;
	static const std::string BinaryAddition;
	static const std::string BinarySubtraction;
	static const std::string Flip1;
	static const std::string Flip2;
	static const std::string Flip3;
	static const std::string Flip4;
	static const std::string LogicalAnd;
	static const std::string LogicalOr;
	static const std::string LogicalXor;
	static const std::string ShiftLeft;
	static const std::string ShiftRight;
	static const std::string BitFlip;
	static const std::string Clear;
	static const std::string Greed;
	static const std::string Peek;

private:
	CardData(std::string newCardResourceFile, std::string newCardName, CardType newCardType, unsigned int newAttack);
	~CardData();
};
