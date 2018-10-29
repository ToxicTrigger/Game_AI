#include "dijkstra.h"

void dijkstra::choose(point & choice) const
{
	int min = INT_MAX;
	int w = _map->getWidth();
	int h = _map->getHeight();
	int cx, cy;

	auto cur = _visit_node.crbegin();
	for(; cur != _visit_node.crend(); ++cur)
	{
		for(int ty = -1; ty <= 1; ++ty)
		{
			for(int tx = -1; tx <= 1; ++tx)
			{
				cx = cur->x + tx;
				cy = cur->y + ty;
				if(cx < 0 || cx > w - 1 || cy < 0 || cy > h - 1 || (tx == 0 && ty == 0))
				{
					continue;
				}
				if(_map->getMapVal(cx, cy) < min && _map->getVisitInfo(cx, cy) == false)
				{
					min = _map->getMapVal(cx, cy);
					choice = {cx, cy};
				}
			}
		}
	}
}

bool dijkstra::find_path(int sx, int sy, int dx, int dy)
{
	_found = false;
	int g = 0;

	int w = this->_map->getWidth();
	int h = this->_map->getHeight();

	point **parent;
	parent = new point *[h];
	for(int i = 0; i < h; ++i)
	{
		parent[i] = new point[w];
	}

	static point c_n;
	c_n = {sx, sy};
	_map->setMapVal(sx, sy, 0);
	parent[sy][sx] = c_n;

	for(int i = 0; i < w * h; ++i)
	{
		choose(c_n);
		_map->setVisitInfo(c_n.x, c_n.y, true);
		_visit_node.push_back(c_n);

		if(c_n.x == dx && c_n.y == dy)
		{
			_found = true;
			break;
		}

		for(int ty = -1; ty <= 1; ++ty)
		{
			for(int tx = -1; tx <= 1; ++tx)
			{
				int nx = c_n.x + tx;
				int ny = c_n.y + ty;

				int dist = 0;
				if(nx < 0 || nx > w - 1 || ny < 0 || ny > h - 1)
				{
					continue;
				}

				if(_map->getVisitInfo(nx, ny) == false)
				{
					dist = (tx == 0 || ty == 0) ? 10 : 14;
					if(_map->getMapVal(c_n.x, c_n.y) + dist < _map->getMapVal(nx, ny))
					{
						int new_val = _map->getMapVal(c_n.x, c_n.y) + dist;
						_map->setMapVal(nx, ny, new_val);
						parent[ny][nx] = c_n;
					}
				}
			}
		}
	}
	if(_found)
	{
		point p = {dx, dy};
		_path.push(p);
		
		while(p.x != sx || p.y != sy)
		{
			p = parent[p.y][p.x];
			int min = 999;
			tile t;
			for(int ty = -1; ty < 2; ++ty)
			{
				for(int tx = -1; tx < 2; ++tx)
				{
					if(min >= _map->getMapVal(p.x + tx, p.y + ty))
					{
						min = _map->getMapVal(p.x + tx, p.y + ty);
						//_path.push(p);
						t = _map->_map[p.y + ty][p.x + tx];
					}
				}
			}
			p = parent[t.y][t.x];
			_path.push(p);
		}
		return true;
	}
	return _found;
}

void dijkstra::draw()
{
	_map->draw();
	if(_found)
	{
		point cp;
		do
		{
			cp = _path.top();
			cout << "(" << cp.x << "," << cp.y << ")==>";
			_path.pop();
		}
		while(!_path.empty());
		cout << "DONE" << endl;
	}
}

dijkstra::~dijkstra()
{
	delete _map;
}
