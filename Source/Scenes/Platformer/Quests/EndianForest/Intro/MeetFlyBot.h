#pragma once

#include "Engine/Quests/QuestTask.h"

class FlyBot;

class MeetFlyBot : public QuestTask
{
public:
	static MeetFlyBot* create(GameObject* owner);

	static const std::string MapKeyQuest;

protected:
	MeetFlyBot(GameObject* owner);
	~MeetFlyBot();

	void initializeListeners() override;
	void onLoad(bool isQuestActive, bool isQuestActiveAsSkippable, bool isQuestComplete) override;
	void onActivate() override;

private:
	typedef QuestTask super;

	void runCinematicSequence();

	bool hasRunEvent;
	FlyBot* flyBot;
};
