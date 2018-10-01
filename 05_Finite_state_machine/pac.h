#pragma once
#include "component.h"
#include <iostream>

class pac : public component
{
public:
	void update()
	{
		std::cout << "Dd" << std::endl;
	}
};