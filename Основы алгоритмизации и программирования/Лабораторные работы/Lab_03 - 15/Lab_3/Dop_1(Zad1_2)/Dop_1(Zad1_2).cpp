/*2. ������ � ���������� ������ ��������, ��������� �� ���� � ����,
����������� ���������, � �������� �� � ����.
��������� �� ����� ������ � ������� �������� ����� ������. */

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str = " ";
	char new_str[50];

	ofstream file;
	file.open("My_file.txt");

	if (!file.is_open())
	{
		cout << "������! " << endl;
	}

	else
	{
		string str;
		cout << "������� ������(����� �������):" << endl;
		getline(cin, str);
		file << str;
		cout << "------------------------" << endl;
		cout << "���������� � ���� ��������! " << endl;
		cout << "------------------------" << endl;
	}

	file.close();

	ifstream fin;
	fin.open("My_file.txt");

	if (!fin.is_open())
	{
		cout << "������! " << endl;
	}

	else
	{
		while (!fin.eof())
		{
			str = " ";
			getline(fin, str);
		}
	}
	fin.close();

	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] % 2 != 0)
			{
				new_str[j] = str[i];
				j++;
			}
		}
	}

	new_str[j] = '\0';
	cout << "�������� ����� ������:" << endl;
	
	for (int i = 0; i < strlen(new_str); i++)
	{
		cout << new_str[i] << " ";

		if ((int)new_str == '\0')
		{
			break;
		}
	}
	cout << endl;	
}