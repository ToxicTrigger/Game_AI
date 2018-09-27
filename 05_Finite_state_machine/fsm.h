#pragma once
#include <thread>

class fsm
{
private:
	std::thread updater;
public:
	//인스턴스가 처음 초기화 될 때 생성자와 함께 호출 
	virtual void awake() = 0;
	//fsm 이 매 tick 업데이트 할 객체를 정의하도록 합니다.
	virtual void update() {};

	fsm()
	{
		this->awake();
		updater = std::thread(&fsm::update, this);
	}

	~fsm()
	{
		updater.join();
	}
};