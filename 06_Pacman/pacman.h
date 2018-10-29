#pragma once
#include "../trigger/trigger/fsm.h"
#include "util.h"
#include "wall.h"
#include <thread>

class pacman : public component
{
public:
	char *p;
	int x, y;

	int input;
	int input_x, input_y;
	fsm::map *states;

	wall **map;

	float tick;
	std::thread key;

	pacman( wall **map )
	{
		p = (char*)"¡Ü";
		x = 9;
		y = 12;
		this->map = map;
		key = std::thread( &pacman::update_input, this );
		states = new fsm::map( new fsm::state( "Normal" ) );
		states->add_state( "Power Up" );
		states->link_state( "Normal", "Power Up" );
		states->link_state( "Power Up", "Normal" );

	}

	void update_input()
	{
		while( active )
		{
			input = _getch();

			if( map[y][x].w == (char*)"¢Á" )
			{
				map[y][x].w = (char*)"  ";
			}

			if( map[y][x].w == (char*)"¡Ü" )
			{
				states->change_link( "Normal", "Power Up", 0 );
				map[y][x].w = (char*)"  ";
			}

			if( input == LEFT )
			{
				if( map[y][x - 1].w != (char*)"¢Ì" )
					x += -1;
			}
			else if( input == RIGHT )
			{
				if( map[y][x + 1].w != (char*)"¢Ì" )
					x += 1;
			}
			else if( input == UP )
			{
				if( map[y - 1][x].w != (char*)"¢Ì" )
					y -= 1;
			}
			else if( input == DOWN )
			{
				if( map[y + 1][x].w != (char*)"¢Ì" )
					y += 1;
			}
		}
		key.join();
	}

	void draw_pacman( float delta )
	{
		if( states->get_now_state()->name == "Normal" )
		{
			SetColor( 2 );
			ScreenPrint( x, y, p );
			SetColor( 15 );
		}
		else
		{
			if( tick <= 10 )
			{
				tick += delta;
				SetColor( 5 );
				ScreenPrint( x, y, p );
				SetColor( 15 );
			}
			else
			{
				//state = 0;
				tick = 0;
				states->change_link( "Power Up", "Normal", 0 );
			}
		}
	}

	void update( float delta ) noexcept
	{
		states->simulate();
		draw_pacman( delta );
	}
};