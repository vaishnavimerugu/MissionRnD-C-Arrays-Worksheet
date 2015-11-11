/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int binaryInsert(int *arr, int len, int ele)
{
	int low = 0, high = len - 1, mid;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == ele)
			return mid + 1;
		else if (arr[mid] < ele)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (arr[low] < ele)
		return(low + 1);
	else
		return low;
}
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len <= 0)
		return NULL;
	int index = binaryInsert(Arr, len, num);
	int *arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
	if (index == len)
		arr[len] = num;
	else
	{
		for (int i = len; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = num;
	}
	return &arr[0];
}