#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Bows/BowRecipe.h"

class HuntersBowPlans : public BowRecipe
{
public:
	static HuntersBowPlans* create();

	Item* craft() override;
	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getCraftedItemIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKey;

protected:
	HuntersBowPlans();
	virtual ~HuntersBowPlans();
	
	std::vector<std::tuple<Item*, int>> getReagentsInternal() override;

private:
	typedef BowRecipe super;
};
