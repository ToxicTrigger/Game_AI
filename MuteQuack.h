#pragma once
#include "Quack.h"

class MuteQuack : public Quack
{
public:
	void Quack::quack()
	{
		std::cout << "Á¶¿ë" << std::endl;
	}
};