#include "WeatherData.h"
#include "MyObserver.h"
#include "ElementRenderer.h"

void main()
{
	WeatherData* w1 = new WeatherData();

	ElementRenderer* ele = new ElementRenderer();
	MyObserver* ob = new MyObserver();

	//등록
	w1->register_observer(ob);
	w1->register_observer(ele);
	
	//변경
	w1->set_measurement(10, 10, 5);
	w1->set_measurement(25, 33, 8);
	w1->set_measurement(22, 20, 3);

	getchar();
}