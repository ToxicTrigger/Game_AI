#include "map.h"


//∫Û ∏ ¿ª ∏∏µÏ¥œ¥Ÿ.
void map::initMap()
{
	for( int y = 0; y < _height; ++y )
	{
		for( int x = 0; x < _width; ++x )
		{
			_map[y][x].x = x;
			_map[y][x].y = y;
			_map[y][x].visit = false;
			_map[y][x].f = 999;
		}
	}
}

const void map::draw() const
{
	cout << "======" << endl;
	for( int y = 0; y < _height; ++y )
	{
		for( int x = 0; x < _width; ++x )
		{
			cout << _map[y][x].visit << "\t";
		}
		cout << endl;
	}
}

map::~map()
{
	delete[] _map;
}
