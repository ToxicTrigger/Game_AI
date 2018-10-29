#pragma once
#include <iostream>

using namespace std;

struct tile
{
	int x = 0, y = 0;
	int f = 0, g = 0, h = 0;
	bool visit = false;
};

class map
{
private:

	
	int _width, _height;

public:
	tile * *_map;
	explicit map( int w, int h ) : _width( w ), _height( h )
	{
		_map = new tile *[h];
		
		for( int i = 0; i < h; ++i )
		{
			_map[i] = new tile[w];
			
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
		_map[y][x].f = val;
	}

	constexpr int getMapVal( int x, int y ) const
	{
		if(x - 1 > _width && x + 1 < _width && y - 1 > _height && y + 1 < _height)
		{
			return _map[y][x].f;
		}
		return 999;
	}

	constexpr void setVisitInfo( int x, int y, bool val )
	{
		_map[y][x].visit = val;
	}

	constexpr bool getVisitInfo( int x, int y ) const
	{
		return _map[y][x].visit;
	}

	const void draw() const;
	~map();
};

