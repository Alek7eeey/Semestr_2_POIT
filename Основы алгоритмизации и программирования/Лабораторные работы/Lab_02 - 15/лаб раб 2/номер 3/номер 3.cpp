// номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
void main()
{
	double d, f, i = -6, x = 4.5, z = 1.5e-6;
	d = tan(-x * i) / sqrt(x - z);
	f = sin(2 * d) / d;


	std::cout << "d=" << d << "\n";
	std::cout << "f=" << f;

}

