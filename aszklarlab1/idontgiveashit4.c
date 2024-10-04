#include <stdio.h>
#include <stdlib.h>

double multiply ( double a, unsigned int b);

double arrayProduct ( unsigned int n, unsigned int A [ ] );

double arraySum ( unsigned int n, unsigned int A [ ] )

#define N 5

void main(void)
{
	unsigned int A1 [ ] = { 1, 2, 3, 4, 5, 6 };
	unsigned int A2 [ N ] = { 0, 1, 2, 3, 4};
	printf( "Product of A1: %f\n", arrayProduct( N, A1 ) );
	printf( "and product of A2: %f\n", arrayProduct( N, A2 ) );
	printf( "and sum of A1: %f\n", arraySum( N, A1) );
	system( "pause" );
}

double multiply ( double a, unsigned int b)
{
	int i;
	double r = 0;
	for ( i = 0, i < b, i++)
	{
		r = r + a
	}
	return r;
}

double arrayProduct ( int n, unsigned int A [ ] )
{
	double r;
	while ( i < n )
	{
		if ( A [ i ] = 0 )
			return -1; // Special value returned indicating that there was an element with value 0
		}
		++i;
		r = multiply( r, A [ i ] );
	}
}
