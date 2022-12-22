//Разработать программу,
//реализующую рекурсивный алгоритм для вычисления значений полиномов.

#include <iostream>
#include <windows.h>
using namespace std;

int sum(int n, int x) {

	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 2*x;
	}
	if (n>1)
	{
		return 2 * n / (n - 1) * sum(n - 1, x) + n - 1 / (2 * n) * sum(n - 2, x);
	}

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x, n;
	cout << "Введите значение x: ", cin >> x;
	cout << "Введите значение n: ", cin >> n;
	cout << " sum = " << sum(n, x) << endl;
}
