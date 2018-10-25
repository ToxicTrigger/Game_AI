#pragma once
#include "map.h"
#include <stack>
#include <list>
#include <iostream>
using namespace std;

struct point
{
	int x, y;
};

class dijkstra
{
private:
	map *_map;
	stack<point> _path;
	list<point> _visit_node;
	bool _found;

public:
	explicit inline dijkstra( map *_map_ ) : _map( _map_ ), _found(false)
	{
		_path = stack<point>();
		_visit_node = list<point>();
	}

	void choose( point &choice )const ;
	bool find_path( int sx, int sy, int dx, int dy );
	void draw();

	~dijkstra();
};

