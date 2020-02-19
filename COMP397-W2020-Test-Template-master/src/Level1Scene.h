#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "RollButton.h"
#include "Dice.h"
#include "Label.h"
#include "Background.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	RollButton* m_pRollButton;
	Dice* m_pDice1;
	Dice* m_pDice2;

	Label* m_pDiceLabel1;
	Label* m_pDiceLabel2;

	Background* m_pBackground;

	// private data member
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
