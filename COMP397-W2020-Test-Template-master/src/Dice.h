#pragma once
#ifndef __DICE__
#define __DICE__
#include "DisplayObject.h"

class Dice : public DisplayObject
{
public:
	Dice();
	~Dice();
	
	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__DICE__) */