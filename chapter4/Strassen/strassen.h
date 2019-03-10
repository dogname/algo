#ifndef __STRASSEN_H_
#define __STRASSEN_H_

typedef struct SubMaxtrix {
	int** Mat   = nullptr;
	int   i_beg = 0, j_beg = 0, n;
} SubMaxtrix;

void StranssenMatrix(const SubMaxtrix A, const SubMaxtrix B, SubMaxtrix C);

#endif  // __STRASSEN_H_
