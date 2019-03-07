#ifndef __FMAXARRAY_H_
#define __FMAXARRAY_H_

typedef struct {
	int lindex;
	int rindex;
	int sum;
} max_subarray;

max_subarray find_max_subarray_exhaustive(const int* ar, int n);

max_subarray find_max_subarray_recursive_cross(const int* ar, int left, int mid, int right);

max_subarray find_max_subarray_recursive(const int* ar, int left, int right);

max_subarray find_max_subarray_dynamic(const int* ar, int n);

#endif
