#include "EnemyBehaviorGroup.h"

#include "Engine/Maps/GameObject.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Enemies/Collision/EnemyCollisionBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Enemies/Combat/EnemyCombatEngageBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Enemies/Stats/EnemyHealthBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/EntityBehaviorGroup.h"

using namespace cocos2d;

const std::string EnemyBehaviorGroup::MapKey = "enemy";

EnemyBehaviorGroup* EnemyBehaviorGroup::create(GameObject* owner)
{
	EnemyBehaviorGroup* instance = new EnemyBehaviorGroup(owner);

	instance->autorelease();

	return instance;
}

EnemyBehaviorGroup::EnemyBehaviorGroup(GameObject* owner) : super(owner, {
	EnemyCollisionBehavior::create(owner),
	EntityBehaviorGroup::create(owner),
	EnemyHealthBehavior::create(owner),
	EnemyCombatEngageBehavior::create(owner),
	})
{
}

EnemyBehaviorGroup::~EnemyBehaviorGroup()
{
}

void EnemyBehaviorGroup::onLoad()
{
}
