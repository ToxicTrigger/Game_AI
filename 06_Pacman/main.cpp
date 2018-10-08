#include <conio.h>
#include "../trigger/trigger/component_world.h"
#include "pacman.h"
#include "world.h"

auto main()-> int
{
	component_world *map = new component_world(true);
	world *pac_world = new world();

	ScreenInit();
	map->add(pac_world);
	while (true)
	{
		
	}

	ScreenRelease();
	return 0;
}