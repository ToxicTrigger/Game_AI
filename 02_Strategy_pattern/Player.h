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

		cout << this->name << " �� " << player->name << " �� "  
		<< player->hand->get_weapon()->name << " ���� ������ " << dam << " �� ���ظ� �Ծ����ϴ�!" << endl;

		cout << this->name << " ���� ü�� : " << this->Hp << endl;
		if (Hp <= 0)
		{
			cout << endl << this->name << " �� ����߽��ϴ�."  << endl;
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
			cout << this->name << " �� ��ȥ�� �����Ϸ� ������.. ���� ���� ���� �ʾҽ��ϴ�." << endl;
		}
		else
		{
			cout << this->name << " �� �տ� ���Ⱑ �����ϴ�." << endl;
		}
	}

};