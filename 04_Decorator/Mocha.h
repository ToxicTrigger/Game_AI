#pragma once
#include "CondimentDecorator.h"

class Mocha : public CondimentDecorator
{
public:
	Mocha( Beverage *beverage ) : CondimentDecorator( beverage )
	{
	}

	string getDescription()
	{
		return this->beverage->getDescription() + " + Mocha";
	}

	float cost()
	{
		return this->beverage->cost() + 500;
	}

};