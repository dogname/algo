#include "strassen.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	int        matrix_n = 8;
	SubMaxtrix A, B, C;
	A.Mat = new int*[matrix_n];
	B.Mat = new int*[matrix_n];
	C.Mat = new int*[matrix_n];
	for (int i = 0; i < matrix_n; i++)
	{
		A.Mat[i] = new int[matrix_n];
		B.Mat[i] = new int[matrix_n];
		C.Mat[i] = new int[matrix_n];
	}
	A.n = matrix_n;
	B.n = matrix_n;
	C.n = matrix_n;
	std::srand(time(0));
	for (int i = 0; i < matrix_n; i++)
		for (int j = 0; j < matrix_n; j++)
		{
			A.Mat[i][j] = std::rand() % 50 - 25;
			B.Mat[i][j] = std::rand() % 50 - 25;
		}
	for (int i = 0; i < matrix_n; i++)
	{
		for (int j = 0; j < matrix_n; j++)
		{
			std::cout << A.Mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < matrix_n; i++)
	{
		for (int j = 0; j < matrix_n; j++)
		{
			std::cout << B.Mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	StranssenMatrix(A, B, C);
	for (int i = 0; i < matrix_n; i++)
	{
		for (int j = 0; j < matrix_n; j++)
		{
			std::cout << C.Mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < matrix_n; i++)
	{
		delete[] A.Mat[i];
		delete[] B.Mat[i];
		delete[] C.Mat[i];
	}
	delete[] A.Mat;
	delete[] B.Mat;
	delete[] C.Mat;
	return 0;
}
