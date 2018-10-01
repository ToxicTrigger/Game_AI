#pragma once
#include "quval_object.h"
#include <iostream>

class player : public component
{
public:

	void update()
	{
		std::cout << "dd" << std::endl;
	}
};