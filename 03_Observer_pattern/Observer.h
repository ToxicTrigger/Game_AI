#pragma once
class Observer
{
public :
	virtual void update(int tmp, int hum, int press) = 0;
};