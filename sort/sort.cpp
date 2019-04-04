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

void BubbleSort(int* ar, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (ar[j] < ar[j - 1])
			{
				temp = ar[j];
				ar[j] = ar[j - 1];
				ar[j - 1] = temp;
			}
		}
	}
}

void MaxHeapIfy(int* ar, int i, int n)
{
	int l = LeftChild(i);
	int r = RightChild(i);
	int largest = i;
	if (l < n && ar[l] > ar[i])
		largest = l;
	if (r < n && ar[r] > ar[largest])
		largest = r;
	if (largest != i)
	{
		int temp = ar[i];
		ar[i] = ar[largest];
		ar[largest] = temp;
		MaxHeapIfy(ar, largest, n);
	}
}

void BuildMaxHeap(int* ar, int n)
{
	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		MaxHeapIfy(ar, i, n);
	}
}

void HeapSort(int* ar, int n)
{
	BuildMaxHeap(ar, n);
	for (int i = n - 1; i > 0; i--)
	{
		int temp = ar[i];
		ar[i] = ar[0];
		ar[0] = temp;
		MaxHeapIfy(ar, 0, i);
	}
}

int Partition(int* ar, int n)
{
	int key = ar[n - 1];
	int temp;
	int i = -1;
	for (int j = 0; j < n - 1; j++)
	{
		if (ar[j] <= key)
		{
			i++;
			temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;
		}
	}
	temp = ar[i + 1];
	ar[i + 1] = key;
	ar[n - 1] = temp;
	return i + 1;
}

void QuickSort(int* ar, int n)
{
	if (n > 1)
	{
		int offset = Partition(ar, n);
		QuickSort(ar, offset);
		QuickSort(&ar[offset], n - offset);
	}
}
