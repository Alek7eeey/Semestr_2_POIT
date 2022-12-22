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
			cout << "������ ����������������� ����� � ����� ������� ���((\n";
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
			cout << "������ ����������������� ����� � ����� ������� ���((\n";
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
	HT.add("if", "�������� ��������, ��������� ������� �������� �����������");
	HT.add("else", "�������� ��������, ��������� ������ �������� � ������ ���� if - false");
	HT.add("for", "�������� �����, � ��������� ��������� ��������� ����. ��������: (�������; �������; ��������� ��������)");
	HT.add("while", "������� �����, � ��������� ������� �������(���. ����.), ���� ������� �������� �������� - ���� ����� �����������");
	HT.add("switch", "������� �������, � ������� ������ ������� � ���������� �� ���� ����������� �����. ������� case");
	HT.add("do", "� ����� ������ ������ ���������������� ��� ����������� ��� ���������� ���� ����������");
	do
	{
		cout << "\n1 - ������� ���-������� �� �����\n";
		cout << "2 - �������� �������\n";
		cout << "3 - ������� ��������\n";
		cout << "4 - �����\n";
		cout << "0 - �����\n";
		cout << "��� �����: "; cin >> choice;
		switch (choice)
		{
		case 1: HT.scan(); break;
		case 2: cout << "\n������� ���������������� �����, ������� �� ������ �������� � �������: "; cin >> name;
			cout << "������� �������� � ������ �����:\n"; cin >> disk;
			HT.add(name, disk);
			break;
		case 3: cout << "������� ��������: "; cin >> name;
			HT.deleteEl(name);
			break;
		case 4: cout << "������� ��������: "; cin >> name;
			HT.search(name);
			break;
		}
	} while (choice != 0);
}