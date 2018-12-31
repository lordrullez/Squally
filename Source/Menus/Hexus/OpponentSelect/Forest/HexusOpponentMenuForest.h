#pragma once

#include "Menus/Hexus/OpponentSelect/HexusOpponentMenuBase.h"

class HexusOpponentMenuForest : public HexusOpponentMenuBase
{
public:
	static void registerGlobalScene();

protected:
	HexusOpponentMenuForest();
	~HexusOpponentMenuForest();

private:
	typedef HexusOpponentMenuBase super;
	static HexusOpponentMenuForest* instance;
};
