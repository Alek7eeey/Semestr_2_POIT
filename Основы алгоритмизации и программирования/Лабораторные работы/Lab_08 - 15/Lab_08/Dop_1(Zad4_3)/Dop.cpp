/*
---1)������� ������� ��� ����� (������������� � �������������) ����� � ������� ��� �����, ������,
�������� � ����������� ������� �������. ������� ��� ������ �������� �������.
������� ������ ���������� �������. ����� ������������ ������� �������. 
---2)������� ������� ��� ����� ����� � ������� ��� �����, ������, �������� � ����������� ������� �������.
������� �������� ������� �� ������� �������� (������������).
������� ������ ���������� �������. ����� ������������ ������� �������. 
---3)������� ������� ��� ����� ����� � ������� ��� �����, ������, �������� � ����������� ������� �������.
����������� �������, ������� ������� �� ������� ������ ������������� �������, ���� ����� ����.
*/

#include <iostream>
#include <string>
#include <windows.h>
#include <queue>
using namespace std;

bool isProved(string num, int start, int end)
{
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

bool isProved_2(string num)
{
	char nums[] = "-0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < 11; j++)
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

void menu();
void fill_queue(queue <int> &, int, string);
void output(queue <int> &, int);
void del_oneElement(queue <int>&, int &);
void clear_queue(queue <int>&, int);
void del_threeElements(queue <int>&, int&);
void max_element(queue <int>&, int);
void del_otr(queue <int>&, int&);

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleOutputCP(1251);
	queue <int> qu;
	string prov;
	int choice, size;

	cout << "������� ����������� �������:\t";
	getline(cin, prov);
	while (!isProved_2(prov))
	{
		system("cls");
		cout << "�������� ����������� ������� �����:\t";
		getline(cin, prov);
	}
	size = stoi(prov);

	fill_queue(qu, size, prov);

	while (true)
	{
		menu();
		cout << "->";
		getline(cin, prov);
		while (!isProved(prov, 0, 7))
		{
			system("cls");
			cout << "�������� ���������� �������!\n";
			menu();
			cout << "->";
			getline(cin, prov);
		}

		choice = stoi(prov);
		switch (choice)
		{
		case 0: {
			system("cls");
			cout << "������� ����������� �������:\t";
			getline(cin, prov);
			while (!isProved_2(prov))
			{
				system("cls");
				cout << "�������� ����������� ������� �����:\t";
				getline(cin, prov);
			}
			size = stoi(prov);
			fill_queue(qu, size, prov);
			break;
		}

		case 1: {
			system("cls");
			cout << "�������: " << endl;
			output(qu, size);
			system("pause");
			system("cls");
			break;
		}

		case 2: {
			system("cls");
			del_oneElement(qu, size);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			clear_queue(qu, size);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			cout << "������ �������: " << qu.size() << endl;
			system("pause");
			system("cls");
			break;
		}

		case 5: {
			system("cls");
			del_threeElements(qu, size);
			cout << "�������:" << endl;
			output(qu, size);
			system("pause");
			system("cls");
			break;
		}

		case 6: {
			system("cls");
			max_element(qu, size);
			system("pause");
			system("cls");
			break;
		}

		case 7: {
			system("cls");
			del_otr(qu, size);
			system("pause");
			system("cls");
			break;
		}
		
		case 8: {
			system("cls");
			exit(0);
		}

	    }
	}
}

void menu()
{
	cout << "�������� �������:" << endl;
	cout << "0 - ���������� ������� ������" << endl;
	cout << "1 - ����� ������� �� �����" << endl;
	cout << "2 - �������� ������� �������� �������" << endl;
	cout << "3 - �������� �������" << endl;
	cout << "4 - ����� ������� �������" << endl;
	cout << "5 - �������� ������ ��� ��������� �������" << endl;
	cout << "6 - ����� ������������� �������� �������" << endl;
	cout << "7 - ����� � �������� ������� �������������� �����" << endl;
	cout << "8 - �����" << endl;
}

void fill_queue(queue<int> &qu,int size, string prov)
{

	cout << endl;
	for (int h = 0; h < size; h++) {
		int a = 0;
		cout << "������� " << h + 1 << " ������� �������:\t";
		getline(cin, prov);
		while (!isProved_2(prov))
		{
			cout << "������� " << h + 1 << " ������� ������� �����:\t";
			getline(cin, prov);
		}
		a = stoi(prov);
		qu.push(a);
	}
	system("pause");
	system("cls");
}

void output(queue <int> &qu, int size) 
{
	int count = 0, per = 0;
	if (!qu.empty()) {
		while (count != size)
		{
			per = qu.front();
			cout << per << "\t";
			qu.push(per);
			qu.pop();
			count++;
		}
		cout << endl;
	}
	else
	{
		cout << "������� �����!" << endl;
	}
}

void del_oneElement(queue <int>&qu, int &size)
{
	if (!qu.empty()) {
		qu.pop();  // ������� ������� �� �������
		size -= 1;
		cout << "������� �����!" << endl;
	}
	else
		cout << "������� �����!" << endl;
}

void clear_queue(queue <int>&qu, int size)
{
	if (!qu.empty()) {
		while (size!=0)
		{
			qu.pop();  // ������� ������� �� �������
			size -= 1;
		}
		cout << "������� �����!" << endl;
	}
	else
		cout << "������� �����!" << endl;
}

void del_threeElements(queue <int>&qu, int&size)
{
	int count = 0, prover = 0;
	if (size < 3)
	{
		cout << "��������� � ������� ������ ���! " << endl;
		prover = 1;
	}
	
	if (!qu.empty() && prover!=1) {
		
		while (count<3)
		{	qu.pop();  // ������� ������� �� �������
			size -= 1;
			count++;
		}
		cout << "��� �������� �������!" << endl;
	}

	else if(prover!=1)
		cout << "������� �����!" << endl;
}

void max_element(queue <int>&qu, int size)
{
	if (!qu.empty()) {
		
		int count = 0, per, max = 0;
		for (int i = 0; i < size; i++)
		{
			if (qu.front() >= max)
			{
				max = qu.front();
				per = qu.front();
				qu.pop();
				qu.push(per);
				count++;
			}

			else
			{
				per = qu.front();
				qu.pop();
				qu.push(per);
				count++;
			}
			
			if (count == size - 1)
			{
				break;
			}
		}
		cout << "������������ ������� = " << max << endl;
	}

	else
	{
	cout << "������� �����!" << endl;
	}
}

void del_otr(queue <int>&qu, int &size)
{
	int count = 0, per = 0;
	if (!qu.empty()) {
		while (count != size)
		{
			count++;

			per = qu.front();
			if (per<0)
			{
				qu.pop();
				cout << "������� �����! " << endl;
				size -= 1;
				break;
			}
			else
			{
				qu.push(per);
				qu.pop();
			}
			
			if (count == size -1)
			{
				cout << "������������� �������� �����������!" << endl;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "������� �����!" << endl;
	}
}