#include "strassen.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	SubMaxtrix A, B, C;
	A.Mat = new int*[4];
	B.Mat = new int*[4];
	C.Mat = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		A.Mat[i] = new int[4];
		B.Mat[i] = new int[4];
		C.Mat[i] = new int[4];
	}
	A.i_end = 3;
	A.j_end = 3;
	B.i_end = 3;
	B.j_end = 3;
	C.i_end = 3;
	C.j_end = 3;
	std::srand(time(0));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			A.Mat[i][j] = std::rand() % 50 - 25;
			B.Mat[i][j] = std::rand() % 50 - 25;
		}
	StranssenMatrix(A, B, C);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << A.Mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << B.Mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << C.Mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < 4; i++)
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