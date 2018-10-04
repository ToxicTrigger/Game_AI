#pragma once
#include <iostream>
#include "fsm.h"

namespace Traffic
{
	class light : public component
	{
		fsm::map *map;
		float start;
		bool is_red, is_yellow, is_green;

	public:
		light()
		{
			map = new fsm::map();
			map->add_state(new fsm::state{ "Red", nullptr, nullptr , false, false });
			map->add_state(new fsm::state{ "Yellow", nullptr, nullptr , false, false });
			map->add_state(new fsm::state{ "Green", nullptr, nullptr , false, false });
			map->link_state("idle", "Red");
			map->link_state("Red", "Yellow");
			map->link_state("Green", "Red");
			map->link_state("Yellow", "Green");
		}

		void update(float delta) noexcept
		{
			start += delta;
			map->change_state("Green", true, is_green);
			map->change_state("Red", true, is_red);
			map->change_state("Yellow", true, is_yellow);

			if (start >= 0 && start <= 3.0f)
			{
				is_green = true;
				is_red = false;
				is_yellow = false;
			}
			else if (start >= 3.0f && start <= 5.0f)
			{
				is_red = true;
				is_yellow = false;
			}
			else if (start >= 5.0f && start <= 8.0f)
			{
				is_yellow = true;
				is_green = false;
			}
			else if (start >= 8.0f && start <= 11.0f)
			{
				start = 0;
			}

			std::cout << "Play Time :" << start << std::endl;
			map->update(delta);
		}
	};
}
