#pragma once
#include <typeinfo>
#include <iostream>

class Weapon
{
	float power;
public:
	char* name;
	Weapon()
	{
		name = (char*)(typeid(this).name());
		power = 1;
	}

	Weapon(float Power):power(Power)
	{
		name = (char*)(typeid(this).name());
	}

	Weapon(float Power, char* name) :power(Power), name(name)
	{
	}

	float get_power() { return power; }

	virtual void rend_effect() = 0;
};