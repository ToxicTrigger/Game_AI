#pragma once
#include <vector>
#include <iostream>
using namespace std;

class chromosome
{
	vector<int>	_genes;
	int			_chrom_size;
	int			_fitness;
	double		_fitness_rate;


public:
	chromosome();
	chromosome( int size );

	void reset(int size);
	void init();

	void calc_fitness();
	int get_chrom_size();
	int get_fitness();
	double get_fitness_rate();
	void set_fitness_rate( double rate );

	vector<int> get_chromosome();
	void set_chromosome( vector<int> chrom );
	void draw();
};