#pragma once

#include "Engine/Deserializers/Objects/ObjectDeserializer.h"

class PlatformerTerrainDeserializer : public ObjectDeserializer
{
public:
	static PlatformerTerrainDeserializer* create();

	static const std::string MapKeyTypeTerrain;

private:
	typedef ObjectDeserializer super;

	PlatformerTerrainDeserializer();
	virtual ~PlatformerTerrainDeserializer();

	void deserialize(ObjectDeserializer::ObjectDeserializationRequestArgs* args);

	std::map<std::string, std::function<GameObject*(cocos2d::ValueMap)>> deserializers;
};
