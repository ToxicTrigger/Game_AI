#pragma once
#include "PizzaStore.h"
#include "CKPizza.h"

class Ckstore : public PizzaStore
{
public:
	Pizza * creat_pizza( Pizza * type )
	{
		return type;
	}
};