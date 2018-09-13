#pragma once
#include "Player.h"
#include "LongSword.h"
#include "Dagger.h"

using namespace std;

void main()
{
	Player* p1 = new Player("용사", 10, new LongSword());
	Player* p2 = new Player("고블린", 2, new Dagger());
	
	p2->attack(p1);

	p2->hand->unequip_weapon();
	p2->attack(p1);

	p2->hand->equip_weapon(new LongSword());
	p1->attack(p2);
	p2->attack(p1);

	getchar();
}