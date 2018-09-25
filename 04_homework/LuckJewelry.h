#pragma once
#include "Jeweler.h"

class LuckJewelry : public Jeweler
{
public:
	inline explicit LuckJewelry(DecoratorJewelry *jew) : Jeweler(jew)
	{
		this->name = "Luck Jewelry";
		this->skill_name = "Luck Up";
	}
};

