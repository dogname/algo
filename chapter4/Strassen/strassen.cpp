#include "strassen.h"

void StranssenMatrix(SubMaxtrix A, SubMaxtrix B, SubMaxtrix C)
{
	int n = A.i_end - A.i_beg + 1;
	if (n == 1)
		C.Mat[C.i_beg][C.j_beg] = A.Mat[A.i_beg][A.j_beg] * B.Mat[B.i_beg][B.j_beg];
	else
	{
		SubMaxtrix A11, A12, A21, A22, B11, B12, B21, B22, C11, C12, C21, C22;

		A11.Mat   = A.Mat;
		A11.i_beg = A.i_beg;
		A11.j_beg = A.j_beg;
		A11.i_end = (A.i_beg + A.i_end) / 2;
		A11.j_end = (A.j_beg + A.j_end) / 2;

		A12.Mat   = A.Mat;
		A11.i_beg = A.i_beg;
		A12.j_beg = (A.j_beg + A.j_end) / 2 + 1;
		A12.i_end = (A.i_beg + A.i_end) / 2;
		A12.j_end = A.j_end;

		A21.Mat   = A.Mat;
		A21.i_beg = (A.i_beg + A.i_end) / 2 + 1;
		A21.j_beg = A.j_beg;
		A21.i_end = A.i_end;
		A21.j_end = (A.j_beg + A.j_end) / 2;

		A22.Mat   = A.Mat;
		A22.i_beg = (A.i_beg + A.i_end) / 2 + 1;
		A22.j_beg = (A.j_beg + A.j_end) / 2 + 1;
		A22.i_end = A.i_end;
		A22.j_end = A.j_end;

		B11.Mat   = B.Mat;
		B11.i_beg = B.i_beg;
		B11.j_beg = B.j_beg;
		B11.i_end = (B.i_beg + B.i_end) / 2;
		B11.j_end = (B.j_beg + B.j_end) / 2;

		B12.Mat   = B.Mat;
		B11.i_beg = B.i_beg;
		B12.j_beg = (B.j_beg + B.j_end) / 2 + 1;
		B12.i_end = (B.i_beg + B.i_end) / 2;
		B12.j_end = B.j_end;

		B21.Mat   = B.Mat;
		B21.i_beg = (B.i_beg + B.i_end) / 2 + 1;
		B21.j_beg = B.j_beg;
		B21.i_end = B.i_end;
		B21.j_end = (B.j_beg + B.j_end) / 2;

		B22.Mat   = B.Mat;
		B22.i_beg = (B.i_beg + B.i_end) / 2 + 1;
		B22.j_beg = (B.j_beg + B.j_end) / 2 + 1;
		B22.i_end = B.i_end;
		B22.j_end = B.j_end;

		C11.Mat   = C.Mat;
		C11.i_beg = C.i_beg;
		C11.j_beg = C.j_beg;
		C11.i_end = (C.i_beg + C.i_end) / 2;
		C11.j_end = (C.j_beg + C.j_end) / 2;

		C12.Mat   = C.Mat;
		C11.i_beg = C.i_beg;
		C12.j_beg = (C.j_beg + C.j_end) / 2 + 1;
		C12.i_end = (C.i_beg + C.i_end) / 2;
		C12.j_end = C.j_end;

		C21.Mat   = C.Mat;
		C21.i_beg = (C.i_beg + C.i_end) / 2 + 1;
		C21.j_beg = C.j_beg;
		C21.i_end = C.i_end;
		C21.j_end = (C.j_beg + C.j_end) / 2;

		C22.Mat   = C.Mat;
		C22.i_beg = (C.i_beg + C.i_end) / 2 + 1;
		C22.j_beg = (C.j_beg + C.j_end) / 2 + 1;
		C22.i_end = C.i_end;
		C22.j_end = C.j_end;

		SubMaxtrix s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
		s1.Mat    = new int*[n / 2];
		s1.i_end  = n / 2 - 1;
		s1.j_end  = n / 2 - 1;
		s2.Mat    = new int*[n / 2];
		s2.i_end  = n / 2 - 1;
		s2.j_end  = n / 2 - 1;
		s3.Mat    = new int*[n / 2];
		s3.i_end  = n / 2 - 1;
		s3.j_end  = n / 2 - 1;
		s4.Mat    = new int*[n / 2];
		s4.i_end  = n / 2 - 1;
		s4.j_end  = n / 2 - 1;
		s5.Mat    = new int*[n / 2];
		s5.i_end  = n / 2 - 1;
		s5.j_end  = n / 2 - 1;
		s6.Mat    = new int*[n / 2];
		s6.i_end  = n / 2 - 1;
		s6.j_end  = n / 2 - 1;
		s7.Mat    = new int*[n / 2];
		s7.i_end  = n / 2 - 1;
		s7.j_end  = n / 2 - 1;
		s8.Mat    = new int*[n / 2];
		s8.i_end  = n / 2 - 1;
		s8.j_end  = n / 2 - 1;
		s9.Mat    = new int*[n / 2];
		s9.i_end  = n / 2 - 1;
		s9.j_end  = n / 2 - 1;
		s10.Mat   = new int*[n / 2];
		s10.i_end = n / 2 - 1;
		s10.j_end = n / 2 - 1;
		for (int i = 0; i < n / 2; i++)
		{
			s1.Mat[i]  = new int[n / 2];
			s2.Mat[i]  = new int[n / 2];
			s3.Mat[i]  = new int[n / 2];
			s4.Mat[i]  = new int[n / 2];
			s5.Mat[i]  = new int[n / 2];
			s6.Mat[i]  = new int[n / 2];
			s7.Mat[i]  = new int[n / 2];
			s8.Mat[i]  = new int[n / 2];
			s9.Mat[i]  = new int[n / 2];
			s10.Mat[i] = new int[n / 2];
		}
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++)
			{
				s1.Mat[i][j]  = B12.Mat[B12.i_beg + i][B12.j_beg + j] - B21.Mat[B21.i_beg + i][B21.j_beg + j];
				s2.Mat[i][j]  = A11.Mat[A11.i_beg + i][A11.j_beg + j] + A12.Mat[A12.i_beg + i][A12.j_beg + j];
				s3.Mat[i][j]  = A21.Mat[A21.i_beg + i][A21.j_beg + j] + A22.Mat[A22.i_beg + i][A22.j_beg + j];
				s4.Mat[i][j]  = B21.Mat[B21.i_beg + i][B21.j_beg + j] - B11.Mat[B11.i_beg + i][B11.j_beg + j];
				s5.Mat[i][j]  = A11.Mat[A11.i_beg + i][A11.j_beg + j] + A22.Mat[A22.i_beg + i][A22.j_beg + j];
				s6.Mat[i][j]  = B11.Mat[B11.i_beg + i][B11.j_beg + j] + B22.Mat[B22.i_beg + i][B22.j_beg + j];
				s7.Mat[i][j]  = A12.Mat[A12.i_beg + i][A12.j_beg + j] - A21.Mat[A21.i_beg + i][A21.j_beg + j];
				s8.Mat[i][j]  = B21.Mat[B21.i_beg + i][B21.j_beg + j] + B22.Mat[B22.i_beg + i][B22.j_beg + j];
				s9.Mat[i][j]  = A11.Mat[A11.i_beg + i][A11.j_beg + j] - A21.Mat[A21.i_beg + i][A21.j_beg + j];
				s10.Mat[i][j] = B11.Mat[B11.i_beg + i][B11.j_beg + j] + B12.Mat[B12.i_beg + i][B12.j_beg + j];
			}
		SubMaxtrix p1, p2, p3, p4, p5, p6, p7;
		p1.Mat   = new int*[n / 2];
		p1.i_end = n / 2 - 1;
		p1.j_end = n / 2 - 1;
		p2.Mat   = new int*[n / 2];
		p2.i_end = n / 2 - 1;
		p2.j_end = n / 2 - 1;
		p3.Mat   = new int*[n / 2];
		p3.i_end = n / 2 - 1;
		p3.j_end = n / 2 - 1;
		p4.Mat   = new int*[n / 2];
		p4.i_end = n / 2 - 1;
		p4.j_end = n / 2 - 1;
		p5.Mat   = new int*[n / 2];
		p5.i_end = n / 2 - 1;
		p5.j_end = n / 2 - 1;
		p6.Mat   = new int*[n / 2];
		p6.i_end = n / 2 - 1;
		p6.j_end = n / 2 - 1;
		p7.Mat   = new int*[n / 2];
		p7.i_end = n / 2 - 1;
		p7.j_end = n / 2 - 1;
		for (int i = 0; i < n / 2; i++)
		{
			p1.Mat[i] = new int[n / 2];
			p2.Mat[i] = new int[n / 2];
			p3.Mat[i] = new int[n / 2];
			p4.Mat[i] = new int[n / 2];
			p5.Mat[i] = new int[n / 2];
			p6.Mat[i] = new int[n / 2];
			p7.Mat[i] = new int[n / 2];
		}
		StranssenMatrix(A11, s1, p1);
		StranssenMatrix(s2, B22, p2);
		StranssenMatrix(s3, B11, p3);
		StranssenMatrix(A22, s4, p4);
		StranssenMatrix(s5, s6, p5);
		StranssenMatrix(s7, s8, p6);
		StranssenMatrix(s9, s10, p7);
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++)
			{
				C11.Mat[C11.i_beg + i][C11.j_beg + j] = p5.Mat[i][j] + p4.Mat[i][j] - p2.Mat[i][j] + p6.Mat[i][j];
				C12.Mat[C12.i_beg + i][C12.j_beg + j] = p1.Mat[i][j] + p2.Mat[i][j];
				C21.Mat[C21.i_beg + i][C21.j_beg + j] = p3.Mat[i][j] + p4.Mat[i][j];
				C22.Mat[C22.i_beg + i][C22.j_beg + j] = p5.Mat[i][j] + p1.Mat[i][j] - p3.Mat[i][j] - p7.Mat[i][j];
			}
		for (int i = 0; i < n / 2; i++)
		{
			delete[] s1.Mat[i];
			delete[] s2.Mat[i];
			delete[] s3.Mat[i];
			delete[] s4.Mat[i];
			delete[] s5.Mat[i];
			delete[] s6.Mat[i];
			delete[] s7.Mat[i];
			delete[] s8.Mat[i];
			delete[] s9.Mat[i];
			delete[] s10.Mat[i];
			delete[] p1.Mat[i];
			delete[] p2.Mat[i];
			delete[] p3.Mat[i];
			delete[] p4.Mat[i];
			delete[] p5.Mat[i];
			delete[] p6.Mat[i];
			delete[] p7.Mat[i];
		}
		delete[] s1.Mat;
		delete[] s2.Mat;
		delete[] s3.Mat;
		delete[] s4.Mat;
		delete[] s5.Mat;
		delete[] s6.Mat;
		delete[] s7.Mat;
		delete[] s8.Mat;
		delete[] s9.Mat;
		delete[] s10.Mat;
		delete[] p1.Mat;
		delete[] p2.Mat;
		delete[] p3.Mat;
		delete[] p4.Mat;
		delete[] p5.Mat;
		delete[] p6.Mat;
		delete[] p7.Mat;
	}
}