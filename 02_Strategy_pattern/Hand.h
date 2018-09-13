#pragma once
#include "Weapon.h"

class Hand
{
private:
	Weapon * weapon;

public:
	Hand()
	{

	}

	Hand(Weapon* weapon) :weapon(weapon)
	{

	}

	Weapon* get_weapon() const
	{
		if (weapon == nullptr)
		{
			return nullptr;
		}
		return this->weapon;
	}

	void unequip_weapon()
	{
		weapon = nullptr;
	}


	void equip_weapon(Weapon* weapon)
	{
		this->weapon = weapon;
	}
};