#pragma once
#include <iostream>

using namespace std;

class map
{
private:
	int **_map;
	bool **_visit;
	int _width, _height;

public:
	explicit map( int w, int h ) : _width( w ), _height( h )
	{
		_map = new int *[h];
		_visit = new bool *[h];
		for( int i = 0; i < h; ++i )
		{
			_map[i] = new int[w];
			_visit[i] = new bool[w];
		}
		initMap();
	}

	void initMap();

	constexpr int getWidth() const
	{
		return _width;
	}
	constexpr int getHeight() const
	{
		return _height;
	}

	constexpr void setMapVal(int x, int y, int val)
	{
		_map[y][x] = val;
	}

	constexpr int getMapVal( int x, int y ) const
	{
		return _map[y][x];
	}

	constexpr void setVisitInfo( int x, int y, bool val )
	{
		_visit[y][x] = val;
	}

	constexpr bool getVisitInfo( int x, int y ) const
	{
		return _visit[y][x];
	}

	const void draw() const;


	~map();
};

