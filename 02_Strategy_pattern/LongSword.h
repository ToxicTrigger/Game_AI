#pragma once
#include "Weapon.h"


class LongSword : public Weapon
{
public:
	LongSword() : Weapon(2, "�ռҵ�")
	{

	}
	virtual void rend_effect()
	{
		std::cout << "����" << std::endl;
	}
};