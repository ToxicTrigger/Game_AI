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
			//쓰레드에 람다 함수 먹이기
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
							//한가지 상태에서 다른 상태로 한번씩 전이가 가능하도록.
						case Traffic::red:
							if (Time.count() % 5 == 0) state = Traffic::green;
							cout << "지금 상태 : " << "R" << endl;
							break;
						case Traffic::green:
							if (Time.count() % 5 == 0) state = Traffic::yellow;
							cout << "지금 상태 : " << "G" << endl;
							break;
						case Traffic::yellow:
							if (Time.count() % 2 == 0) state = Traffic::red;
							cout << "지금 상태 : " << "Y" << endl;
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
