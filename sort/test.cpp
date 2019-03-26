#include "sort.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

enum SortMethod
{
	Insert_Sort,
	Merge_Sort,
	Bubble_Sort,
	Heap_Sort
};

enum
{
	Sort_Success,
	Sort_Failure
};

static int TestSort(const int* ar, int n, SortMethod method)
{
	int* temp = new int[n];
	memcpy(temp, ar, n * sizeof(int));
	switch (method)
	{
	case Insert_Sort:
		InsertSort(temp, n);
		break;
	case Merge_Sort:
		MergeSort(temp, 0, n - 1);
		break;
	case Bubble_Sort:
		BubbleSort(temp, n);
		break;
	case Heap_Sort:
		HeapSort(temp, n);
		break;
	default:
		std::cout << "不存在的排序方式" << std::endl;
		return Sort_Failure;
	}
	for (int i = 1; i < n; ++i)
	{
		if (temp[i] < temp[i - 1])
		{
			std::cout << method << " failed " << std::endl;
			return Sort_Failure;
		}
	}
	std::cout << method << " success" << std::endl;
	delete[] temp;
	return Sort_Success;
}

int main()
{
	const int test_size = 50;
	int Array_Init[test_size];
	srand(time(NULL));
	for (int i = 0; i < test_size; ++i)
	{
		Array_Init[i] = rand() % 100;
	}
	TestSort(Array_Init, test_size, Insert_Sort);
	TestSort(Array_Init, test_size, Merge_Sort);
	TestSort(Array_Init, test_size, Bubble_Sort);
	TestSort(Array_Init, test_size, Heap_Sort);
	return 0;
}
