#include "sort.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

static const int test_size = 50;

static int Array_Init[test_size];

enum SortMethod { Insert_Sort, Merge_Sort, Bubble_Sort };

enum { Sort_Success, Sort_Failure };

static int TestSort(const int* ar, int n, SortMethod method)
{
	int temp[test_size];
	memcpy(temp, ar, test_size * sizeof(int));
	switch (method)
	{
	case Insert_Sort:
		InsertSort(temp, test_size);
		break;
	case Merge_Sort:
		MergeSort(temp, 0, test_size - 1);
		break;
	case Bubble_Sort:
		BubbleSort(temp, test_size);
		break;
	default:
		std::cout << "不存在的排序方式" << std::endl;
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
	return Sort_Success;
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < test_size; ++i) { Array_Init[i] = rand() % 100; }
	TestSort(Array_Init, test_size, Insert_Sort);
	TestSort(Array_Init, test_size, Merge_Sort);
	TestSort(Array_Init, test_size, Bubble_Sort);
	return 0;
}
