#include "sort.h"

void InsertSort(int* ar, int n)
{
	int key;
	for (int i = 1; i < n; i++)
	{
		key = ar[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (key < ar[j])
				ar[j + 1] = ar[j];
			else
				break;
		}
		ar[j + 1] = key;
	}
}

void MergeSort(int* ar, int n) {}
