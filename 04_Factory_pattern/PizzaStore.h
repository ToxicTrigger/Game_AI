#pragma once
#include "Pizza.h"

class PizzaStore
{
protected:
	//Ư���ϰ� ������ ���� ���ٸ� �׳� return type !!
	virtual Pizza *creat_pizza( Pizza *type ) = 0;

public:
	Pizza * orderPizza( Pizza *type ) noexcept
	{
		Pizza* pizza = creat_pizza( type );
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

};