#include "sort.h"
#include <cstring>

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

void Merge(int* ar, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *left, *right;
	left = new int[n1];
	right = new int[n2];
	memcpy(left, &ar[p], n1 * sizeof(int));
	memcpy(right, &ar[q + 1], n2 * sizeof(int));
	int i = 0, j = 0;
	for (int k = p; k <= r; k++)
	{

		if (i < n1 && j < n2)
		{
			if (left[i] < right[j])
			{
				ar[k] = left[i];
				i++;
			}
			else
			{
				ar[k] = right[j];
				j++;
			}
		}
		else if (i == n1)
		{
			ar[k] = right[j];
			j++;
		}
		else
		{
			ar[k] = left[i];
			i++;
		}
	}
	delete[] left;
	delete[] right;
}

void MergeSort(int* ar, int p, int r)
{
	if (p < r)
	{
		int q = (r + p) / 2;
		MergeSort(ar, p, q);
		MergeSort(ar, q + 1, r);
		Merge(ar, p, q, r);
	}
}
