#pragma once
#include "cocos2d.h"

#include "Engine/Localization/Localization.h"

#include "Scenes/Hexus/Components/Banners/BannerBase.h"

using namespace cocos2d;

class RoundTieBanner : public BannerBase
{
public:
	static RoundTieBanner * create();

protected:
	void onBeforeStateChange(GameState* eventCustom) override;
	void onAnyStateChange(GameState* eventCustom) override;

private:
	RoundTieBanner();
	~RoundTieBanner();

	void initializePositions() override;

	Sprite* playerPassBanner1;
	Sprite* playerPassBanner2;
};