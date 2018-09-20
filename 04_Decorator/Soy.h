#pragma once

#include "CondimentDecorator.h"

class Soy : public CondimentDecorator
{
public:
	Soy( Beverage *bev ) : CondimentDecorator( bev )
	{
	}

	string getDescription()
	{
		return this->beverage->getDescription() + " + Soy";
	}

	float cost()
	{
		return this->beverage->cost() + 250;
	}
};