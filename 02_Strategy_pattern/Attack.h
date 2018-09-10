#pragma once
#include "Body.h"

class Attack
{
public: 
	float damage;
	
	Attack(float Damage) : damage(Damage) {} 
	virtual void attack_eff() = 0;
};