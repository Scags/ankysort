#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ankysort.h>

void* randlist(unsigned int, unsigned int);
int comp(const void*, const void*);

int main()
{
	unsigned int i;
	const int n = 100;
	int *p = ( int* )randlist(n, 10000);
	int *p2 = ( int* )randlist(n, 10000);
	clock_t *start, *end;

	start = malloc(2*sizeof(clock_t));
	end = malloc(2*sizeof(clock_t));

	start[0] = clock();
	ankysort(p, n);
	end[0] = clock();

	start[1] = clock();
	qsort(p2, n, sizeof(int), comp);
	end[1] = clock();

	printf("ankysort:%f\nqsort:%f\n", (end[0]-start[0])/( double )CLOCKS_PER_SEC, (end[1]-start[1])/( double )CLOCKS_PER_SEC);

	free(start);
	free(end);
	return 0;
}

void *randlist(unsigned int n, unsigned int r)
{
	int *p = malloc(n*sizeof(n));
	if (!p)
		return NULL;

	unsigned int i;
	srand(time(NULL));
	for (i = 0; i < n; ++i)
		p[i] = rand() % r;

	return p;
}

int comp(const void* a, const void* b)
{
	return (*( int* )a) - (*( int* )b);
}
