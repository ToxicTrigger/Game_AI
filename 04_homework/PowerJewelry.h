#pragma once
#include "Jeweler.h"

class PowerJewelry : public Jeweler
{
public:
	inline explicit PowerJewelry(DecoratorJewelry *jew) : Jeweler(jew)
	{
		this->name = "Power Jewelry";
		this->skill_name = "Power Up";
	}
};




