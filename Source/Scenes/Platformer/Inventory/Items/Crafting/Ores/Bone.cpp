#include "Bone.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string Bone::SaveKey = "bone";

Bone* Bone::create()
{
	Bone* instance = new Bone();

	instance->autorelease();

	return instance;
}

Bone::Bone() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 57 }}), ItemMeta(20000))
{
}

Bone::~Bone()
{
}

Item* Bone::clone()
{
	return Bone::create();
}

std::string Bone::getItemName()
{
	return Bone::SaveKey;
}

LocalizedString* Bone::getString()
{
	return Strings::Items_Crafting_Ore_Bone::create();
}

std::string Bone::getIconResource()
{
	return ItemResources::Crafting_Smithing_Bone;
}

std::string Bone::getSerializationKey()
{
	return Bone::SaveKey;
}
