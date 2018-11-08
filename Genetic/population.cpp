#include "population.h"

population::population( int pSize, int cSize, double cR, double mR )
{
	this->_pop_size = pSize;
	this->_chrom_size = cSize;
	this->_cross_over_rate = cR;
	this->_mutation_rate = mR;
	this->_total_fitness = 0;

	this->_pop.resize( pSize );
	this->_old.resize( pSize );
	for( int i = 0; i < pSize; i++ )
	{
		_pop[i].reset( cSize );
	}
	evaluation();
	copy_pop_to_parent();
}

chromosome population::
selection()
{
	int select = 0;
	double rnd = rand() / (double)RAND_MAX;
	double sel = 0.0;
	for( int i = 0; i < _pop_size; i++ )
	{
		sel += _old[i].get_fitness_rate();
		if( sel > rnd )
		{
			select = i;
			break;
		}
	}
	return _old[select];
}

void population::crossover( chromosome & chrom1, chromosome & chrom2 )
{
	int cross = rand() % _chrom_size;
	auto gen1 = chrom1.get_chromosome();
	auto gen2 = chrom2.get_chromosome();

	for( int i = 0; i < cross; i++ )
	{
		int t = gen1[i];
		gen1[i] = gen2[i];
		gen2[i] = t;
	}
	chrom1.set_chromosome( gen1 );
	chrom2.set_chromosome( gen2 );
}

void population::mutation( chromosome & chrom )
{
	int mut = rand() % _chrom_size;
	double rnd = rand() / (double)RAND_MAX;
	if( rnd > _mutation_rate ) return;

	auto gen = chrom.get_chromosome();
	gen[mut] = !gen[mut];
	chrom.set_chromosome( gen );
}

void population::evaluation()
{
	_total_fitness = 0;
	int best_fit = 0;
	int best_chrom_index = 0;

	for( int i = 0; i < _pop_size; i++ )
	{
		_pop[i].calc_fitness();
		int  cur = _pop[i].get_fitness();
		if( cur > best_fit )
		{
			best_fit = cur;
			best_chrom_index = i;
		}
		_total_fitness += cur;
	}
	for( int i = 0; i < _pop_size; i++ )
	{
		double cur = _pop[i].get_fitness() / (double)_total_fitness;
		_pop[i].set_fitness_rate( cur );
	}
	_best = _pop[best_chrom_index];
}

void population::copy_pop_to_parent()
{
	for( int i = 0; i < _pop_size; i++ )
	{
		_old[i] = _pop[i];
	}
}

void population::push_chrom_to_pop( int pos, chromosome chrom )
{
	_pop[pos] = chrom;
}

int population::get_worst_chrom_index()
{
	int worst = _pop[0].get_fitness();
	int worst_index = 0;
	for( int i = 0; i < _pop_size; i++ )
	{
		int cur = _pop[i].get_fitness();
		if( cur < worst )
		{
			worst = cur;
			worst_index = i;
		}
	}
	return worst_index;
}

void population::draw()
{
	for( int i = 0; i < _pop_size; i++ )
	{
		_pop[i].draw();
	}
}
