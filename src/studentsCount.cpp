
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
int binarySearch(int *arr, int len, int ele)
{
	int low = 0, high = len - 1, mid;
	while (low <high)
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
void * studentsCount(int *Arr, int len, int score, int *lessCount,
	int *moreCount)
{
	*lessCount = 0;
	*moreCount = 0;
	if (Arr == NULL || len <= 0)
		return NULL;
	if ((len > 1 && Arr[0] == Arr[len - 1]) || (len == 1 &&
		score == Arr[0]))
		return NULL;
	int index = binarySearch(Arr, len, score);
	if (Arr[index - 1] == score)
		*lessCount = index - 1;
	else
		*lessCount = index;
	*moreCount = len - index;
}
