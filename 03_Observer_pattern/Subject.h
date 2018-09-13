#pragma once
#include "Observer.h"

class Subject
{
public:
	virtual void remove_observer(Observer* target) = 0;
	virtual void notify_observers() = 0;
	virtual void register_observer(Observer* target) = 0;
};
