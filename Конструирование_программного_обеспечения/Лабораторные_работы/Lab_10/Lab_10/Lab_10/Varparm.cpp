#include <iostream>
#include "Varparm.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int a = Varparm::ivarparm(3, 5, 2, 2); //произведение значений всех параметров
	cout << a << endl;

	int b = Varparm::svarparm(3, 25, 115, 50); //максимальное значение параметров
	cout << b << endl;

	float c = Varparm::fvarparm(1.5, 25.0, 5.0, 10.0, FLT_MAX); //сумму значений всех параметров
	cout << c << endl;

	double d = Varparm::dvarparm(25.2, 5.2, 10.0, DBL_MAX); //сумму значений всех параметров
	cout << d << endl;

}