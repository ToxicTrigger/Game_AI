#pragma once
#include "Quack.h"

class MuteQuack : public Quack
{
public:
	void Quack::quack()
	{
		std::cout << "����" << std::endl;
	}
};