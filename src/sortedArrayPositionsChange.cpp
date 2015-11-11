/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)
		return NULL;
	int pos1 = -1, pos2 = -1, temp;
	for (int i = 0; i < len; i++)
	{
		if (pos1 == -1)
		{
			if (i == 0)
			{
				if (Arr[i]>Arr[i + 1])
					pos1 = i;
			}
			else if (Arr[i - 1] < Arr[i] && Arr[i + 1]
				< Arr[i])
				pos1 = i;
		}

		else if (Arr[i] < Arr[i - 1])
			pos2 = i;


	}
	if (pos1 != -1 && pos2 != -1)
	{
		temp = Arr[pos2];
		Arr[pos2] = Arr[pos1];
		Arr[pos1] = temp;
	}
	return NULL;
}
