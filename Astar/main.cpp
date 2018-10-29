#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <math.h>
#include <Windows.h>

using namespace std;

static int map_w, map_h;

struct node
{
	int f = 999;
	int g = 0;
	int h = 0;
	int x = 0, y = 0;
	bool arrived = false;
	bool wall = false;
};

//�� ���
void draw(node **map)
{
	for(int y = 0; y < map_h; ++y)
	{
		for(int x = 0; x < map_w; ++x)
		{
			//f �� ����� ��� �� Ÿ���� F ���� ������ �� ������ ������ ���� ���� �鸥 ���� Ȯ���ϵ��� ��
			if(!map[y][x].wall)
			{
				if(!map[y][x].arrived)
				{
					cout << "��";
				}
				else
				{
					cout << "��";
				}
			}
			else
			{
				cout << "��" ;
			}
		}
		cout << endl;
	}
	cout << "==========================" << endl;
}

bool check_load(node **map, int x, int y, int dx, int dy, stack<node>& path_)
{
	auto path = std::stack<node>();
	int nx = x;
	int ny = y;

	// Ŀ��
	static node c_n;
	c_n = {x, y};
	//������
	map[y][x].arrived = true;
	map[y][x].g = 0;
	path.push(map[y][x]);

	bool found = false;

	//���� ��� Ÿ�� Ȯ��
	for(int count = 0; count < map_w * map_h; ++count)
	{
		c_n = path.top();

		if(c_n.x == dx && c_n.y == dy)
		{
			found = true;
			while(!path.empty())
			{
				path_.push(path.top());
				path.pop();
			}
			return true;
		}

		node next;

		auto min = std::vector<node>(0);

		//8���� ����
		for(int ty = -1; ty <= 1; ++ty)
		{
			for(int tx = -1; tx <= 1; ++tx)
			{
				int dist = 0;
				if(c_n.x + tx < 0 || c_n.x + tx > map_w - 1 || c_n.y + ty < 0 || c_n.y + ty > map_h - 1)
				{
					continue;
				}
				if(!map[c_n.y + ty][c_n.x + tx].arrived)
				{
					if(!map[c_n.y + ty][c_n.x + tx].wall)
					{
						// �̵� ��� ���
						dist = (tx == 0 || ty == 0) ? 10 : 14;
						//G ����
						map[c_n.y + ty][c_n.x + tx].g = c_n.g + dist;
						//H ���
						int h = static_cast<int>(std::sqrt(std::pow((dx - map[c_n.y + ty][c_n.x + tx].x), 2) + std::pow((dy - map[c_n.y + ty][c_n.x + tx].y), 2)) * dist);
						// H , F ����
						map[c_n.y + ty][c_n.x + tx].h = h;
						map[c_n.y + ty][c_n.x + tx].f = map[c_n.y + ty][c_n.x + tx].h + map[c_n.y + ty][c_n.x + tx].g;
						//�ּҸ� ã�� ���� ����

						min.push_back(map[c_n.y + ty][c_n.x + tx]);
					}
				}
			}
		}

		int low = 999;
		for(auto n : min)
		{
			if(n.f < low)
			{
				next = n;
				low = next.f;
			}
		}
		map[next.y][next.x].arrived = true;
		next.arrived = true;
		path.push(next);
	}
	return false;
}

int main()
{
	map_h = 10;
	map_w = 10;

	auto path = std::stack<node>();

	node **map = new node*[map_h];
	for(int i = 0; i < map_w; ++i)
	{
		map[i] = new node[map_w];
	}

	for(int y = 0; y < map_h; ++y)
	{
		for(int x = 0; x < map_w; ++x)
		{
			map[y][x].x = x;
			map[y][x].y = y;
		}
	}

	//�� ����
	map[3][2].wall = true;
	map[3][3].wall = true;
	map[3][1].wall = true;

	map[2][3].wall = true;

	map[5][0].wall = true;
	map[5][1].wall = true;

	if(check_load(map, 2, 2, 3, 9, path))
	{
		draw(map);

		Sleep(100);

		while(!path.empty())
		{
			auto t = path.top();
			std::cout << "(" << t.x << " ," << t.y << ")->";
			path.pop();
		}
		cout << "DONE" << endl;
	}
	else
	{
		cout << "���� ��ã��!" << endl;
	}



	getchar();
}