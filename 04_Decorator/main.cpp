#include "HouseBlend.h"
#include <memory>
#include <iostream>
#include "Mocha.h"
#include "Soy.h"


//포인터를 너무 많이 옮겨다니는 것 같은데..
//까딱 잘못하면 바로 lost pointer 각 나온다.
//shard_ptr? unique_ptr?

auto main() -> void
{
	Beverage* beverage = new HouseBlend();

	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;

	beverage = new Mocha( beverage );
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;

	beverage = new Soy( beverage );
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;

	getchar();
}