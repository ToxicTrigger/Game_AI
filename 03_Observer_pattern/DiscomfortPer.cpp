#include "DiscomfortPer.h"

void DiscomfortPer::update(int t, int h, int p)
{
	float tt = (9 / 5) * t;
	printf("�������� : %f\n", tt - 0.55f * (1 - h) * (tt - 26) + 32);
}
