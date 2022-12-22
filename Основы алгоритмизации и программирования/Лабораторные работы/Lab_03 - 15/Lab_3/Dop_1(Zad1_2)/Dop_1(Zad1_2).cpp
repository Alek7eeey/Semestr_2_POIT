/*2. Ввести с клавиатуры строку символов, состоящую из цифр и слов,
разделенных пробелами, и записать ее в файл.
Прочитать из файла данные и вывести нечетные числа строки. */

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
		cout << "Ошибка! " << endl;
	}

	else
	{
		string str;
		cout << "Введите строки(через пробелы):" << endl;
		getline(cin, str);
		file << str;
		cout << "------------------------" << endl;
		cout << "Информация в файл записана! " << endl;
		cout << "------------------------" << endl;
	}

	file.close();

	ifstream fin;
	fin.open("My_file.txt");

	if (!fin.is_open())
	{
		cout << "Ошибка! " << endl;
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
	cout << "Нечётные числа строки:" << endl;
	
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