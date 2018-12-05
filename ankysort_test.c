#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ankysort.h>

void* randlist(unsigned int, unsigned int);

int main()
{
	unsigned int i;
	const int n = 100;
	int *p = ( int* )randlist(n, 100);
	char s[1024] = "[";

	for (i = 0; i < n; ++i)
		sprintf(s, "%s %d", s, p[i]);

	printf("%s]\n", s);
	memset(s, 0, strlen(s));
	s[0] = '[';

	ankysort(p, n);
	for (i = 0; i < n; ++i)
		sprintf(s, "%s %d", s, p[i]);

	printf("%s]\n", s);

	free(p);
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
