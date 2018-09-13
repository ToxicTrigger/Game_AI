#pragma once
#include "Weapon.h"


class LongSword : public Weapon
{
public:
	LongSword() : Weapon(2, "·Õ¼Òµå")
	{

	}
	virtual void rend_effect()
	{
		std::cout << "½¹½¹" << std::endl;
	}
};