#include "Miner.h"
#include "component_world.h"
#include "fsm.h"

using namespace std;

auto main() -> int
{
	Miner *miner = new Miner();
	component_world *world = new component_world();
	world->add(miner);

	getchar();
	
	return 0;
}