#pragma once
#include "fsm.h"

class Miner : public component
{
	fsm::map *map;
	float time;
	float money;
	float thirst;
	float totalMoney;

public:
	Miner()
	{

		map = new fsm::map();
		map->add_state(new fsm::state("GoHome"));
		map->link_state("idle", "GoHome");
		map->change_state("idle", true, true);
		map->add_state(new fsm::state("EnterMineAndDig"));
		map->add_state(new fsm::state("VisitBank"));
		map->add_state(new fsm::state("QuenchThist"));

		map->link_state("GoHome", "EnterMineAndDig");
		map->link_state("EnterMineAndDig", "QuenchThist");
		map->link_state("EnterMineAndDig", "VisitBank");

		map->link_state("QuenchThist", "EnterMineAndDig");
		map->link_state("VisitBank", "GoHome");

		money = 3;
		time = 0;
		thirst = 0;
	}

	void update(float delta) noexcept
	{
		if (map->now_state->name == "GoHome")
		{
			if (money >= 0)
			{
				money -= delta;
			}
			else
			{
				map->now_state = map->get_state("EnterMineAndDig");
			}
		}

		if (map->now_state->name == "EnterMineAndDig")
		{
			money += delta;

			if (money >= 5)
			{
				map->now_state = map->get_state("VisitBank");
			}

			if (thirst <= 3)
			{
				thirst += delta;
			}
			else 
			{
				map->now_state = map->get_state("QuenchThist");
			}
		}

		if (map->now_state->name == "QuenchThist")
		{
			if (thirst >= 0)
			{
				thirst -= delta;
			}
			else
			{
				map->now_state = map->get_state("EnterMineAndDig");
			}
		}

		if (map->now_state->name == "VisitBank")
		{
			
			if (money >= 0)
			{
				totalMoney += delta;
				money -= delta;
			}
			else
			{
				money = 0;
				map->now_state = map->get_state("GoHome");
			}
		}

		time += delta;
		map->simulate();
		std::cout << "Miner time : " << time << std::endl;
		std::cout << "Miner money : " << money << std::endl;
		std::cout << "Miner TotalMoney : " << totalMoney << std::endl;
		std::cout << "Miner thirst : " << thirst << std::endl;
		std::cout << "Miner State : " << map->now_state->name << std::endl;
	}
};