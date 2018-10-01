#pragma once
#include "component.h"
#include <iostream>

class player : public component
{
public:
	float time;
	void update(float delta) noexcept
	{
		std::cout << "Player : " << time << std::endl;
		time += delta;
	}
};