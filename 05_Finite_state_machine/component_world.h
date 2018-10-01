#pragma once
#include <list>
#include "component.h"
#include <memory>

using namespace std;

class component_world : public component
{
public:
	list<component*> components;

	component_world()
	{
		components = list<component*>();
		update();
	}

	void add(unique_ptr<component> com)
	{
		com->update();
		components.push_back(com.get());
		update();
	}

	void update()
	{
		while (this->active && components.size() != 0)
		{ // Thread Ã¼ÀÎÁö
			for (auto i : components)
			{
				if (i->active)
				{
					i->update();
				}
			}
		}
	}
};