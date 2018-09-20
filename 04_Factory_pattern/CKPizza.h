#pragma once
#include "Pizza.h"

class CKPizza : public Pizza
{
public:

	CKPizza()
	{
		this->name = "Ã»°­ÀÇ ¸í¹° ÇÇÀÚ";
		this->dough = "¾ßµé¾ßµéÇÑ µµ¿ì";
		this->sauce = "»õÄÞ ´ÞÄÞ Â¬Â© ´ÜÂ§´ÜÂ§ÀÇ Á¤¼®";
		this->topping.push_back( "ÂÌ±ê ¹ö¼¸" );
		this->topping.push_back( "¸ÅÄÞ ÇÜ" );
		this->topping.push_back( "¸Ô°í½Í´Ù" );
	}

	void Pizza::box()
	{
		cout << "´Ù ´ã¾Æ ´ã¾Æ, ÁI½î¾²Á¶¾Æ" << endl;
	}

	void Pizza::bake()
	{
		cout << "30 ºÐ°£ 350 µµ ¿Àºì¿¡¼­ ±Á±Á" << endl;
	}

	void Pizza::cut()
	{
		cout << "8 Á¶°¢À¸·Î ³È³È" << endl;
	}
};