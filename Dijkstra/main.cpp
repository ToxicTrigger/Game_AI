#include "dijkstra.h"

void main()
{
	map game( 10, 10 );
	dijkstra short_path( &game );

	short_path.draw();

	bool f = short_path.find_path( 0, 9, 5, 5 );
	short_path.draw();
}