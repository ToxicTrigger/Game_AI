#pragma once
class component
{
public:
	bool active = true;
	virtual void update() = 0;
};