#ifndef __SORT_H_
#define __SORT_H_

void InsertSort(int* ar, int n);

void Merge(int* ar, int p, int q, int r);

void MergeSort(int* ar, int p, int r);

void BubbleSort(int* ar, int n);

inline int LeftChild(int i)
{
	return 2 * i + 1;
}
inline int RightChild(int i)
{
	return 2 * i + 2;
}

void MaxHeapIfy(int* ar, int i, int n);

void BuildMaxHeap(int* ar, int n);

void HeapSort(int* ar, int n);

#endif  // __SORT_H_
