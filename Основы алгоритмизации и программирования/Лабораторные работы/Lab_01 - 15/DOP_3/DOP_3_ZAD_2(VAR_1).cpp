/*�������� ������� fmin � ���������� ������ ����������,
� ������� ������������ ����������� �� ����� ���� int. */

#include <iostream>
using namespace std;

int fmin(int, ...); //��������

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	
	cout << "������ ���������: " << fmin(3, rand() % 100, rand() % 100, rand() % 100) << endl;
	cout << "������ ���������: " << fmin(2, rand() % 100, rand() % 100) << endl;
	cout << "������ ���������: " << fmin(5, rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100) << endl;

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