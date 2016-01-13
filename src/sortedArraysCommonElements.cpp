/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_to_num1(char * s)
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
int searchin(int * arr, int key,int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
		if (arr[i] == key)
			return i;
	return -1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
		return NULL;
	int i = 0,*first;
	first = (int *)malloc(sizeof(int)*ALen);
	for (i = 0; i < ALen; i++)
		first[i] = date_to_num1(A[i].date);

	int flag = -1,key,count=0;
	struct transaction * result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen < BLen ? ALen : BLen));
	for (i = 0; i < BLen; i++)
	{
		key = date_to_num1(B[i].date);
		flag = searchin(first, key, ALen);
		if (flag >= 0)
		{
			result[count] = A[flag];
			count++;
		}
	}
	if (count > 0)
		return result;
	else
		return NULL;
}