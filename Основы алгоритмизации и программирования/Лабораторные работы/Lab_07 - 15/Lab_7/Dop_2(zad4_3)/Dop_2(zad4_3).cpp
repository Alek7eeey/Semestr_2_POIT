/*Разработать функцию, которая удаляет все положительные элементы, если такой есть.*/

#include <iostream>
#include <stack>
#include <windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	stack<int>steck;
	int i = 0, kol = 0;

	cout << "Введите количество элементов, которые хотите занести в стек: ", cin >> kol;

	cout << "Стек: " << endl;
	while (i != kol)
	{
		int a;
		a = rand() % 20 - 10;
		steck.push(a);
		i++;
		cout << a << " ";
	}
	cout << endl;
	cout << "\nКоличество элементов в стеке: " << steck.size() << endl;

	i = 0;
	cout << "Стек после удаления отрицательных элементов: " << endl;
	while (i != kol)
	{
		if (steck.top() <= 0) //верхний элемент
		{
			int a = steck.top();
			cout << a << " ";
			steck.pop();  // удаляем верхний элемент
		}

		else
			steck.pop();  // удаляем верхний элемент

		i++;
	}
	cout << endl << endl;
}