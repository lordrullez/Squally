#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/Npcs/NpcBase.h"
#include "Resources.h"

using namespace cocos2d;

class Thor : public NpcBase
{
public:
	static Thor * deserialize(ValueMap* initProperties);

	static const std::string MapKeyNpcThor;

private:
	Thor(ValueMap* initProperties);
	~Thor();
};