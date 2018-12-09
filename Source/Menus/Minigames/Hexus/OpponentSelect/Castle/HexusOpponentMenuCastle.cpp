#include "HexusOpponentMenuCastle.h"

HexusOpponentMenuCastle* HexusOpponentMenuCastle::instance = nullptr;

void HexusOpponentMenuCastle::registerGlobalScene()
{
	if (HexusOpponentMenuCastle::instance == nullptr)
	{
		HexusOpponentMenuCastle::instance = new HexusOpponentMenuCastle();

		HexusOpponentMenuCastle::instance->autorelease();
		HexusOpponentMenuCastle::instance->initializeListeners();
	}

	GlobalDirector::registerGlobalScene(HexusOpponentMenuCastle::instance);
}

HexusOpponentMenuCastle::HexusOpponentMenuCastle() : HexusOpponentMenuBase(NavigationEvents::NavigateHexusOpponentSelectArgs::Chapter::Castle, HexusChapterPreviewCastle::stringKeyChapterName)
{
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentGarin::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentWraith::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentLeroy::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentZombie::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentThurstan::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentExecutioner::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentRogas::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentKingRedsongSlime::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentJack::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentTyracius::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentReaper::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentErlic::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentVampireLord::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentMabel::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentVampiress::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentMerlin::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentZombieErlic::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentPrincessOpal::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentScarecrow::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentRaven::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentShade::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentKingRedsong::getInstance()));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentAgnes::getInstance()));

	for (std::vector<HexusOpponentPreview*>::iterator it = this->opponents.begin(); it != this->opponents.end(); ++it)
	{
		this->scrollPane->addChild(*it);
	}
}

HexusOpponentMenuCastle::~HexusOpponentMenuCastle()
{
}
