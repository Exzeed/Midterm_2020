#include "Dice.h"
#include "Game.h"

Dice::Dice()
{
	TheTextureManager::Instance()->load("../Assets/textures/blank.png",
		"dice", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("dice");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	setIsColliding(false);
	setType(GameObjectType::DICE);
}

Dice::~Dice()
{
}

void Dice::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("dice", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Dice::update()
{
	//std::string 
	/*TheTextureManager::Instance()->load("../Assets/textures/question_mark.png",
		"reel", TheGame::Instance()->getRenderer());*/
	
}

void Dice::clean()
{
}
