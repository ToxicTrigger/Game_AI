#pragma once
#include "Fly.h"
#include "Quack.h"

class Duck
{
private:
	Fly* fly;
	Quack* q;

public:
	void do_fly()
	{
		fly->fly();
	}

	void do_Quack()
	{
		q->quack();
	}

	void set_fly_behavior(Fly* fly)
	{
		this->fly = fly;
	}

	void set_quack_behavior(Quack* quack)
	{
		this->q = quack;
	}
	virtual void display() = 0;
};