#include "chromosome.h"

chromosome::chromosome()
{
	reset( 5 );
}

chromosome::chromosome( int size )
{
	reset( size );
}

void chromosome::reset(int size)
{
	this->_chrom_size = size;
	this->_fitness = 0;
	this->_fitness_rate = 0;
	this->_genes.resize( size );
	init();
}

void chromosome::init()
{
	for( int i = 0; i < _chrom_size; ++i )
	{
		_genes[i] = rand() / (double)RAND_MAX >= 0.5 ? 1 : 0;
	}
	calc_fitness();
}

void chromosome::calc_fitness()
{
	_fitness = 0;
	for( int i = 0; i < _chrom_size; i++ )
	{
		_fitness += _genes[i];
	}
}

int chromosome::get_chrom_size()
{
	return this->_chrom_size;
}

int chromosome::get_fitness()
{
	return this->_fitness;
}

double chromosome::get_fitness_rate()
{
	return this->_fitness_rate;
}

void chromosome::set_fitness_rate( double rate )
{
	this->_fitness_rate = rate;
}

vector<int> chromosome::get_chromosome()
{
	return this->_genes;
}

void chromosome::set_chromosome( vector<int> chrom )
{
	for( int i = 0; i < _chrom_size; i++ )
	{
		_genes[i] = chrom[i];
	}
}

void chromosome::draw()
{
	for( int i = 0; i < _chrom_size; i++ )
	{
		cout << _genes[i] << " ";
	}
	cout << " >> fit " << _fitness;
	cout << " >> fitness_rate " << _fitness_rate;
	cout << endl;
}
