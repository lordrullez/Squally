#pragma once
#include "cocos2d.h"
#include "Resources.h"

#include "Engine/SmartNode.h"
#include "Engine/Localization/Localization.h"
#include "Engine/UI/Controls/MenuSprite.h"
#include "Events/HexusEvents.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusChapterPreview : public SmartNode
{
public:
	static HexusChapterPreview * create();

	void setClickCallback(std::function<void()> callback);
	void disableInteraction();
	void enableInteraction();

protected:
	HexusChapterPreview();
	~HexusChapterPreview();

	void initializePositions() override;
	void initializeListeners() override;
	void onOpponentClick(MenuSprite* HexusChapterPreview);
	
	ClippingNode* frameClip;
	MenuSprite* frame;
	Label* text;
	std::function<void()> callback;
};