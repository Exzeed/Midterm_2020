#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pRollButton->draw();
	m_pDice1->draw();
	m_pDice2->draw();

	m_pDiceLabel1->draw();
	m_pDiceLabel2->draw();
	//m_pBackground->draw();
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	if(m_pRollButton->ButtonClick())
	{
		m_pDiceLabel1->setText(std::to_string(m_pRollButton->diceV1));
		m_pDiceLabel2->setText(std::to_string(m_pRollButton->diceV2));
	}
}

void Level1Scene::clean()
{
	removeAllChildren();
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);
				//m_pDiceLabel1->setText("2");
				//std::string d1= RollButton::diceValue[0];
				//m_pDiceLabel1->setText(RollButton::diceValue[0]);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	SDL_Color black = { 0, 0, 0, 255 };
	m_pDiceLabel1 = new Label("0", "Consolas", 36, black, 
		glm::vec2(Config::SCREEN_WIDTH * 0.3f, Config::SCREEN_HEIGHT * 0.65f));
	m_pDiceLabel1->setParent(this);
	addChild(m_pDiceLabel1);

	m_pDiceLabel2 = new Label("0", "Consolas", 36, black, 
		glm::vec2(Config::SCREEN_WIDTH * 0.7f, Config::SCREEN_HEIGHT * 0.65f));
	m_pDiceLabel2->setParent(this);
	addChild(m_pDiceLabel2);
	
	m_pRollButton = new RollButton();
	m_pRollButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.8f));
	addChild(m_pRollButton);

	m_pDice1= new Dice();
	m_pDice1->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.3, Config::SCREEN_HEIGHT * 0.4f));
	addChild(m_pDice1);

	m_pDice2= new Dice();
	m_pDice2->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.7, Config::SCREEN_HEIGHT * 0.4f));
	addChild(m_pDice2);
	
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}
