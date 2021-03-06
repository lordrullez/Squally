#pragma once

#include "Engine/SmartNode.h"

namespace cocos2d
{
	class Sprite;
}

class Projectile;

class ProjectilePool : public SmartNode
{
public:
	static ProjectilePool* create(std::function<Projectile*()> projectileFactory);

	Projectile* getNextProjectile();

protected:
	ProjectilePool(std::function<Projectile*()> projectileFactory);
	virtual ~ProjectilePool();

private:
	typedef SmartNode super;

	std::vector<Projectile*> projectiles;
	std::function<Projectile*()> projectileFactory;

	int dartIndex;

	static const int PoolCapacity;
};
