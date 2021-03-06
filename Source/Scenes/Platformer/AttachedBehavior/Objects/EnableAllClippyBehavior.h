#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class HackableObject;

class EnableAllClippyBehavior : public AttachedBehavior
{
public:
	static EnableAllClippyBehavior* create(GameObject* owner);

	static const std::string MapKey;

protected:
	EnableAllClippyBehavior(GameObject* owner);
	virtual ~EnableAllClippyBehavior();

	void onLoad() override;
	void onDisable() override;

private:
	typedef AttachedBehavior super;

	HackableObject* hackableObject;
};
