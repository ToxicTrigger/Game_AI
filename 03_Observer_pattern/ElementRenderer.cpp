#include "ElementRenderer.h"

void ElementRenderer::update(int t, int h, int p)
{
	count++;
	this->all_h += h;
	this->all_p += p;
	this->all_t += t;

	printf("��� ��� : %d | ��� ���� : %d | ��� ��� : %d\n", 
		this->all_t / count,
		this->all_h / this->count, 
		this->all_p / this->count
	);
}
