#pragma once
#include "Subject.h"
#include <stdio.h>
#include <list>


class WeatherData : public Subject
{
	std::list<Observer*> observers;
	int temp;
	int hum;
	int press;
	int observers_count;
public:
	void register_observer(Observer* target);

	void notify_observers();

	void remove_observer(Observer* target);

	void set_measurement(int t, int h, int p);
};