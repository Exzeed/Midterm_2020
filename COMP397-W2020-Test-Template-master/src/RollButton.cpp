#include "RollButton.h"
#include "Game.h"
#include "Util.h"

RollButton::RollButton()
	// call super constructor
	:Button(
		"../Assets/textures/rollButton.png",
		"rollButton",
		ROLL_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "sound", SOUND_SFX);
}

RollButton::~RollButton()
{
}

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("sound", 0);
			std::cout<<"Roll"<<std::endl;
			RollButton::Rolls();
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}

std::vector<std::string> RollButton::Rolls()
{
	diceValue= {" ", " "};
	int outcome[]= {0,0,0};

	for(int roll= 0; roll<2; roll++)
	{
		outcome[roll]= Util::RandomRange(1,6);
		std::cout<<"Dice "<<roll+1<< ": "<<outcome[roll] << std::endl;

		switch(outcome[roll])
		{
		case 1:
			diceValue[roll]= "1";
			break;
		case 2:
			diceValue[roll]= "2";
			break;
		case 3:
			diceValue[roll]= "3";
			break;
		case 4:
			diceValue[roll]= "4";
			break;
		case 5:
			diceValue[roll]= "5";
			break;
		case 6:
			diceValue[roll]= "6";
			break;
		}
	}
	std::cout<<"Values: "<<diceValue[0]<< " "<<diceValue[1]<<std::endl;
	return diceValue;
}