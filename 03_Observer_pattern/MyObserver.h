#pragma once
#include "Observer.h"
#include <iostream>

using namespace std;

class MyObserver : public Observer
{
public:
	void update(int t, int h, int p);
};