#pragma once

namespace call {
	
	int _cdecl cdevl(int a, int b, int c); //Параметры помещаются в стек в обратном порядке (справа налево)
	
	int _stdcall cstd(int& a_ref, int b, int c); //Параметры помещаются в стек в обратном порядке (справа налево)

	int _fastcall cfst(int a, int b, int c, int d); //Хранятся в регистрах, затем помещаются в стек
	
}
