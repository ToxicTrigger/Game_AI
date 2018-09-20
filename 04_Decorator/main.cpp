#include "HouseBlend.h"
#include <memory>
#include <iostream>
#include "Mocha.h"
#include "Soy.h"


//�����͸� �ʹ� ���� �Űܴٴϴ� �� ������..
//��� �߸��ϸ� �ٷ� lost pointer �� ���´�.
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