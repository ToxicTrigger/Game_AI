#pragma once
#include "Weapon.h"
#include "Hand.h"
#include <iostream>

using namespace std;

class Player
{
public:
	float Hp;
	Hand* hand;
	char* name;

	Player()
	{
		hand = new Hand();
		Hp = 0;
		name = " ";
	}

	Player(char* name, float hp, Weapon* weapon) : name(name), Hp(hp)
	{
		hand = new Hand(weapon);
	}
	
	void damaged(Player* player)
	{
		float dam = player->hand->get_weapon()->get_power();
		Hp -= dam;

		cout << this->name << " 가 " << player->name << " 의 "  
		<< player->hand->get_weapon()->name << " 공격 때문에 " << dam << " 의 피해를 입었습니다!" << endl;

		cout << this->name << " 남은 체력 : " << this->Hp << endl;
		if (Hp <= 0)
		{
			cout << endl << this->name << " 은 사망했습니다."  << endl;
		}
	}

	void attack(Player* player)
	{
		if (this->hand->get_weapon() != nullptr & this->Hp > 0)
		{
			this->hand->get_weapon()->rend_effect();
			player->damaged(this);
		}
		else if (this->Hp <= 0)
		{
			cout << this->name << " 의 영혼은 공격하려 했지만.. 몸이 말을 듣지 않았습니다." << endl;
		}
		else
		{
			cout << this->name << " 의 손에 무기가 없습니다." << endl;
		}
	}

};