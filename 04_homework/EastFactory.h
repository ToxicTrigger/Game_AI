#pragma once
#include "JewelryFactory.h"

class EastFactory : public JewelryFactory
{
protected:
	inline DecoratorJewelry *mining(DecoratorJewelry *type)
	{
		std::cout <<
			"===================" << std::endl <<
			"동쪽 공장에서 생산됨 : " << type->get_origin_name() << std::endl <<
			"===================" << std::endl;
		return type;
	}

};