/*2. Ввести с клавиатуры строку символов, состоящую из букв,
цифр, запятых, точек, знаков + и -,и записать ее в файл. 
Прочитать из файла данные и вывести подстроку,
которая соответствует записи вещественного числа с фиксированной точкой.*/
             
#include <string>    
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iterator>
 
using namespace std;

void main()
{
	setlocale(LC_ALL,"Rus");
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str = " ";

	ofstream file;
	file.open("My_file.txt");
	
	if (!file.is_open())
	{
		cout << "Ошибка! " << endl;
	}

	else
	{
		string str;
		cout << "Введите строки :" << endl;
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

	int st = 0;
	string::iterator i, b; /*Итератор — это объект, разработанный специально для перебора элементов контейнера*/

	for (i = str.begin(); i != str.end() && st != 5; ++i)
	{
		switch (st)
		{
		case 0:
			if (*i == '+' || *i == '-')
			{
				st = 1;
				b = i;
			}
			else if (isdigit(*i)) /*Функция isdigit проверяет аргумент, передаваемый через параметр сharacter, является ли он десятичной цифрой.*/
			{
				st = 2;
				b = i;
			}
			break;

		case 1:
			if (isdigit(*i)) 
				st = 2;
			else 
				st = 0;
			break;

		case 2:
			if (*i == '.') 
				st = 3;
			else if
				(!isdigit(*i)) 
				st = 0;
			break;

		case 3:
			if (isdigit(*i)) 
				st = 4;
			else 
				st = 0;
			break;

		case 4:
			if (!isdigit(*i)) 
				st = 5;
		}
	}

	if (st == 5 || (st == 4 && i == str.end()))
	{
		cout << "Вещественное число с фиксированной точкой: ";
		copy(b, i-1, ostream_iterator<char>(cout, ""));  //ostream_iterator - это итератор вывода. Он применяется для вывода элементов.
	}                                      //b и i - это диапазон ячеек к которым будут выполнятся операции.
	
	cout << endl;
}
