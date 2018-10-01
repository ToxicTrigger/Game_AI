#include "TrafficLight.h"
#include "player.h"
#include "pac.h"
#include "component_world.h"

using namespace std;

auto main() -> int
{
	component_world *world = new component_world();

	player *p = new player();
	world->add(p);
	world->add(new pac());

	return 0;
}