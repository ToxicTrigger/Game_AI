#include "TrafficLight.h"
#include "component_world.h"
#include "fsm.h"

using namespace std;

auto main() -> int
{
	Traffic::light *light1 = new Traffic::light();
	Traffic::light *light2 = new Traffic::light();
	component_world *world = new component_world();

	world->add(light1);
	world->add(light2);

	auto tmp = world->get_components<Traffic::light>();
	getchar();
	
	return 0;
}