#include "JewelryFactory.h"
#include "PowerJewelry.h"
#include "LuckJewelry.h"
#include <iostream>
#include <memory>

using namespace std;

auto main() -> int
{
	auto fac = make_unique<JewelryFactory>();

	DecoratorJewelry *my = new DecoratorJewelry("기본" , "효과 없음");
	my->rend_Jewelry();

	my = new PowerJewelry(my);
	my->rend_Jewelry();
	
	my = fac->creat(new LuckJewelry(my));
	my->rend_Jewelry();

	getchar();
}