#include "sort.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

static int Array_Init[50];

enum SortMethod
{
	Insert_Sort,
	Merge_Sort
};

enum
{
	Sort_Success,
	Sort_Failure
};

static int TestSort(const int* ar, int n, SortMethod method)
{
	int temp[50];
	memcpy(temp, ar, 50 * sizeof(int));
	switch (method)
	{
	case Insert_Sort:
		InsertSort(temp, 50);
	case Merge_Sort:
		MergeSort(temp, 50);
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
	for (int i = 0; i < 50; ++i)
	{
		Array_Init[i] = rand() % 100;
	}
	TestSort(Array_Init, 50, Insert_Sort);
	TestSort(Array_Init, 50, Merge_Sort);
	return 0;
}
