#pragma once
#include "Observer.h"
#include <stdio.h>

class ElementRenderer : public Observer
{
	int count;

	int all_t, all_h, all_p;
public:
	void update(int t, int h, int p);
};

