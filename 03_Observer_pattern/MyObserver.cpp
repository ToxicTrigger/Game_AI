#include "MyObserver.h"

void MyObserver::update(int t, int h, int p)
{
	cout << "기온 : " << t << "습도 : " << h << "기압 : " << p << endl;
}
