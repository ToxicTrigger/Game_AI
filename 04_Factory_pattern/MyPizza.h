#pragma once
#include "Pizza.h"

class MyPizza : public Pizza
{
public:
	MyPizza() : Pizza( "�Ի�����" , "�Ի쵵��" , "�Ի�ҽ�" , list<string>() )
	{
		this->topping.push_back( "�Ի�Ƣ��" );
		this->topping.push_back( "��������" );
		this->topping.push_back( "��¡�" );
	}
	void Pizza::box()
	{
		cout << "������ ���������� ����" << endl;
	}

	void Pizza::bake()
	{
		cout << "30 �а� 350 �� ���쿡�� ����" << endl;
	}

	void Pizza::cut()
	{
		cout << "�ٳ�����" << endl;
	}
};