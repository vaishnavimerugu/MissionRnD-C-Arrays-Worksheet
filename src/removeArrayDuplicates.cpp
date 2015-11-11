/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)
		return NULL;
	for (int i = 0; i < len; i++)
	{
		int j = i + 1;
		while (j < len)
		{
			if (Arr[j] == Arr[i])
			{
				for (int k = j; k < len; k++)
					Arr[k] = Arr[k + 1];
				len--;
			}
			else
				j++;
		}
	}
}