#include "WeatherData.h"

void WeatherData::register_observer(Observer* target)
{
	if (target != nullptr)
	{
		observers.push_back(target);
	}
	else
	{
		printf("Failed : target Observer is nullptr, regist failed!\n");
	}
}

void WeatherData::notify_observers()
{
	std::list<Observer*>::iterator iter;
	for (iter = this->observers.begin(); iter != this->observers.end(); ++iter)
	{
		printf("Observer [%p] :", iter._Ptr);
		iter._Ptr->_Myval->update(this->temp, this->hum, this->press);
	}
}

void WeatherData::remove_observer(Observer* target)
{
	if (target != nullptr)
	{
		observers.remove(target);
	}
	else
	{
		printf("Failed : target Observer is nullptr, remove failed!\n");
	}
}
	

void WeatherData::set_measurement(int t, int h, int p)
{
	this->temp = t;
	this->hum = h;
	this->press = p;

	this->notify_observers();
}
;