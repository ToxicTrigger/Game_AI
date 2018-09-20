#pragma once
#include "Pizza.h"

class PizzaStore
{
protected:
	//특별하게 구현할 것이 없다면 그냥 return type !!
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