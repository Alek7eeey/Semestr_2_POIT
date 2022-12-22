/*Написать функцию fmin с переменным числом параметров,
в которой определяется минимальное из чисел типа int. */

#include <iostream>
using namespace std;

int fmin(int, ...); //прототип

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	
	cout << "Первое обращение: " << fmin(3, rand() % 100, rand() % 100, rand() % 100) << endl;
	cout << "Второе образение: " << fmin(2, rand() % 100, rand() % 100) << endl;
	cout << "Третье обращение: " << fmin(5, rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100) << endl;

	return 0;
}

int fmin(int amount, ...)
{
	int min;
	int* num = &amount + 1;
	
	for (int i = 0; i < amount; i++)
	{
		if (i == 0)
		{
			min = *num;
		}

		if (min > *num)
		{
			min = *num;
		}
	}
	return min;
}