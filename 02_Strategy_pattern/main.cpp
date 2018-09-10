#pragma once
#include "Player.h"

void main()
{
	Player* p = new Player("ss", 10, 2);
	Player* p2 = new Player("aa", 10, 2);
	p->damaged(p2->get_attack());
}