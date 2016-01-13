/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<stdlib.h>
#include<stdio.h>
int partition(int *x, int p, int r)
{
	int z = x[r];//pivot
	int i = p - 1;//pivot previous position
	int j = 0;//comaprision element
	int temp;
	for (j = i + 1; j < r; j++)
	{
		if (x[j] <= z)
		{
			i++;

			temp = x[i];

			x[i] = x[j];

			x[j] = temp;

		}
	}

	temp = x[i + 1];
	x[i + 1] = x[r];
	x[r] = temp;
	return i + 1;//returning the pivot position
}
void quicksort(int *arr, int low, int high)
{
	int pivot_pos;
	if (low < high)//base comdition
	{
		pivot_pos = partition(arr, low, high);//partitioning the array 
		quicksort(arr, 0, pivot_pos - 1);
		quicksort(arr, pivot_pos + 1, high);
	}
}
int search_for_one(int *a, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (i == len - 1)
		{
			if (a[i] != a[i - 1])
				return a[i];
		}
		if (i > 0)
		{
			if ((a[i - 1] != a[i]) && (a[i + 1] != a[i]))
				return a[i];
		}
		if (i == 0)
		{
			if (a[i] != a[i + 1])
				return a[i];
		}
	}
	return -1;
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	quicksort(A, 0, len - 1);
	return search_for_one(A, len );
}