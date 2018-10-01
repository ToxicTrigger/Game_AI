#include "TrafficLight.h"
#include "player.h"
#include "pac.h"
#include "component_world.h"

using namespace std;

auto main() -> int
{
	//Traffic::Light light;
	component_world world;
	world.add(make_unique<player>());
	world.add(make_unique<pac>());
	getchar();
	return 0;
}