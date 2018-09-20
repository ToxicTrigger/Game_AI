#pragma once
#include "Pizza.h"

class MyPizza : public Pizza
{
public:
	MyPizza() : Pizza( "게살피자" , "게살도우" , "게살소스" , list<string>() )
	{
		this->topping.push_back( "게살튀김" );
		this->topping.push_back( "스폰지밥" );
		this->topping.push_back( "오징어링" );
	}
	void Pizza::box()
	{
		cout << "딱봐도 정성스러운 포장" << endl;
	}

	void Pizza::bake()
	{
		cout << "30 분간 350 도 오븐에서 굽굽" << endl;
	}

	void Pizza::cut()
	{
		cout << "다내끄야" << endl;
	}
};