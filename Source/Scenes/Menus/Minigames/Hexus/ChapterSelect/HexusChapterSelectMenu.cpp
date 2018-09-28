#include "HexusChapterSelectMenu.h"

HexusChapterSelectMenu * HexusChapterSelectMenu::create()
{
	HexusChapterSelectMenu* instance = new HexusChapterSelectMenu();

	instance->autorelease();

	return instance;
}

HexusChapterSelectMenu::HexusChapterSelectMenu()
{
	this->chapters = new std::vector<HexusChapterPreview*>();
	this->background = Sprite::create(Resources::Menus_MinigamesMenu_Hexus_WoodBackground);
	this->hexusChapterPreviewTraining = HexusChapterPreviewTraining::create();
	this->hexusChapterPreviewJungle = HexusChapterPreviewJungle::create();
	this->hexusChapterPreviewRuins = HexusChapterPreviewRuins::create();
	this->hexusChapterPreviewForest = HexusChapterPreviewForest::create();
	this->hexusChapterPreviewCaverns = HexusChapterPreviewCaverns::create();
	this->hexusChapterPreviewCastle = HexusChapterPreviewCastle::create();
	this->hexusChapterPreviewIceCaps = HexusChapterPreviewIceCaps::create();
	this->hexusChapterPreviewVolcano = HexusChapterPreviewVolcano::create();
	this->hexusChapterPreviewObelisk = HexusChapterPreviewObelisk::create();
	this->hexusChapterPreviewMech = HexusChapterPreviewMech::create();
	this->chapterSelectLabel = Label::create("Chapter Select", Localization::getMainFont(), Localization::getFontSizeH1(Localization::getMainFont()));

	Label* manageDeckLabel = Label::create("Manage Cards", Localization::getMainFont(), Localization::getFontSizeP(Localization::getMainFont()));
	Label* manageDeckLabelHover = Label::create("Manage Cards", Localization::getMainFont(), Localization::getFontSizeP(Localization::getMainFont()));
	Label* manageDeckLabelClick = Label::create("Manage Cards", Localization::getMainFont(), Localization::getFontSizeP(Localization::getMainFont()));
	
	manageDeckLabel->enableOutline(Color4B::BLACK, 2);
	manageDeckLabelHover->enableOutline(Color4B::BLACK, 2);
	manageDeckLabelClick->enableOutline(Color4B::BLACK, 2);

	this->hexusChapterPreviewRuins->disableInteraction();
	this->hexusChapterPreviewForest->disableInteraction();
	this->hexusChapterPreviewCaverns->disableInteraction();
	this->hexusChapterPreviewCastle->disableInteraction();
	this->hexusChapterPreviewIceCaps->disableInteraction();
	this->hexusChapterPreviewVolcano->disableInteraction();
	this->hexusChapterPreviewObelisk->disableInteraction();
	this->hexusChapterPreviewMech->disableInteraction();

	this->deckManagementButton = TextMenuSprite::create(
		manageDeckLabel,
		manageDeckLabelHover,
		manageDeckLabelClick,
		Resources::Menus_Buttons_GenericButton,
		Resources::Menus_Buttons_GenericButtonHover,
		Resources::Menus_Buttons_GenericButtonClick
	);

	this->chapterSelectLabel->enableOutline(Color4B::BLACK, 2);
	this->setCascadeOpacityEnabled(true);

	auto callback = CC_CALLBACK_1(HexusChapterSelectMenu::onMouseOver, this);
	this->chapters->push_back(this->hexusChapterPreviewTraining);
	this->chapters->push_back(this->hexusChapterPreviewJungle);
	this->chapters->push_back(this->hexusChapterPreviewRuins);
	this->chapters->push_back(this->hexusChapterPreviewForest);
	this->chapters->push_back(this->hexusChapterPreviewCaverns);
	this->chapters->push_back(this->hexusChapterPreviewCastle);
	this->chapters->push_back(this->hexusChapterPreviewIceCaps);
	this->chapters->push_back(this->hexusChapterPreviewVolcano);
	this->chapters->push_back(this->hexusChapterPreviewObelisk);
	this->chapters->push_back(this->hexusChapterPreviewMech);

	this->addChild(this->background);

	for (std::vector<HexusChapterPreview*>::iterator it = this->chapters->begin(); it != this->chapters->end(); ++it)
	{
		this->addChild(*it);
	}

	this->addChild(this->deckManagementButton);
	this->addChild(this->chapterSelectLabel);
	this->addChild(Mouse::create());
}

HexusChapterSelectMenu::~HexusChapterSelectMenu()
{
}

void HexusChapterSelectMenu::onEnter()
{
	FadeScene::onEnter();

	float delay = 0.25f;
	float duration = 0.35f;
}

void HexusChapterSelectMenu::initializeListeners()
{
	FadeScene::initializeListeners();

	EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();

	keyboardListener->onKeyPressed = CC_CALLBACK_2(HexusChapterSelectMenu::onKeyPressed, this);
	this->hexusChapterPreviewTraining->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Training); } );
	this->hexusChapterPreviewJungle->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Jungle); } );
	this->hexusChapterPreviewRuins->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Ruins); } );
	this->hexusChapterPreviewForest->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Forest); } );
	this->hexusChapterPreviewCaverns->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Caverns); } );
	this->hexusChapterPreviewCastle->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Castle); } );
	this->hexusChapterPreviewIceCaps->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_IceCaps); } );
	this->hexusChapterPreviewVolcano->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Volcano); } );
	this->hexusChapterPreviewObelisk->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Obelisk); } );
	this->hexusChapterPreviewMech->setClickCallback([]() { NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Chapter_Mech); } );
	this->deckManagementButton->setClickCallback(CC_CALLBACK_1(HexusChapterSelectMenu::onDeckManagementClick, this));

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void HexusChapterSelectMenu::initializePositions()
{
	FadeScene::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	int index = 0;

	for (std::vector<HexusChapterPreview*>::iterator it = this->chapters->begin(); it != this->chapters->end(); ++it)
	{
		int x = index % 5;
		int y = index / 5;

		(*it)->setPosition(Vec2(visibleSize.width / 2.0f - 720.0f + 360.0f * x, visibleSize.height / 2.0f + 240.0f - 480.0f * y - 48.0f));

		index++;
	}

	this->deckManagementButton->setPosition(Vec2(visibleSize.width / 2.0f + 756.0f, visibleSize.height - 64.0f));
	this->chapterSelectLabel->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height - 64.0f));
}

void HexusChapterSelectMenu::onMouseOver(HexusChapterPreview* HexusChapterPreview)
{
}

void HexusChapterSelectMenu::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_ESCAPE:
			event->stopPropagation();
			NavigationEvents::navigateBack();
			break;
		default:
			break;
	}
}

void HexusChapterSelectMenu::onCloseClick(MenuSprite* menuSprite)
{
	NavigationEvents::navigateBack();
}

void HexusChapterSelectMenu::onDeckManagementClick(MenuSprite* menuSprite)
{
	NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Deck_Management);
}