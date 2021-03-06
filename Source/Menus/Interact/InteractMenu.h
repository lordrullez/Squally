#pragma once
#include <functional>

#include "cocos/base/CCEventKeyboard.h"
#include "cocos/base/ccTypes.h"

#include "Engine/SmartNode.h"

namespace cocos2d
{
	class LayerColor;
	class Sprite;
}

class LocalizedLabel;
class LocalizedString;

class InteractMenu : public SmartNode
{
public:
	static InteractMenu* create(LocalizedString* displayString);

	void show();
	void hide();

protected:
	InteractMenu(LocalizedString* displayString);
	virtual ~InteractMenu();

private:
	typedef SmartNode super;
	void onEnter() override;
	void onExit() override;
	void initializePositions() override;
	void initializeListeners() override;

	bool hasRelocated;

	cocos2d::Node* uiElements;
	cocos2d::LayerColor* backdrop;
	LocalizedString* displayString;
	LocalizedLabel* displayLabel;
};
