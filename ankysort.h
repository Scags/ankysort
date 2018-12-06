#ifndef ANKYSORT
#define ANKYSORT

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ankysort(int *array, unsigned long n)
{
	unsigned long i, u, h, l, lowval, highval;
	int *array2;

	array2 = malloc(sizeof(*array)*n);
	if (!array2)
		return;

	u = array[0] > array[1];
	array2[0] = u ? array[1] : array[0];
	array2[n-1] = u ? array[0] : array[1];

	lowval = 0;
	highval = n-1;

	for (i = 2; i < n; ++i)
	{
		if (array[i] < array2[lowval])
		{
			for (u = lowval; u >= 0 && array[i] < array2[u]; --u)
				array2[u+1] = array2[u];

			array2[u+1] = array[i];
			++lowval;
		}
		else if (array2[lowval] <= array[i] && array[i] <= array2[highval])
		{
			l = abs(array[i] - array2[lowval]);
			h = abs(array[i] - array2[highval]);
			array2[h > l ? ++lowval : --highval] = array[i];
		}
		else
		{
			for (u = highval; u < n && array[i] > array2[u]; ++u)
				array2[u-1] = array2[u];
			
			array2[u-1] = array[i];
			--highval;
		}
	}

	free(array);
	memcpy(array, array2, n*sizeof(array));
}

#ifdef __cplusplus
}
#endif

#endif	// ANKYSORT