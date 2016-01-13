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
	if (A==NULL || B==NULL)
	return NULL;
	struct transaction * result = (struct transaction *)malloc(sizeof(struct transaction)* (ALen + BLen));
	int key1, key2;
	for (int i = ALen, j = BLen; i >= 0 && j >= 0;i--)
	{
		
	}
	
	
	return NULL;
}