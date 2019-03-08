#include "fmaxarray.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

enum Method
{
	Recursive_Find,
	Dynamic_Find
};

bool TestFind(int const* ar, int n, Method mth, max_subarray check)
{
	max_subarray result;
	double t;
	std::clock_t start, end;
	switch (mth)
	{
	case Recursive_Find:
		start = std::clock();
		result = find_max_subarray_recursive(ar, 0, n - 1);
		end = std::clock();
		t = end - start;
		std::cout << "递归时间" << t / CLOCKS_PER_SEC << std::endl;
		break;
	case Dynamic_Find:
		start = std::clock();
		result = find_max_subarray_dynamic(ar, n);
		end = std::clock();
		t = end - start;
		std::cout << "动态归化时间" << t / CLOCKS_PER_SEC << std::endl;
		break;
	default:
		break;
	}
	if (result.sum != check.sum)
	{
		std::cout << mth << " failed, the sum is error" << std::endl;
		return false;
	}
	int sum = 0;
	for (int i = result.lindex; i <= result.rindex; ++i)
	{
		sum += ar[i];
	}
	if (check.sum != sum)
	{
		std::cout << mth << " failed, the indexs are error" << std::endl;
		std::cout << "(" << result.lindex << "," << result.rindex << ")" << std::endl;
		return false;
	}
	std::cout << mth << " success\n";
	return true;
}

int main()
{
	const int test_size = 500;
	int A[test_size];
	double t;
	clock_t start, end;
	std::srand(std::time(0));
	for (int i = 0; i < test_size; i++)
	{
		A[i] = std::rand() % 100 - 50;
	}
	max_subarray check;
	start = std::clock();
	check = find_max_subarray_exhaustive(A, test_size);
	end = std::clock();
	t = end - start;
	std::cout << "穷举时间" << t / CLOCKS_PER_SEC << std::endl;
	TestFind(A, test_size, Recursive_Find, check);
	TestFind(A, test_size, Dynamic_Find, check);
	return 0;
}
