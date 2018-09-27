#pragma once
#include <thread>
#include <chrono>
#include <iostream>
#include <stdlib.h>

namespace Traffic
{
	using namespace std;

	typedef chrono::high_resolution_clock time;

	enum State
	{
		red,
		yellow,
		green,
	};

	class Light
	{
	public:
		State state = green;

		Light()
		{
			//�����忡 ���� �Լ� ���̱�
			thread t = thread([=]()
			{
				auto start = time::now();
				float t = 0;
				while (true)
				{
					auto cur = time::now();

					auto Time = chrono::duration_cast<chrono::duration<int>>(cur - start);

					auto float_time = chrono::duration_cast<chrono::duration<float>>(cur - start);

					auto t1 = time::now();
					auto t2 = time::now();

					if (t >= 1.0f)
					{
						system("cls");
						switch (state)
						{
							//�Ѱ��� ���¿��� �ٸ� ���·� �ѹ��� ���̰� �����ϵ���.
						case Traffic::red:
							if (Time.count() % 5 == 0) state = Traffic::green;
							cout << "���� ���� : " << "R" << endl;
							break;
						case Traffic::green:
							if (Time.count() % 5 == 0) state = Traffic::yellow;
							cout << "���� ���� : " << "G" << endl;
							break;
						case Traffic::yellow:
							if (Time.count() % 2 == 0) state = Traffic::red;
							cout << "���� ���� : " << "Y" << endl;
							break;
						}
						t = 0;

					}
					else
					{
						t += chrono::duration_cast<chrono::duration<float>>(t2 - t1).count() * 10;
					}
				};
			});
			t.join();
		}
	};
}
