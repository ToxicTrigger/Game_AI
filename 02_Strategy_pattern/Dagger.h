#pragma once
#include "Weapon.h"

class Dagger : public Weapon
{
public:
	Dagger() : Weapon(1, "�ܰ�")
	{

	}

	virtual void rend_effect()
	{
		std::cout << "����" << std::endl;
	}
};