#pragma once
#include "Fly.h"

class FlyWing : public Fly
{
public:
	void Fly::fly()
	{
		std::cout << "날개로 날아올라" << std::endl;
	}
};
