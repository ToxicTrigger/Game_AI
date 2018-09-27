#pragma once
#include "DecoratorJewelry.h"
#include <memory>
#include <iostream>

class JewelryFactory
{
protected:
	virtual DecoratorJewelry *mining(DecoratorJewelry *type)
	{
		std::cout << 
			"===================" << std::endl <<
			"기본 공장에서 생산됨 : " << type->get_origin_name() << std::endl << 
			"===================" << std::endl;
		return type;
	}
public:
	inline auto creat(DecoratorJewelry *type) noexcept -> DecoratorJewelry*
	{
		if (type == nullptr) return nullptr;

		auto tmp = mining(type);
		return tmp;
	}
};