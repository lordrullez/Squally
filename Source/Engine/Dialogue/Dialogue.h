#pragma once
#include "cocos2d.h"

#include "Engine/Dialogue/DialogueTree.h"
#include "Engine/Localization/Localization.h"
#include "Engine/Rendering/Components/MenuLabel.h"
#include "Events/DialogEvents.h"
#include "Resources.h"

using namespace cocos2d;

class Dialogue : public Node
{
public:
	static Dialogue * create(std::string filePath, std::string fontResource, Size size);

	void setDialogueSpeed(float speed);
	bool showNextDialogue();
	void setDialogueShownCallback(std::function<void()> callback);

	Label* label;

private:
	Dialogue(DialogueTree* root, std::string fontResource, Size size);
	~Dialogue();

	void onEnter() override;
	void updateLabels();
	void runTypeWriterEffect();

	float dialogueSpeed;
	DialogueTree* dialogueRoot;
	DialogueTree* currentDialogue;
	std::function<void()> dialogueShownCallback;

	static const std::string ScheduleKeyTypeWriterEffect;
	static const float DefaultTypeSpeed;
};