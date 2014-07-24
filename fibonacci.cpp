#include "fibonacci.h"
#include <iostream>
#include <assert.h>



int 
fibonacci(int n)
{
	if (n <= 0)
	{
		return -1;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		int value1 = 1;
		int value2 = 1;
		int value;
		for (int i = 2; i < n; ++i)
		{	
			value = value1 + value2;
			value1 = value2;
			value2 = value;
		}

		return value;
	}
}


struct matrix2By2
{
	matrix2By2
	(long long m00, long long m01, long long m10, long long m11) : m00(m00), m01(m01), m10(m10), m11(m11) {}

	long long m00;
	long long m01;
	long long m10;
	long long m11;
};


matrix2By2 matrixMul(matrix2By2& mat1, matrix2By2& mat2)
{
	return matrix2By2
		(
		mat1.m00 * mat2.m00 + mat1.m01 * mat2.m10,
		mat1.m00 * mat2.m01 + mat1.m01 * mat2.m11,
		mat1.m10 * mat2.m00 + mat1.m11 * mat2.m10,
		mat1.m10 * mat2.m01 + mat1.m11 * mat2.m11
		);
}

matrix2By2 matrixPow(matrix2By2& mat, long long n)
{
	assert(n > 0);

	if (n == 1)
		return mat;

	if (n == 2)
		return matrixMul(mat, mat);

	if (n % 2 == 0)
		return matrixPow(matrixPow(mat, n / 2), 2);

	if (n % 2 == 1)
		return matrixMul(mat, matrixPow(matrixPow(mat, n / 2), 2));
}