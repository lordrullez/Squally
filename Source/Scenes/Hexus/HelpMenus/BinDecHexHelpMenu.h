#pragma once

#include "Engine/SmartNode.h"

namespace cocos2d
{
	class Node;
}

class AutoCard;
class Card;
class LocalizedLabel;

class BinDecHexHelpMenu : public SmartNode
{
public:
	static BinDecHexHelpMenu* create();

	void open(Card* card);

protected:
	BinDecHexHelpMenu();
	virtual ~BinDecHexHelpMenu();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;

private:
	typedef SmartNode super;

	LocalizedLabel* description;
	AutoCard* binCard;
	AutoCard* decCard;
	AutoCard* hexCard;
	LocalizedLabel* equalsLabelLeft;
	LocalizedLabel* equalsLabelRight;
	LocalizedLabel* binHeader;
	LocalizedLabel* decHeader;
	LocalizedLabel* hexHeader;
};
