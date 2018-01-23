#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Shaders/PostProcess.h"
#include "GUI/Components/MenuSprite.h"
#include "GUI/Components/MouseOverPanel.h"
#include "Objects/Hackables/HackableObject.h"
#include "Utils/HackUtils.h"

using namespace cocos2d;

class CodeMenu : public Node
{
public:
	static CodeMenu * create();

	void open(HackableObject* hackableObject);

private:
	CodeMenu();
	~CodeMenu();

	void initializePositions();
	void initializeListeners();
	void onClose(MenuSprite* menuSprite);

	Sprite* codeMenuBackground;
	MenuSprite* closeButton;
	Node* rows;
};

