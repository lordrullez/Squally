#include "LanguageTab.h"

#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Config/ConfigManager.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/Localization/LocalizedString.h"
#include "Engine/UI/Controls/CRadioButton.h"
#include "Engine/UI/Controls/TextMenuSprite.h"

#include "Resources/UIResources.h"

#include "Strings/Generics/NativeLanguage.h"
#include "Engine/Localization/Localization.h"

using namespace cocos2d;

LanguageTab* LanguageTab::create()
{
	LanguageTab* instance = new LanguageTab();

	instance->autorelease();

	return instance;
}

LanguageTab::LanguageTab()
{
	this->languageButtons = std::vector<TextMenuSprite*>();

	for (int index = (int)LanguageType::FIRST_LANGUAGE; index < (int)LanguageType::LAST_LANGUAGE; index++)
	{
		LanguageType language = (LanguageType)index;
		LocalizedString* nextString = Strings::Generics_NativeLanguage::create();

		nextString->setOverrideLanguage(language);

		TextMenuSprite* button = this->constructLanguageButton(nextString);

		button->setClickCallback([=](MenuSprite*, MouseEvents::MouseEventArgs*) { Localization::setLanguage(language); });

		this->languageButtons.push_back(button);
	}

	for (auto it = this->languageButtons.begin(); it != this->languageButtons.end(); it++)
	{
		this->addChild(*it);
	}
}

LanguageTab::~LanguageTab()
{
}

void LanguageTab::onEnter()
{
	super::onEnter();

	float delay = 0.1f;
	float duration = 0.25f;
}

void LanguageTab::initializeListeners()
{
	super::initializeListeners();
}

void LanguageTab::initializePositions()
{
	super::initializePositions();

	const Vec2 offset = Vec2(-240.0f, 160.0f);
	const Vec2 spacing = Vec2(224.0f, 64.0f);
	int index = 0;

	for (auto it = this->languageButtons.begin(); it != this->languageButtons.end(); it++)
	{
		float x = (float)(index / 10) * spacing.x + offset.x;
		float y = -(float)(index % 10) * spacing.y + offset.y;

		(*it)->setPosition(Vec2(x, y));

		index++;
	}
}

TextMenuSprite* LanguageTab::constructLanguageButton(LocalizedString* string)
{
	LocalizedLabel* label = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::P, string);
	LocalizedLabel* labelHover = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::P, string);

	TextMenuSprite* button = TextMenuSprite::create(label, labelHover, UIResources::Menus_OptionsMenu_DarkButton, UIResources::Menus_OptionsMenu_DarkButtonSelected);

	return button;
}