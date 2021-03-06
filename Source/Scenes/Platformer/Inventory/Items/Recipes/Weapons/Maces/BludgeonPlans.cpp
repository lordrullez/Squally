#include "BludgeonPlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string BludgeonPlans::SaveKey = "bludgeon-plans";

BludgeonPlans* BludgeonPlans::create()
{
	BludgeonPlans* instance = new BludgeonPlans();

	instance->autorelease();

	return instance;
}

BludgeonPlans::BludgeonPlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

BludgeonPlans::~BludgeonPlans()
{
}

Item* BludgeonPlans::craft()
{
	return Bludgeon::create();
}

std::vector<std::tuple<Item*, int>> BludgeonPlans::getReagentsInternal()
{
	return
	{
		{ Copper::create(), 3 },
		{ LightWood::create(), 10 },
		{ Iron::create(), 2 },
	};
}

Item* BludgeonPlans::clone()
{
	return BludgeonPlans::create();
}

std::string BludgeonPlans::getItemName()
{
	return BludgeonPlans::SaveKey;
}

LocalizedString* BludgeonPlans::getString()
{
	return Strings::Items_Equipment_Weapons_Maces_Bludgeon::create();
}

std::string BludgeonPlans::getIconResource()
{
	return ItemResources::Misc_SCROLL_1;
}

std::string BludgeonPlans::getCraftedItemIconResource()
{
	return ItemResources::Equipment_Weapons_Special_Bludgeon;
}

std::string BludgeonPlans::getSerializationKey()
{
	return BludgeonPlans::SaveKey;
}
