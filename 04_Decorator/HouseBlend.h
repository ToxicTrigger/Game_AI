#pragma once
#include "Beverage.h"
class HouseBlend :
	public Beverage
{
public:
	inline HouseBlend() : Beverage( "House Blend Coffee" )
	{
	}

	float cost()
	{
		return 1000.0f;
	}
};
