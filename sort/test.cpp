#include "sort.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

static int Array_Init[50];

enum SortMethod { Insert_Sort, Merge_Sort };

enum { Sort_Success, Sort_Failure };

static int TestSort(const int* ar, int n, SortMethod method)
{
	for (size_t i = 1; i < n; ++i)
	{
		if (ar[i] < ar[i - 1])
		{
			std::cout << method << " failed " << std::endl;
			return Sort_Failure;
		}
	}
	return Sort_Success;
}

int main()
{
	srand(time(NULL));
	for (size_t i = 0; i < 50; ++i) { Array_Init[i] = rand() % 100; }
	InsertSort(Array_Init, 50);
	TestSort(Array_Init, 50, Insert_Sort);
	return 0;
}
