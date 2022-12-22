/*����������� �������, ������� ������� �� ����� ��� ������������� ��������, ���� ����� ����.*/

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

	cout << "\n������� ���������� ���������, ������� ������ ������� � ����: ", cin >> kol;

	cout << "����: " << endl;
	while (i!=kol)
	{
		int a;
		a = rand() % 20 - 10;
		steck.push(a);
		i++;
		cout << a << " ";
	}
	cout << endl;
	cout << "���������� ��������� � �����: " << steck.size() << endl;

	i = 0;
	cout << "���� ����� �������� ������������� ���������: " << endl;
	while (i!=kol)
	{
		if (steck.top() >= 0) //������� �������
		{
			int a = steck.top();
			cout << a << " ";
			steck.pop();  // ������� ������� �������
		}

		else
		steck.pop();  // ������� ������� �������

		i++;
	}
	cout << endl << endl;
}