#include "fmaxarray.h"

max_subarray find_max_subarray_exhaustive(int const* ar, int n)
{
	max_subarray result{0, 0, ar[0]};
	for (int i = 0; i < n; ++i)
	{
		int tmp = 0;
		for (int j = i; j < n; ++j)
		{
			tmp += ar[j];
			if (tmp > result.sum)
			{
				result.sum    = tmp;
				result.lindex = i;
				result.rindex = j;
			}
		}
	}
	return result;
}

max_subarray find_max_subarray_recursive_cross(int const* ar, int left, int mid, int right)
{
	max_subarray result;
	int          left_sum  = ar[mid];
	int          right_sum = ar[mid + 1];
	int          tmp       = 0;
	for (int i = mid; i >= left; i--)
	{
		tmp += ar[i];
		if (tmp > left_sum)
		{
			left_sum      = tmp;
			result.lindex = i;
		}
	}
	tmp = 0;
	for (int i = mid + 1; i < right; i++)
	{
		tmp += ar[j];
		if (tmp > right_sum)
		{
			right_sum     = tmp;
			result.rindex = i;
		}
	}
	result.sum = left_sum + right_sum;
	return result;
}

max_subarray find_max_subarray_recursive(int const* ar, int left, int right)
{
	max_subarray  resultl{left, left, ar[left]};
	max_subarray  resultr;
	max_subarray  resultc;
	max_subarray* result = &resultl;
	if (right == left)
		return *result;
	else
	{
		int mid = (left + right) / 2;
		resultl = find_max_subarray_recursive(ar, left, mid);
		resultr = find_max_subarray_recursive(ar, mid + 1, right);
		if (resultr.sum > result->sum)
		{
			result = &resultr;
		}
		resultc = find_max_subarray_recursive_cross(ar, left, mid, right);
		if (resultc.sum > result->sum)
		{
			result = &resultc;
		}
	}
	return *result;
}
