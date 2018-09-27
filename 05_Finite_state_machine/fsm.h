#pragma once
#include <thread>

class fsm
{
private:
	std::thread updater;
public:
	//�ν��Ͻ��� ó�� �ʱ�ȭ �� �� �����ڿ� �Բ� ȣ�� 
	virtual void awake() = 0;
	//fsm �� �� tick ������Ʈ �� ��ü�� �����ϵ��� �մϴ�.
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