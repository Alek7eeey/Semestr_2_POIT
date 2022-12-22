/*Создать список, содержащий элементы целого типа. 
Найти сумму отрицательных элементов, кратных 2, или выдать сообщение, что таких элементов нет. */

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;

struct list
{
	int number;
	list* next;
};

bool isProved(string num)
{
	char nums[] = "0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == '-')
		{
			continue;
		}
		for (int j = 0; j < 10; j++)
		{
			if (num[i] == nums[j])
			{
				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}

void insert(list* &, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void sum(list*);  //функция подсчета суммы чисел
void toFile(list*& p);
void fromFile(list*& p);

string inf = "information.txt";

void main()
{ 
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list* first = NULL;
	int choice;
	int value;
	string s_value = " ", s_choice = " ";
	menu();    // вывести меню 
	cout << "--> ";
	
	cin >> s_choice;
	cin.ignore();
	while (!isProved(s_choice))
	{
		cout << "Выберите пункт меню верно: ";
		getline(cin, s_choice);
	}
	choice = stoi(s_choice);
	

	while (choice != 6)
	{
		switch (choice)
		{
		case 1:  
			system("cls");
			cout << "Введите число: "; // добавить число в список
			cin >> s_value;
			cin.ignore();
			while (!isProved(s_value))
			{
				cout << "Введите число верно: ";
				getline(cin, s_value);
			}
			value = stoi(s_value);

			insert(first, value);
			printList(first);
			break;
		
		case 2: if (!IsEmpty(first)) // удалить число из списка
		{
			system("cls");
			cout << "Введите удаляемое число: ";
			cin >> s_value;
			cin.ignore();
			while (!isProved(s_value))
			{
				cout << "Введите число верно: ";
				getline(cin, s_value);
			}
			value = stoi(s_value);
			
			if (del(first, value))
			{  
				cout << "Удалено число: " << value << endl;
				printList(first);
			}

			else
				cout << "Число не найдено!" << endl;
		}
		else
			cout << "Список пуст!" << endl;
			break;
		
		case 3:   
			system("cls");
			sum(first);	// вычисление суммы	
			break;
		
		case 4: 
			system("cls");
			toFile(first); break;

		case 5: 
			system("cls");
			fromFile(first); break;

		default:  cout << "Неправильный выбор!" << endl;
			break;
		}
		menu();
		cout << "--> ";
		cin >> s_choice;
		cin.ignore();
		while (!isProved(s_choice))
		{
			cout << "Выберите пункт меню верно: ";
			getline(cin, s_choice);
		}
		choice = stoi(s_choice);
	}
	cout << "Конец!" << endl;
}

void menu(void)  //Вывод меню 
{
	cout << "\nСделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - Вычисление суммы отрицательных элементов, кратных 2" << endl;
	cout << " 4 - Запись информации в файл" << endl;
	cout << " 5 - Считывание информации из файла" << endl;
	cout << " 6 - Выход" << endl;
}

void insert(list* &p, int value) //Добавление числа value в список 
{
	list* Ptr = new list;
	
	if (Ptr != NULL)     //есть ли место?  
	{
		Ptr->number = value;
		Ptr->next = p;
		p = Ptr;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}



float del(list* &p, int value)  // Удаление числа 
{
	list* previous, * current, * temp;
	
	if (value == p->number)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // перейти к следующему 
		}
		
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
	return p == NULL;
}

void printList(list* p)  //Вывод списка 
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << " --> " << p->number;
			p = p->next;
		}
		cout << " -->NULL " << endl;
	}
}

void sum(list* p)  // Подсчет суммы отрицательных чисел, кратных 2  
{
	float sm = 0;
	if (p == NULL)
		cout << "Список пуст" << endl;
	
	else
	{
		while (p != NULL)
		{
			if (p->number < 0 && p->number % 2 == 0)
				sm = sm + (p->number);
			p = p->next;
		}
		cout << "Сумма = " << sm << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream fout;

    fout.open(inf);

	if (!fout.is_open())
	{
		cout << "Ошибка! " << endl;
	}
	
	while (temp)
	{
		buf = *temp;
		fout << temp->number<<" --> ";
		temp = temp->next;
	}
	fout << "NULL";
	fout.close();
	cout << "Список записан в файл information.txt\n";
}

void fromFile(list*& p)          //Считывание из файла
{
	list buf, * first = nullptr;
	string str;
	
	ifstream fin;
	fin.open(inf);
	
	if (!fin.is_open())
	{
		cout << "Ошибка! " << endl;
	}
	
	while (!fin.eof() )
	{
		str = " ";
		getline(fin, str);
		cout << "--> " << str;
	}
	
	fin.close();
	p = first;
	cout << "\nСписок считан из файла information.txt\n";
}





