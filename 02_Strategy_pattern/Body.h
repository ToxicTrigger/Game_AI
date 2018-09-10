#pragma once
#include "Attack.h"
#include <iostream>

class Body
{
public:
	float char_Hp;
	char* char_name;
	bool still_alive;

	Body(char* Name, float Max_Hp) : char_Hp(Max_Hp), char_name(Name) {}

	void damaged(Attack* attacker)
	{
		if (this->char_Hp - attacker->damage > 0)
		{
			this->char_Hp -= attacker->damage;
			this->still_alive = true;
			attacker->attack_eff();
			rend_effect(attacker);
		}
		else 
		{
			this->char_Hp -= attacker->damage;
			this->still_alive = false;
			attacker->attack_eff();
			std::cout << this->char_name << "\t : ���" << std::endl;
		}
	}
	
	//���� ���� �� ��� �޽���
	//immutable
	virtual void rend_effect(Attack* attacker) const = 0;
};