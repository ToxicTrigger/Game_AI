#pragma once
#include <thread>
#include <string>
#include <vector>
#include "component.h"
#include <iostream>


namespace fsm 
{
	class state
	{
	public:
		std::string name;
		bool op;
		state(std::string name)
		{
			this->name = name;
		}
	};

	class link
	{

	public:
		static const unsigned int MAX_OPS = 12;
		state *cur;
		state *next;
		bool* ops;

		link()
		{
			cur = nullptr;
			next = nullptr;
			ops = new bool[link::MAX_OPS];
		}

		link(state *current, state *next) : link()
		{
			this->cur = current;
			this->next = next;
		}
	};

	class map : public component
	{
	public:
		std::vector<state*> states;
		std::vector<link*> links;
		state *now_state;
		
		map()
		{
			states = std::vector<state*>();
			links = std::vector<link*>();
			state *idle = new state("idle");
			idle->op = true;
			add_state(idle);
			now_state = idle;
		}

		map(state *def_state) : map()
		{
			// inited state idle
			link *def = new link(now_state, def_state);
			def->ops[0] = true;
			links.push_back(def);
			//now_state = def_state;
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

		inline bool link_state(std::string state1, std::string state2) noexcept
		{
			state *a = get_state(state1);
			state *b = get_state(state2);
			if (a == nullptr && b == nullptr)
			{
				return false;
			}
			link *tmp = new link(a, b);
			this->links.push_back(tmp);

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
			for (auto i : this->links)
			{
				if (i->cur->name == now_state->name)
				{
					int size = sizeof(i->ops) / sizeof(bool);
					bool all_pass = true;
					for (int ii = 0; ii < size; ++ii)
					{
						if (!i->ops[ii])
						{
							all_pass = false;
						}
					}
					if (all_pass)
					{
						now_state = i->next;
						int size = sizeof(i->ops) / sizeof(bool);
						for (int ii = 0; ii < size; ++ii)
						{
							i->ops[ii] = false;
						}
					}
				}
			}
		}

		inline bool change_state(std::string name, unsigned int op_index ,bool op) const noexcept
		{
			state *tmp = get_state(name);
			if (tmp != nullptr)
			{
				tmp->op = true;
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
			links.clear();
		}

	};

}
