#ifndef __FMAXARRAY_H_
#define __FMAXARRAY_H_

typedef struct {
	int lindex;
	int rindex;
	int sum;
} max_subarray;

max_subarray find_max_subarray_exhaustive(int* const ar, int n);

max_subarray find_max_subarray_recursive_cross(int const* ar, int left, int mid, int right);

max_subarray find_max_subarray_recursive(int const* ar, int left, int right);

max_subarray find_max_subarray_line(int* const ar, int n);

#endif
