#include "JewelryFactory.h"
#include "PowerJewelry.h"
#include "LuckJewelry.h"
#include <iostream>
#include <memory>

using namespace std;

auto main() -> int
{
	auto fac = make_unique<JewelryFactory>();

	DecoratorJewelry *my = new DecoratorJewelry("�⺻" , "ȿ�� ����");
	my->rend_Jewelry();

	my = new PowerJewelry(my);
	my->rend_Jewelry();
	
	my = fac->creat(new LuckJewelry(my));
	my->rend_Jewelry();

	getchar();
}