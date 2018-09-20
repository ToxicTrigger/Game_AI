#pragma once
#include "Beverage.h"

class CondimentDecorator : public Beverage
{
protected:
	Beverage * beverage;
public:
	explicit inline CondimentDecorator( Beverage *beverage ) : Beverage( beverage->getDescription() )
	{
		this->beverage = beverage;
	}

	virtual string getDescription() = 0;
};