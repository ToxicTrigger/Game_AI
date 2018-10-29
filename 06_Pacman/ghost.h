#pragma once
#include "../trigger/trigger/fsm.h"
#include "wall.h"
#include "pacman.h"
#include <vector>
#include <math.h>

namespace ghost
{
	class pinky : public component
	{
	public:
		wall * *map;
		pacman *target;
		char *p = ( char* )"＠";
		int x, y;
		fsm::map *state;
		int move_count;

		pinky( wall **world, pacman *player )
		{
			target = player;
			map = world;
			x = y = 10;
			state = new fsm::map( new fsm::state( "Follow" ) );
			state->add_state( new fsm::state( "Run" ) );
			state->link_state( "Follow", "Run" );
			state->link_state( "Run", "Follow" );

		}

		void draw()
		{
			if( target->states->get_now_state()->name != "Power Up" )
			{
				state->change_link( "Run", "Follow", 0 );
				SetColor( 13 );
				ScreenPrint( x, y, p );
				SetColor( 15 );
			}
			else
			{
				state->change_link( "Follow", "Run", 0 );
				SetColor( 9 );
				ScreenPrint( x, y, p );
				SetColor( 15 );
			}
		}

		void update_end()
		{

			if( target->x == x && target->y == y )
			{
				if( target->states->get_now_state()->name == "Normal" )
				{
					target->active = false;
				}
				else {
					x = y = 10;
				}
			}
		}

		int distance( pacman *t )
		{
			int x = std::pow( t->x - this->x, 2 );
			int y = std::pow( t->y - this->y, 2 );
			return std::sqrtf( x + y );
		}

		int distance( pacman * p, wall *w )
		{
			int x = std::pow( p->x - w->x, 2 );
			int y = std::pow( p->y - w->y, 2 );
			return std::sqrtf( x + y );
		}

		int distance( int x, int y )
		{
			int xx = std::pow( x - this->x, 2 );
			int yy = std::pow( y - this->y, 2 );
			return std::sqrtf( xx + yy );
		}

		int distance( int x, int y, pacman *p )
		{
			int xx = std::pow( x - p->x, 2 );
			int yy = std::pow( y - p->y, 2 );
			return std::sqrtf( xx + yy );
		}

		int distance( int x, int y, int x1, int y1 )
		{
			int xx = std::pow( x - x1, 2 );
			int yy = std::pow( y - y1, 2 );
			return std::sqrtf( xx + yy );
		}

		int distance( wall *t )
		{
			int x = std::pow( t->x - this->x, 2 );
			int y = std::pow( t->y - this->y, 2 );
			return std::sqrtf( x + y );
		}

		float tick;
		void update_path( float delta )
		{
			if( tick >= 0.5f )
			{
				auto path = std::vector<wall>();
				//현재 위치 기준으로 상하좌우 타일 가져오기
				path.push_back( map[y - 1][x] );
				path.push_back( map[y][x - 1] );
				path.push_back( map[y][x + 1] );
				path.push_back( map[y + 1][x] );

				auto poss = std::vector<wall>();
				for( auto i = 0; i < 4; ++i )
				{
					if( path[i].w != ( char* )"▩" )
					{
						path[i].power = distance( target->x, target->y, path[i].x, path[i].y ) + distance( 10, 10, x, y );
						poss.push_back( path[i] );
					}
				}

				if( state->get_now_state()->name == "Follow" )
				{
					wall min;
					min.power = 99999;
					for( auto i : poss )
					{
						if( min.power >= i.power )
						{
							min = i;
						}
					}
					this->x = min.x;
					this->y = min.y;
					move_count += 1;
				}
				else if( state->get_now_state()->name == "Run" )
				{
					wall max;
					for( auto i : poss )
					{
						if( max.power <= i.power )
						{
							max = i;
						}
					}
					this->x = max.x;
					this->y = max.y;
				}
				tick = 0;
			}
			else
			{
				tick += delta;
			}

		}

		void update( float delta ) noexcept
		{
			update_end();
			update_path( delta );
			state->simulate();
			draw();
		}
	};
}