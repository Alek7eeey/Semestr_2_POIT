/*
N �������  �������������  �� �����.  ����� ������ �� �������, ������� ������� k-��,
������ ���� ����� ��������. ���������� ������� �������� ����� �� �����.
������������ �������� ������.
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <list>
using namespace std;

void out(list <string> &li)
{
	cout << "\n������:" << endl;
	for (auto i = li.cbegin(); i !=li.cend(); ++i) //��������
	{
		cout << *i << endl;
	}
}

void del(list <string>& li, int k, int count, int f = 1)
{
	string time; int schet = 0;
	for (auto i = 0; i <count; ++i) 
	{
		if (f % k == 0)
		{
			li.pop_front();
			schet++;
		}

		else {

			time = li.front();
			li.pop_front();
			li.push_back(time);

		}
		++f;
	}
	if (schet == 0)
	{
		cout << "\n������������ ���������� ���������!";
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list <string> li;
	int n;
	string t = " �������";


	while (true)
	{
		system("cls");
		cout << "������� ���������� �������: ", cin >> n;

		for (int i = 0; i < n; i++)
		{
			string name = to_string(i + 1);
			name.append(t);
			li.push_back(name);
		}
		out(li);

		int k;

		int count = li.size();
		cout << "������� k(������ k-�� ������ ����� �����): ", cin >> k;

		del(li, k, count);
		out(li);
		system("pause");
		cout << endl;
		int choice;
		cout << "������� ����������?(1 - ��, 2 - ���) ", cin >> choice;
		/*if (choice == 1)
		{
			goto active;
		}*/

		if (choice == 0)
		{
			exit(0);
		}
		if (choice == 1)
		{
			li.clear();
			system("cls");
		}
		
		else if(choice !=1 && choice !=0)
		{
			system("cls");
			cout << "Error!" << endl;
		}
	}
	
	
	/*auto it = li.cbegin();
	
		advance(it, k-1);
		li.erase(it);*/
		
	//for (auto i = li.cbegin(); i != li.cend(); ++i)
	//{
	//		if (f % k == 0)
	//		{
	//			li.erase(it);
	//			f++;
	//		}
	//	
	//	++it;
	//	f++;
	//}
	
}