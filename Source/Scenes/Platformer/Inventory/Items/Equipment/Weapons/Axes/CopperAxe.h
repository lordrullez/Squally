#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Axes/Axe.h"

class CopperAxe : public Axe
{
public:
	static CopperAxe* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;
	cocos2d::Size getWeaponCollisionSize() override;
	cocos2d::Vec2 getWeaponOffset() override;

	static const std::string SaveKey;

protected:
	CopperAxe();
	virtual ~CopperAxe();

private:
	typedef Axe super;
};
