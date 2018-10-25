#include "map.h"


//∫Û ∏ ¿ª ∏∏µÏ¥œ¥Ÿ.
void map::initMap()
{
	for( int y = 0; y < _height; ++y )
	{
		for( int x = 0; x < _width; ++x )
		{
			_map[y][x] = 1000;
			_visit[y][x] = false;
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
			cout << _map[y][x] << "\t";
		}
		cout << endl;
	}
}

map::~map()
{
	delete[] _map;
	delete[] _visit;
}
