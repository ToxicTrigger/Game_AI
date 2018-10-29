#pragma once
#include "../trigger/trigger/fsm.h"
#include "util.h"
#include "pacman.h"
#include <conio.h>
#include <fstream>
#include <string>
#include "wall.h"
#include "ghost.h"

class world : public component
{
public:
	wall * *walls;
	int size = 22;

	pacman *player;
	ghost::pinky *pinky1;
	ghost::pinky *pinky2;

	world()
	{
		walls = new wall*[size];
		for( int i = 0; i < size; ++i ) walls[i] = new wall[size - 3];

		char *wall_p = (char*)"¢Ì";
		char *bisk_p = (char*)"¢Á";
		char *powe_p = (char*)"¡Ü";

		std::ifstream open( "map.txt" );
		for( int y = 0; y < size; ++y )
		{
			for( int x = 0; x < size - 3; ++x )
			{
				int t = 0;
				open >> t;
				if( t == 0 )
				{
					walls[y][x].w = wall_p;
				}
				else if( t == 1 )
				{
					walls[y][x].w = bisk_p;
				}
				else if( t == 4 )
				{
					walls[y][x].w = powe_p;
				}
				else
				{
					walls[y][x].w = (char*)"  ";
				}
				walls[y][x].x = x;
				walls[y][x].y = y;
			}
		}
		this->player = new pacman( walls );
		pinky1 = new ghost::pinky( walls, player );
		pinky2 = new ghost::pinky( walls, player );
		pinky2->x = 8;

	}

	void draw_map()
	{
		for( int y = 0; y < size; ++y )
		{
			for( int x = 0; x < size - 3; ++x )
			{
				ScreenPrint( x, y, walls[y][x].w );
			}
		}
	}


	void update( float delta ) noexcept
	{
		ScreenClear();
		draw_map();
		pinky1->update( delta );
		pinky2->update( delta );
		player->update( delta );
		ScreenFlipping();
	}
};
