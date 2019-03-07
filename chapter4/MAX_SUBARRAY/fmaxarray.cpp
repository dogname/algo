#include "fmaxarray.h"

max_subarray find_max_subarray_exhaustive(const int* ar, int n)
{
	max_subarray result = {0, 0, ar[0]};
	for (int i = 0; i < n; ++i)
	{
		int tmp = 0;
		for (int j = i; j < n; ++j)
		{
			tmp += ar[j];
			if (tmp > result.sum)
			{
				result.sum = tmp;
				result.lindex = i;
				result.rindex = j;
			}
		}
	}
	return result;
}

max_subarray find_max_subarray_recursive_cross(const int* ar, int left, int mid, int right)
{
	int a = ar[mid];
	max_subarray result = {mid, mid + 1, a};
	int left_sum = ar[mid];
	int right_sum = ar[mid + 1];
	int tmp = 0;
	for (int i = mid; i >= left; i--)
	{
		tmp += ar[i];
		if (tmp > left_sum)
		{
			left_sum = tmp;
			result.lindex = i;
		}
	}
	tmp = 0;
	for (int i = mid + 1; i <= right; i++)
	{
		tmp += ar[i];
		if (tmp > right_sum)
		{
			right_sum = tmp;
			result.rindex = i;
		}
	}
	result.sum = left_sum + right_sum;
	return result;
}

max_subarray find_max_subarray_recursive(const int* ar, int left, int right)
{
	max_subarray resultl = {left, left, ar[left]};
	max_subarray resultr;
	max_subarray resultc;
	max_subarray* result = &resultl;
	if (right == left)
		return *result;
	else
	{
		int mid = (left + right) / 2;
		resultl = find_max_subarray_recursive(ar, left, mid);
		resultr = find_max_subarray_recursive(ar, mid + 1, right);
		resultc = find_max_subarray_recursive_cross(ar, left, mid, right);
	}
	if (resultl.sum >= resultr.sum && resultl.sum >= resultc.sum)
		result = &resultl;
	else if (resultr.sum >= resultc.sum)
		result = &resultr;
	else
		result = &resultc;
	return *result;
}

max_subarray find_max_subarray_dynamic(const int* ar, int n)
{
	max_subarray* result = new max_subarray[n];

	result->lindex = 0;
	result->rindex = 0;
	result->sum = ar[0];

	for (int i = 1; i < n; i++)
	{
		if (result[i - 1].sum < 0)
		{
			result[i].lindex = i;
			result[i].rindex = i;
			result[i].sum = ar[i];
		}
		else
		{
			result[i].lindex = result[i - 1].lindex;
			result[i].rindex = i;
			result[i].sum = result[i - 1].sum + ar[i];
		}
	}
	max_subarray max = result[0];
	for (int i = 1; i < n; i++)
	{
		if (result[i].sum > max.sum)
			max = result[i];
	}
	delete[] result;
	return max;
}