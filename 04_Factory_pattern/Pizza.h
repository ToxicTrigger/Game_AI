#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;


class Pizza
{
protected:
	string name;

	string dough;

	string sauce;

	list<string> topping;

public:

	Pizza( void ) { }
	Pizza( Pizza* pizza )
	{
		this->name = pizza->name;
		this->dough = pizza->dough;
		this->sauce = pizza->sauce;
		this->topping = pizza->topping;
	}

	Pizza( string name , string dough , string sauce , list<string> topping )
	{
		this->name = name;
		this->dough = dough;
		this->sauce = sauce;
		this->topping = topping;
	}

	~Pizza( void )
	{
		if( topping.size() != 0 )
		{
			topping.clear();
		}
	}

	inline void prepare() const noexcept
	{
		cout << "준비 : " << name << endl;
		cout << "도우 펴는 중 ... " << endl;
		cout << "소스 바르는 중..." << endl;

		cout << "토핑 올리는 중 : ";
		auto itr = topping.cbegin();
		auto itr_end = topping.cend();
		for( ; itr != itr_end ; ++itr )
		{
			cout << " " << *itr ;
		}

		cout << endl;
	}

	virtual void bake() = 0;

	virtual void cut() = 0;

	virtual void box() = 0;

	inline string getName() const { return name; }
};