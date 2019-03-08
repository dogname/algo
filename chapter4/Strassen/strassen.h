#ifndef __STRASSEN_H_
#define __STRASSEN_H_

typedef struct SubMaxtrix {
	int** Mat;
	int   i_beg = 0, i_end, j_beg = 0, j_end;
} SubMaxtrix;

void StranssenMatrix(SubMaxtrix A, SubMaxtrix B, SubMaxtrix C);

#endif  // __STRASSEN_H_
