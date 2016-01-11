/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdlib.h>
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_to_num(char * s)
{
	int num = 0, i;
	//char * s = (char*)malloc(sizeof(char) * 20);
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
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL)
		return -1;

	//converting dates to number
	int key = 0, i;
	key = date_to_num(date);
	int *date_num = (int *)malloc(sizeof(int)*len);
	int count = 0;
	for (i = 0; i < len; i++)
	{
		date_num[i] = date_to_num(Arr[i].date);
		if (date_num[i]>key)
		{
			count++;
			printf("%d %d\n", key, date_num[i]);
		}
	}
	return count;

}