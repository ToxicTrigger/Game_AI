#pragma once
#include "chromosome.h"
class population
{
	vector<chromosome> _pop;
	vector<chromosome> _old;
	chromosome _best;
	chromosome _worst;

	int _pop_size;
	int _chrom_size;
	int _total_fitness;
	double _cross_over_rate;
	double _mutation_rate;

public:
	population( int pSize, int cSize, double cR, double mR );
	chromosome selection();
	void crossover( chromosome &chrom1, chromosome &chrom2 );
	void mutation(chromosome &chrom);
	void evaluation();
	void copy_pop_to_parent();
	void push_chrom_to_pop(int pos, chromosome chrom);

	chromosome get_best_chrom()
	{
		return _best;
	}

	int get_worst_chrom_index();
	int get_pop_size()
	{
		return _pop_size;
	}

	int get_chrom_size()
	{
		return _chrom_size;
	}

	int get_cross_over_rate()
	{
		return _cross_over_rate;
	}

	int get_mutation_rate()
	{
		return _mutation_rate;
	}

	void draw();
};