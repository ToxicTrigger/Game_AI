#pragma once
#include "JewelryFactory.h"

class EastFactory : public JewelryFactory
{
protected:
	inline DecoratorJewelry *mining(DecoratorJewelry *type)
	{
		std::cout <<
			"===================" << std::endl <<
			"���� ���忡�� ����� : " << type->get_origin_name() << std::endl <<
			"===================" << std::endl;
		return type;
	}

};