#pragma once
#include "Weapon.h"

class Dagger : public Weapon
{
public:
	Dagger() : Weapon(1, "´Ü°Ë")
	{

	}

	virtual void rend_effect()
	{
		std::cout << "ÈÅÈÅ" << std::endl;
	}
};