#pragma once

#include "Engine/Deserializers/Objects/ObjectDeserializer.h"

class GameObject;

class PlatformerEntityDeserializer : public ObjectDeserializer
{
public:
	static PlatformerEntityDeserializer* create();

	static const std::string MapKeyTypeEntity;

private:
	typedef ObjectDeserializer super;

	PlatformerEntityDeserializer();
	virtual ~PlatformerEntityDeserializer();
};
