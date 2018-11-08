#include "population.h"

#include <time.h>

void main()
{
	srand( (unsigned)time( NULL ) );
	population simple( 10, 5, 0.7, 0.02 );
	chromosome best = simple.get_best_chrom();
	int best_fit = best.get_fitness();
	int pop_size = simple.get_pop_size();

	int gen = 0;
	int solution = simple.get_chrom_size();

	double cross = simple.get_cross_over_rate();
	simple.draw();

	while( 1 )
	{
		gen++;
		cout << "==========" << endl;
		cout << "Gen : " << gen << endl;
		simple.draw();
		cout << "best : ";
		best.draw();

		if( best_fit == solution ) break;

		int chromSize = simple.get_chrom_size();
		chromosome e1( chromSize );
		chromosome e2( chromSize );
		int i = 0;
		double rnd;
		do
		{
			rnd = rand() / (double)RAND_MAX;
			if( rnd < cross )
			{
				e1 = simple.selection();
				e2 = simple.selection();
				simple.crossover( e1, e2 );
				simple.mutation( e1 );
				simple.mutation( e2 );
				e1.calc_fitness();
				e2.calc_fitness();
				simple.push_chrom_to_pop( i, e1 );
				simple.push_chrom_to_pop( i + 1, e2 );
				i += 2;
			}
		}
		while( i < pop_size );
		int worst = simple.get_worst_chrom_index();
		simple.push_chrom_to_pop( worst, best );
		simple.evaluation();
		simple.copy_pop_to_parent();
		best = simple.get_best_chrom();
		best_fit = best.get_fitness();
	}
	getchar();
}