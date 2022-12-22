/*1. Скопировать из файла FILE1 в файл FILE2 все строки, кроме той строки,
в которой больше всего гласных букв. Напечатать номер этой строки.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");

   char mas[20] = { 'а','А','у','У','о','О','ы','Ы','и','И','э','Э','я','Я','ю','Ю','ё','Ё','е','Е'}; //массив всех гласных букв
   string str = "Строка_один\nстрока_два\nстрока_три\nстрока_четыре"; //строки в файле
	
	ofstream f1;
	f1.open("File1.txt"); //создание файла 

	if (!f1.is_open() )
	{
		cout << "Error!" << endl;
	}

	else
	{
		f1 << str << endl; //заполнение информацией файла
		
	}
	f1.close();

	ofstream f2;
	f1.open("File2.txt"); //создание второго файла

	if (!f1.is_open())
	{
		cout << "Error!" << endl;
	}
	f2.close();

	ifstream fin;
	fin.open("File1.txt"); //считывание информации из первого файла
	
	int kol = 0, save_kol = 0, sbu = 0, num = 0;

	if (!f1.is_open())
	{
		cout << "Error!" << endl;
	}

	else
	{
		char ch;
		while (fin.get(ch))   //посимвольное считывание файла
		{
			cout << ch;
			for (int j = 0; j < 100; j++)
			{
				if (ch == mas[j]) //проверка на гласные буквы
				{
					kol++; //подсчёт количества гласных
					break;
				}
			}

			if (ch == '\n') //поиск конца строки
			{
				sbu++;  //запись номера строки

				if (kol >= save_kol) //поиск строки с наибольшим количеством гласных
				{
					num = sbu; //номер строки с наибольшим количеством гласных
					save_kol = kol; // количество гласных в строке с наибольшим количеством гласных
				}

				kol = 0;
			}
		}
	}

	cout << "Наибольшее количество гласных в строке номер " << num << endl;
	fin.close();
	int count = 0, value = 0;

	for (int i = 0; i < 49; i++) //подсчет количества букв в строке с наибольшим количеством гласных
	{

		if (str[i] == '\n')
		{
			count++;
		}

		if (count == num - 1)
		{
			value++;
			
			if (str[i]=='\0')
			{
				break;
			}
		}

	}
	value -= 2;

	int sbf = 0, finish_sbu = 0;

	count = 0;

	for (int i = 0; i < 49; i++) //подсчёт начальной позиции строки с наибольшим количеством гласных
	{
		sbf++;

		if (str[i] == '\n')
		{
			count++;
		}

		if (count == num - 1)
		{
			finish_sbu = sbf;
			break;
		}
	}

	cout << "-----------------------------------" << endl;

	str.erase(finish_sbu, value); //удаление строки с наибольшим количеством гласных

	f2.open("File2.txt"); //запись данных во второй файл

	if (!f2.is_open())
	{
		cout << "Error!" << endl;
	}

	else
	{
		f2 << str;
		cout << "\nДанные записаны в файл!";
	}
	f2.close();

	
	cout << endl << endl;
		
}