#pragma once
#include <string>
#include <iostream>

using namespace std;

class DecoratorJewelry
{
protected:
	string name;
	string skill_name;

public:
	inline explicit DecoratorJewelry()
	{
		name = "Unkown Jewelry";
		skill_name = "Unknown Skill";
	};

	inline explicit DecoratorJewelry(string name, string skill_name) : DecoratorJewelry()
	{
		this->name = name;
		this->skill_name = skill_name;
	}

	inline explicit DecoratorJewelry(DecoratorJewelry *other)
	{
		this->name = other->get_name();
		this->skill_name = other->get_skill();
	}

	inline string get_origin_name() const noexcept
	{
		return name;
	}

	inline string get_origin_skill_name() const noexcept
	{
		return skill_name;
	}
	
	//���ܰ� �� ��Ȳ�� �����Ƿ� noexcept
	inline virtual auto get_name() const noexcept -> string { return this->name; }
	inline virtual auto get_skill() const noexcept -> string { return this->skill_name; }

	//ǥ�ø� �ϴ� �Լ��ϱ� ������ �ɹ� ���� ����Ǵ� ���� ����� ��
	inline virtual void rend_Jewelry() const noexcept
	{
		cout << "Name : " << this->name << endl
			<< "Skill : " << this->skill_name << endl;
	}

	~DecoratorJewelry()
	{
		cout << name << " ������" << endl;
	}
};