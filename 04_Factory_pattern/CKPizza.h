#pragma once
#include "Pizza.h"

class CKPizza : public Pizza
{
public:

	CKPizza() : Pizza( "청강의 명물 피자" , "야들야들한 도우" , "새콤 달콤 짭짤 단짠단짠의 정석" , list<string>())
	{
		this->topping.push_back( "쫄깃 버섯" );
		this->topping.push_back( "매콤 햄" );
		this->topping.push_back( "먹고싶다" );
	}

	void Pizza::box()
	{
		cout << "다 담아 담아, 핱쏘쓰조아" << endl;
	}

	void Pizza::bake()
	{
		cout << "30 분간 350 도 오븐에서 굽굽" << endl;
	}

	void Pizza::cut()
	{
		cout << "8 조각으로 냠냠" << endl;
	}
};