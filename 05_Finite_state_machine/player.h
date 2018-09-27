#pragma once
#include "fsm.h"
#include <iostream>

class player : public fsm
{
public:
	player() : fsm()
	{

	}
	
	void awake() override
	{
		std::cout << "초기화 끝" << std::endl;
	}
	void update() override
	{
		std::cout << "안녕";
	}
};