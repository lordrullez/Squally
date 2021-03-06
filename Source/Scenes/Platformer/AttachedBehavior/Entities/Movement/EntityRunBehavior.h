#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class PlatformerEntity;

class EntityRunBehavior : public AttachedBehavior
{
public:
	static EntityRunBehavior* create(GameObject* owner);

	static const std::string MapKey;

protected:
	EntityRunBehavior(GameObject* owner);
	virtual ~EntityRunBehavior();

	void onLoad() override;
	void onDisable() override;

private:
	typedef AttachedBehavior super;

	PlatformerEntity* entity;

	static const float RunAcceleration;
};
