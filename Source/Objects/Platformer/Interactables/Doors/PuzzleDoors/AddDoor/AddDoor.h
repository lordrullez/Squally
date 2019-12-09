#pragma once

#include "Objects/Platformer/Interactables/Doors/PuzzleDoors/GreenStoneDoor/GreenStonePuzzleDoor.h"

namespace cocos2d
{
	class Sprite;
}

class CollisionObject;
class ConstantString;
class HackableData;
class LocalizedLabel;
class SmartAnimationSequenceNode;

class AddDoor : public GreenStonePuzzleDoor
{
public:
	static AddDoor* create(cocos2d::ValueMap& properties);

	static const std::string MapKeyAddDoor;

protected:
	AddDoor(cocos2d::ValueMap& properties);
	virtual ~AddDoor();

	void registerHackables() override;
	void runOperation(int puzzleIndex) override;

private:
	typedef GreenStonePuzzleDoor super;
	void showActiveHackableCrystal();
	void AddDoorTransform(int puzzleIndex);
};