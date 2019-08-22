#pragma once

#include "Entities/Platformer/PlatformerFriendly.h"

namespace cocos2d
{
	typedef std::map<std::string, Value> ValueMap;
}

class Squally : public PlatformerFriendly
{
public:
	static Squally* create();
	static Squally* deserialize(cocos2d::ValueMap& properties);

	float getFloatHeight() override;
	cocos2d::Vec2 getDialogueOffset() override;

	static const std::string MapKeySqually;

protected:
	void performSwimAnimation() override;

	cocos2d::Vec2 getButtonOffset() override;

private:
	typedef PlatformerFriendly super;
	friend class SquallyBehaviorGroup;
	friend class SquallyCollisionBehavior;
	friend class SquallyEquipmentVisualBehavior;
	friend class SquallyMovementBehavior;
	friend class SquallyOutOfCombatAttackBehavior;
	
	Squally(cocos2d::ValueMap& properties);
	~Squally();
	
	void onEnter() override;
	void onEnterTransitionDidFinish() override;
	void initializePositions() override;
	void initializeListeners() override;
	void update(float dt) override;
	void onHackerModeEnable(int eq) override;
	void runEyeBlinkLoop();
	void spawnHelper();

	static const float SquallyScale;
};
