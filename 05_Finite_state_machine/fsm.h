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

	//�ν��Ͻ��� ó�� �ʱ�ȭ �� �� �����ڿ� �Բ� ȣ�� 
	virtual void awake() = 0;
};