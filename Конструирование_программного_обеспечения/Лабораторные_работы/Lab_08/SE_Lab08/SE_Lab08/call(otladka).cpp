#include <iostream>
#include <windows.h>
#include "Call.h"
using namespace std;

namespace call {
	int _cdecl cdevl(int a, int b, int c) //Параметры помещаются в стек в обратном порядке (справа налево)
	{
		return a + b + c;
	}

	int _stdcall cstd(int& a_ref, int b, int c) //Параметры помещаются в стек в обратном порядке (справа налево)
	{
		return a_ref * b * c;
	}

	int _fastcall cfst(int a, int b, int c, int d) //Хранятся в регистрах, затем помещаются в стек
	{
		return a + b + c + d;
	}
}

void main()
{ 
	int a = 5;

	int result_1 = call::cdevl(1, 3, 5);

	int result_2 = call::cstd(a, 3, 5);

	int result_3 = call::cfst(1, 3, 5, -4);


}