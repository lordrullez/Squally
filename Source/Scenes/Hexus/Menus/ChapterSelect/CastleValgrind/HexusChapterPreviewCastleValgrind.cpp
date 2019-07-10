#include "HexusChapterPreviewCastleValgrind.h"

#include "cocos/2d/CCSprite.h"

#include "Engine/Localization/LocalizedLabel.h"

#include "Resources/HexusResources.h"

#include "Strings/Menus/Maps/CastleValgrind.h"

using namespace cocos2d;

const std::string HexusChapterPreviewCastleValgrind::SaveKeyChapterName = "HEXUS_CHAPTER_CASTLE_VALGRIND";

HexusChapterPreviewCastleValgrind* HexusChapterPreviewCastleValgrind::create()
{
	HexusChapterPreviewCastleValgrind* instance = new HexusChapterPreviewCastleValgrind();

	instance->autorelease();

	return instance;
}

HexusChapterPreviewCastleValgrind::HexusChapterPreviewCastleValgrind() : HexusChapterPreview(HexusChapterPreviewCastleValgrind::SaveKeyChapterName, Strings::Menus_Maps_CastleValgrind::create())
{
	this->contentNode->addChild(Sprite::create(HexusResources::Menus_HexusFrameCastleValgrind));
}

HexusChapterPreviewCastleValgrind::~HexusChapterPreviewCastleValgrind()
{
}

void HexusChapterPreviewCastleValgrind::initializePositions()
{
	super::initializePositions();
}
