#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int foo()
{
	cout << "Функция вызвана! " << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;
	int X = 9 + n;
	int Y = 10 + n;
	int Z = 11 + n;
	float S = 1.0 + n;

	char size[16];

	bool f_bool_val = true;
	bool s_bool_val = false;

	char lat = 'K';
	char rus = 'К';

	wchar_t  lat_t = 'K';
	wchar_t  rus_t = 'К';

	short f_short_val = X;
	short s_short_val = -X;

	int f_int_val = Y;
	int s_int_val = -Y;

	long f_long_val = Z;
	long s_long_val = -Z;

	float f_float_val = S;
	float s_float_val = -S;

	char* f_pnt_char = &lat;
	char* s_pnt_char = &rus;

	wchar_t* f_pnt_wchar = &lat_t;
	wchar_t* s_pnt_wchar = &rus_t;

	short* f_pnt_short = &f_short_val;
	short* s_pnt_short = &s_short_val;

	int* f_pnt_val = &f_int_val;
	int* s_pnt_val = &s_int_val;

	long* f_pnt_long = &f_long_val;
	long* s_pnt_long = &s_long_val;

	float* f_pnt_float = &f_float_val;
	float* s_pnt_float = &s_float_val;

	float f1 = f_float_val / 0; //неопределенности 
	float f2 = s_float_val / 0;
	float f3 = sqrt(s_float_val);

	short max_short_val = SHRT_MAX;
	short min_short_val = SHRT_MIN;

	unsigned short max_ushort_val = USHRT_MAX;
	unsigned short min_ushort_val = 0;

	long max_long_val = LONG_MAX;
	long min_long_val = LONG_MIN;

	unsigned long max_ulong_val = ULONG_MAX;
	unsigned long min_ulong_val = 0;

	_itoa_s(max_short_val, size, 16);
	cout << size << endl;
	_itoa_s(min_short_val, size, 16);
	cout << size << endl;
	_itoa_s(max_ushort_val, size, 16);
	cout << size << endl;
	_itoa_s(max_long_val, size, 16);
	cout << size << endl;
	_itoa_s(min_long_val, size, 16);
	cout << size << endl;
	_itoa_s(max_ulong_val, size, 16);
	cout << size << endl;

	int (*pft)()=foo;
	pft();
}


