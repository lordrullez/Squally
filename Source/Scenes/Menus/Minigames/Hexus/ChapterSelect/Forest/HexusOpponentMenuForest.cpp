#include "HexusOpponentMenuForest.h"

const std::string HexusOpponentMenuForest::StringKeyProgressSave = "SAVE_KEY_HEXUS_FOREST_PROGRESS";

HexusOpponentMenuForest * HexusOpponentMenuForest::create()
{
	HexusOpponentMenuForest* instance = new HexusOpponentMenuForest();

	instance->autorelease();

	return instance;
}

HexusOpponentMenuForest::HexusOpponentMenuForest() : HexusOpponentMenuBase(HexusOpponentMenuForest::StringKeyProgressSave)
{
	auto callback = CC_CALLBACK_1(HexusOpponentMenuForest::onGameEndCallback, this);

	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));

	for (std::vector<HexusOpponentPreview*>::iterator it = this->opponents.begin(); it != this->opponents.end(); ++it)
	{
		this->scrollPane->addChild(*it);
	}
}

HexusOpponentMenuForest::~HexusOpponentMenuForest()
{
}
