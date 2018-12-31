#pragma once

#include "Scenes/Maps/MapBase.h"

class IsometricMap : public MapBase
{
public:
	static IsometricMap* create();

protected:
	IsometricMap();
	~IsometricMap();

private:
	typedef MapBase super;
	void initializePositions() override;
	void initializeListeners() override;
	void onEnter() override;
};
