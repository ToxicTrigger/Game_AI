#pragma once
#include <thread>
#include <string>
#include <vector>
#include "component.h"
#include <iostream>


namespace fsm 
{
	struct state
	{
		std::string name;
		state *next, *cur;
		bool def, op;
	};

	class map : public component
	{
	public:
		std::vector<state*> states;
		state *now_state;
		
		map()
		{
			states = std::vector<state*>();
			state *idle = new state{"idle", nullptr, nullptr, true, true};
			idle->cur = idle;
			add_state(idle);
			now_state = idle;
		}

		map(state *def_state) : map()
		{
			now_state = def_state;
		}

		inline state* get_state(unsigned int index) const noexcept
		{
			if (index >= states.size()) return nullptr;
			return states[index];
		}

		inline state* get_state(std::string name) const noexcept
		{
			for (auto i : states)
			{
				if (i->name == name)
				{
					return i;
				}
			}
			return nullptr;
		}

		inline state* get_state(state *state)
		{
			for (auto i : states)
			{
				if (i == state) return i;
			}
			return nullptr;
		}

		inline bool link_state(std::string state1, std::string state2) const noexcept
		{
			state *a = get_state(state1);
			state *b = get_state(state2);
			if (a == nullptr && b == nullptr)
			{
				return false;
			}
			
			a->next = b;
			b->cur = a;
			return true;
		}

		inline void add_state(state *new_state) noexcept
		{
			if (new_state != nullptr)
			{
				states.push_back(new_state);
			}
		}

		inline void simulate() noexcept
		{
			if (now_state->def && now_state->op)
			{
				if (now_state->next != nullptr)
				{
					now_state = now_state->next;
				}
			}
		}

		inline bool change_state(std::string name, bool def, bool op) const noexcept
		{
			state *tmp = get_state(name);
			if (tmp != nullptr)
			{
				tmp->def = def;
				tmp->op = op;
				return true;
			}
			return false;
		}

		void update(float delta) noexcept
		{
			
			simulate();
			std::cout << "now_state : " << now_state->name << std::endl;
		}

		~map()
		{
			if (now_state != nullptr)
			{
				delete now_state;
			}

			states.clear();
		}

	};

}
