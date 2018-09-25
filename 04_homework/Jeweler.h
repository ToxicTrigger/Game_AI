#pragma once
#include "DecoratorJewelry.h"

class Jeweler : public DecoratorJewelry
{
protected:
	DecoratorJewelry * jew;
public:
	inline Jeweler() : DecoratorJewelry() {};
	inline Jeweler(string name , string skill) : DecoratorJewelry(name , skill) {}

	inline Jeweler(DecoratorJewelry *jewelry) : DecoratorJewelry(jewelry)
	{
		this->jew = jewelry;
		this->name = jewelry->get_name();
		this->skill_name = jewelry->get_skill();
	}



	inline string get_name() const noexcept override
	{
		return this->jew->get_name() + " + " + this->name;
	}

	inline string get_skill() const noexcept override
	{
		return this->jew->get_skill() + " + " + this->skill_name;
	}

	inline void rend_Jewelry() const noexcept
	{
		cout << "Name : " << this->get_name() << endl
			<< "Skill : " << this->get_skill() << endl;
	}

};



