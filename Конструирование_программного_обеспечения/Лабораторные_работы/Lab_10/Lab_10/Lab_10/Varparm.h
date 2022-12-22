#pragma once

namespace Varparm {
	int ivarparm(int n, ...) { 
	
		int result = 1;
		// получаем указатель на параметр n
		for (int* ptr = &n; n > 0; n--)
		{
			result *= *(++ptr);
		}
		return result;
	}
	
	int svarparm(short n, ...)
	{
		int max = 0;

		// получаем указатель на параметр n
		for (int* ptr = (int*)(&n); n > 0; n--)
		{
			if ( *(++ptr) >= max)
			{
				max = *(ptr);
			}
		}
		return max;
	}
	
	float fvarparm(float n, ...)
	{
		double* ptr = (double*)(&n+1);
		int k = 0;
		float sum = n;
		while (ptr[k] != (double)FLT_MAX)
		{
			sum += *(ptr + k);
			k++;
		}
		return sum;
	}
	
	double dvarparm(double n, ...)
	{
		double* ptr = (double*)(&n + 1);
		int k = 0;
		float sum = n;
		while (ptr[k] != (double)DBL_MAX)
		{
			sum += *(ptr + k);
			k++;
		}
		return sum;
	}
}