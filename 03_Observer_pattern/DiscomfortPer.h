#pragma once
#include "Observer.h"
#include <stdio.h>

class DiscomfortPer : public Observer
{
public :
	void update(int t, int h, int p);
};