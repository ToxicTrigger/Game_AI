#pragma once

class fsm
{
	enum state
	{
		null,
		inited,
	};
private:
	state state;
public:

	explicit fsm()
	{
		awake();
	}

	//인스턴스가 처음 초기화 될 때 생성자와 함께 호출 
	virtual void awake() = 0;
};