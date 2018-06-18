#pragma once
#include "cocos2d.h"

#include "Engine/Rendering/Components/FloatingSprite.h"
#include "Engine/Rendering/Components/MenuSprite.h"
#include "Engine/Rendering/Components/InfiniteParallaxNode.h"
#include "Resources.h"
#include "Scenes/Menus/Tutorial/TutorialScreen.h"
#include "Utils/GameUtils.h"

using namespace cocos2d;
using namespace cocos_experimental;

class TitleScreenBackground : public Node
{
public:
	static TitleScreenBackground * create();

	void initializePositions();

private:
	TitleScreenBackground();
	~TitleScreenBackground();

	void onEnter() override;
	void initializeListeners();
	void createSlimeAnimation();

	Node* squallyNode;
	AnimationNode* squally;
	SpriterEngine::EntityInstance* squallyEntity;
	Node* slimeNode;
	Sprite* slime;
	Animation* slimeAnimation;
	Sprite* background;
	FloatingSprite* backgroundVines;
	FloatingSprite* backgroundTrees;
	FloatingSprite* midgroundTrees;
	Sprite* tree;
	Animation* eyes1Anim;
	Animation* eyes2Anim;
	Sprite* eyes1;
	Sprite* eyes2;
	FloatingSprite* foregroundVines;
	InfiniteParallaxNode* fog;
	InfiniteParallaxNode* foregroundFog;
	FloatingSprite* foregroundGrassBottom;
	FloatingSprite* foregroundGrassTop;
	Sprite* foregroundLight;

	ParticleSystem* windParticles;
	ParticleSystem* fireflyParticles;
};