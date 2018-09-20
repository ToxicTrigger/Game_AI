#pragma once
#include "Pizza.h"

class CKPizza : public Pizza
{
public:

	CKPizza() : Pizza( "û���� �� ����" , "�ߵ�ߵ��� ����" , "���� ���� ¬© ��§��§�� ����" , list<string>())
	{
		this->topping.push_back( "�̱� ����" );
		this->topping.push_back( "���� ��" );
		this->topping.push_back( "�԰�ʹ�" );
	}

	void Pizza::box()
	{
		cout << "�� ��� ���, �I�����" << endl;
	}

	void Pizza::bake()
	{
		cout << "30 �а� 350 �� ���쿡�� ����" << endl;
	}

	void Pizza::cut()
	{
		cout << "8 �������� �ȳ�" << endl;
	}
};