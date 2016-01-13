/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_to_num2(char * s)
{
	int num = 0, i;
	//converting the string date format to number making easy for comparision
	for (i = 6; i <= 9; i++)
	{
		num = num * 10 + s[i] - '0';
	}
	num = num * 10 + s[3] - '0';
	num = num * 10 + s[4] - '0';

	num = num * 10 + s[0] - '0';
	num = num * 10 + s[1] - '0';
	return num;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction * result = (struct transaction *)malloc(sizeof(struct transaction)* (ALen + BLen));
	// trading space for better time complexity 
	int * first = (int *)malloc(sizeof(int)*ALen);
	int * second = (int *)malloc(sizeof(int)*ALen);
	for (int i = 0; i < ALen; i++)
		first[i] = date_to_num2(A[i].date);

	for (int i = 0; i < BLen; i++)
		second[i] = date_to_num2(B[i].date);

	int i, j;
	// just like sorting arrays of sizing m and n ... takes time of O(m+n)
	//this is better compared to usual string comparisions coz ... it takes O(n) to compare and then n to iterate ... O(m^2) for loops ... so it takes O(n*m^2) ... O(n^3) \
		// so this is far better in complexity 
	for (i = ALen - 1, j = BLen - 1; i >= 0 && j >= 0;)
	{
		if (first[i]>second[j])
		{
			result[i + j + 1] = A[i];
			i--;
		}
		else if (first[i] < second[j])
		{
			result[i + j + 1] = B[j];
			j--;
		}
		else
		{
			result[i + j + 1] = B[j];
			j--;
			result[i + j + 1] = A[i];
			i--;
		}
	}
	int temp = j;

	if (i >= 0)
		for (j = 0; j <= i; j++)
			result[j] = A[j];

	if (temp >= 0)
		for (i = 0; i <= temp; i++)
			result[i] = B[i];
	return result;
}
