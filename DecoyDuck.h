#pragma once
#include "Duck.h"
#include "MuteQuack.h"
#include "FlyWing.h"

class DecoyDuck : Duck
{
public:
	void Duck::display()
	{
		this->set_quack_behavior(new MuteQuack());
		this->set_fly_behavior(new FlyWing());
		this->do_fly();
		this->do_Quack();
	}
};