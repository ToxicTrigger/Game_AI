#pragma once
#include "Attack.h"
#include "Body.h"

class Player : public Body, Attack
{
public:
	Player(char* name, float Hp, float Power) : Body(name, Hp), Attack(Power)
	{}

	Attack* get_attack()
	{
		return this;
	}

	virtual void rend_effect(Attack* attacker) const
	{
		std::cout << "맞았다!" << std::endl;
	}

	virtual void attack_eff()
	{
		std::cout << "강공격!" << std::endl;
	}
};