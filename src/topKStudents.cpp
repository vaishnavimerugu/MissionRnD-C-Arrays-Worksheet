/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int K)
{
	if (len < 1||K<=0)
		return NULL;
	if (K > len)
		K= len;
	int n = 0;
	struct student **result = (struct student **)malloc(n*sizeof(struct student));
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (students[j].score < students[j + 
1].score)
			{
				struct student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < K; i++)
	{
		result[n++] = &students[i];
	}
	return result;
}