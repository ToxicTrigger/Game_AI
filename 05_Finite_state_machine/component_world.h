#pragma once
#include <list>
#include <memory>
#include <chrono>
#include <stdlib.h>
#include <thread>

#include "component.h"

using namespace std;

class component_world : public component
{
	typedef chrono::high_resolution_clock time;
	typedef chrono::time_point<chrono::steady_clock> Time;

private:
	list<component*> components;
	Time start_time;
	chrono::duration<float> delta_time;
	chrono::duration<float> run_time;
	thread main_thread;

public:
	//Build a new World
	component_world()
	{
		components = list<component*>();
		start_time = time::now();
		main_thread = thread(&component_world::update, this, delta_time.count());
	}

	inline float get_delta_time() noexcept
	{
		return delta_time.count();
	}

	template<typename T>
	T* get()
	{
		for (auto i : components)
		{
			auto t = dynamic_cast<T*>(i);
			if (t != nullptr)
			{
				return t;
			}
		}
		return nullptr;
	};

	component& get(int index) 
	{
		//TODO:: 인덱스 넘버로 가져오기!
	}

	//add component in world-component-list
	void add(component * com)
	{
		components.push_back(com);
	}

	//simulating world
	void update(float delta) noexcept
	{
		while (this->active)
		{
			run_time = chrono::duration_cast<chrono::duration<float>>(time::now() - start_time);
			auto t = time::now();

			for (auto i : components)
			{
				if (i->active)
				{
					i->update(this->delta_time.count());
				}
			}
			system("cls");

			delta_time = chrono::duration_cast<chrono::duration<float>>(time::now() - t);
		}
	}

	~component_world()
	{
		main_thread.join();
	}
};