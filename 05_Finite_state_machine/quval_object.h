#pragma once
#include "component.h"

class quval_object : public component
{
public:
	quval_object()
	{
		quval_object::update();
	}

};