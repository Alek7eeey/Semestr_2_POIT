#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <Windows.h>
using namespace std;

const int sizeoft = 32;

struct Data {
	string disk;
	string name;
};

struct HashTable {
	array<vector<Data>, sizeoft> table;

	int hash_func(string key)
	{
		int sum = 0;
		for (auto i : key)
		{
			sum += int(i);
		}
		return sum % sizeoft;
	}

	bool add(string key, string disk)
	{
		int place = hash_func(key);
		Data t = { disk, key };
		table[place].push_back(t);
		return true;
	}
	void search(string key)
	{
		int place = hash_func(key);
		bool check = false;
		for (auto i : table[place])
		{
			if (i.name == key)
			{
				cout << "- " << i.disk << endl;
				check = true;
			}
		}
		if (check == false)
			cout << "Такого зарезервированого слова в нашей таблице нет((\n";
	}

	void deleteEl(string key)
	{
		int place = hash_func(key);
		bool check = false; int buf;
		for (auto i : table[place])
		{
			if (i.name == key)
			{
				check = true;
			}
			if (check == true)
				table[place].clear();
		}
		if (check == false)
			cout << "Такого зарезервированого слова в нашей таблице нет((\n";
	}

	void scan()
	{
		for (int j = 0; j < sizeoft; j++)
		{
			for (auto i : table[j])
			{
				cout << i.name << " --- " << i.disk << endl;
			}
		}
	}


};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HashTable HT;
	int choice; string name, disk;
	HT.add("if", "условный оператор, позволяет создать условную конструкцию");
	HT.add("else", "условный оператор, позволяет задать действие в случай если if - false");
	HT.add("for", "оператор цикла, в параметры оператора заносятся след. значения: (счётчик; условие; коррекция счётчика)");
	HT.add("while", "операто цикла, в параметры задаётся условие(лог. знач.), пока условие является истинной - тело цикла выполняется");
	HT.add("switch", "опертор условия, в скобках задётся условие в зависмости от него выполняется соотв. опертор case");
	HT.add("do", "в более старых языках программирования был необходимым для выполнения кода оператором");
	do
	{
		cout << "\n1 - вывести хеш-таблицу на экран\n";
		cout << "2 - добавить элемент\n";
		cout << "3 - удалить элементы\n";
		cout << "4 - поиск\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: "; cin >> choice;
		switch (choice)
		{
		case 1: HT.scan(); break;
		case 2: cout << "\nвведите зарезервированое слово, которое вы хотите добавить в таблицу: "; cin >> name;
			cout << "введите описание к вашему слову:\n"; cin >> disk;
			HT.add(name, disk);
			break;
		case 3: cout << "Введите деректву: "; cin >> name;
			HT.deleteEl(name);
			break;
		case 4: cout << "Введите деректву: "; cin >> name;
			HT.search(name);
			break;
		}
	} while (choice != 0);
}