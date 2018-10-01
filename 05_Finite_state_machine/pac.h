#pragma once
#include "component.h"
#include <iostream>

class pac : public component
{
public:
	void update(float delta) noexcept
	{
		std::cout << "Pacman = " << delta << std::endl;
	}
};