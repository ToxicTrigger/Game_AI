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
		std::cout << "�ʱ�ȭ ��" << std::endl;
	}
	void update() override
	{
		std::cout << "�ȳ�";
	}
};