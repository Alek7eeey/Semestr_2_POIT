//========================== Var8 =================================
//Аэропорт. Создать хеш-таблицу со следующими
//полями: номер рейса, аэропорт назначения. Ключ – номер рейса.

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <windows.h>
using namespace std;

#define gl(str)  getline(cin,str)
#define SIZE 32

bool isProved(string num, int start, int end)
{
	if (num == "")
		return false;
	char nums[] = "-0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < strlen(nums); j++)
		{
			if (num[i] == nums[j])
			{
				isNotNum = false;
				if (num[i] == '-' && i != 0)
					return false;
				if (num[i] == '-' && i == 0 && num.size() == 1)
					return false;
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

	if (stoi(num) < start || stoi(num) > end)
	{
		return false;
	}

	return true;
}

struct Information {
	int flight_number;
	string name;
} Inf;


struct HT {
	array <vector<Information>, SIZE> arr;

	int hash(int key)
	{
		return key % SIZE;
	}

	int cnt() {
		int cnt = 0;
		for (auto i : arr)
			cnt += i.size();
		return cnt;
	}

	bool add(int flight_number, string name)
	{
		if (cnt() == 32) 
			return false;

		int place = hash(flight_number);

		for (auto& i : arr[place])
		{
			if (i.flight_number == flight_number)
			{
				i.name = name;
				cout << i.name << endl;
				return true;
			}
		}

		Inf = { flight_number, name };
		arr[place].push_back(Inf);
		return true;
	}

	string operator[](int num)
	{
		int place = hash(num);
		for (auto& i : arr[place])
		{
			if (i.flight_number == num)
			{
				return i.name;
			}
		}
		return "none";
	}

	bool del(int num)
	{
		int place = hash(num);
		short j = 0;

		for (auto i : arr[place])
		{
			if (i.flight_number == num)
			{
				arr[place].erase(arr[place].begin() + j);
				return true;
			}
			j += 1;
		}
		return false;
	}

	void print()
	{
		for (auto i : arr)
		{
			for (auto j : i)
			{
				cout << "Пункт назначения: " << j.name << "\tномер рейса: " << j.flight_number << endl;
			}
		}
	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HT arr;
	string check;
	string name;
	string name_2;
	int flight_number, N;
	bool isExit = false;

	while (!isExit)
	{
		cout << endl; cout << endl;
		do {
			cout << "1) Добавить рейс!\n"
				<< "2) Удалить рейс!\n"
				<< "3) Поиск рейса!\n"
				<< "4) Вывести таблицу полётов!\n"
				<< "5) Выход!\n";
			gl(check);
		} while (!isProved(check, 1, 5));
		N = stoi(check);
		switch (N)
		{
		case 1:
			do {
				cout << "Введите номер рейса: ";
				gl(check);
				cout << endl;
			} while (!isProved(check, 1, 100000));
			flight_number = stoi(check);
			cout << "Введите пункт назначения: ";
			gl(name);
			arr.add(flight_number, name);
			break;
		case 2:
			do {
				cout << "Введите номер рейса: ";
				gl(check);
				cout << endl;
			} while (!isProved(check, 100000, 999999));
			flight_number = stoi(check);
			if (arr.del(flight_number))
				cout << "Удалено!\n";
			else
				cout << "Нет такого рейса!\n";
			break;
		case 3:
			do {
				cout << "Введите номер рейса: ";
				gl(check);
				cout << endl;
			} while (!isProved(check, 100000, 999999));
			flight_number = stoi(check);
			name_2 = arr[flight_number];
			cout << name_2 << endl;
			break;
		case 4:
			arr.print();
			break;

		case 5:
			exit(0);
			break;
		}
	}
}