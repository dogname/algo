#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y;
} Point;

double distance(Point* pots, int i, int j)
{
	return sqrt((double)pow(pots[i].x - pots[j].x, 2) + pow(pots[i].y - pots[j].y, 2));
}

double minBitonicPath(Point* pots, int n, int*** pre)
{
	if (n < 2) return 0;
	double** length = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < n; ++i) length[i] = (double*)malloc(sizeof(double) * (i + 1));
	*pre = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; ++i) (*pre)[i] = (int*)malloc(sizeof(int) * (i + 1));
	length[1][0] = distance(pots, 1, 0);
	pre[1]       = 0;
	for (int i = 2; i < n; ++i)
	{
		for (int j = 0; j < i - 1; ++j)
		{
			length[i][j] = length[i - 1][j] + distance(pots, i, i - 1);
			printf("length[%d][%d]=%lf ", i, j, length[i][j]);
			(*pre)[i][j] = i - 1;
		}
		length[i][i - 1] = 1.0 / 0.0;
		for (int k = 0; k < i - 1; ++k)
		{
			double q = length[i - 1][k] + distance(pots, k, i);
			if (q < length[i][i - 1])
			{
				length[i][i - 1] = q;
				(*pre)[i][i - 1] = k;
			}
		}
		printf("length[%d][%d]=%lf ", i, i - 1, length[i][i - 1]);
		printf("\n");
	}
	double ret           = length[n - 1][n - 2] + distance(pots, n - 1, n - 2);
	(*pre)[n - 1][n - 1] = n - 2;
	for (int i = 0; i < n; ++i) free(length[i]);
	free(length);
	return ret;
}
void printPath(int** pre, int i, int j)
{
	if (i >= j)
	{
		if (i == 1 || j == 0) return;
		printf("%d ", pre[i][j]);
		printPath(pre, j, pre[i][j]);
	}
	else
	{
		printPath(pre, j, i);
	}
}
int main(void)
{
	double length;
	int** pre;
	Point pots[7] = {{0, 6}, {1, 0}, {2, 3}, {5, 4}, {6, 1}, {7, 5}, {8, 2}};
	length        = minBitonicPath(pots, 7, &pre);
	printf("length=%lf\n", length);
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("pre[%d][%d]=%d ", i, j, pre[i][j]);
		}
		printf("\n");
	}
	printPath(pre, 6, 6);
	printf("\n");
	return 0;
}
