/*
������� sinx+sin2x+sin3x+...+sinnx;
*/

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int i = 1;
double PI = 3.14;

void foo(int n, double x, double *sum)
{
	while (i<n)
	{
		*sum += sin((x*i)* PI / 180);
		++i;
		foo(n, x, sum);
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	double x;
	int n;

	cout << "������� n: ", cin >> n;
	cout << "\n������� x(� �����c��): ", cin >> x;
	foo(n, x, &sum);

	cout << "���� ������� ����� = "<< sum << endl<<endl;

}