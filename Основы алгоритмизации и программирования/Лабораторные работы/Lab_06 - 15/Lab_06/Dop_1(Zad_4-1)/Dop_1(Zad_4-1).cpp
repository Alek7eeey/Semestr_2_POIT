/*������� ������, ���������� �������� ������ ����. ����� ����� ������������� ���������
��� ������ ���������, ��� ������������� ��������� ���. */

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

void insert(list*&, int); //������� ���������� ��������, ���������� ����� ������ � ������, ������� ����������� 
float del(list*&, int);   //������� ��������, ���������� ����� ������ � ������, ������� ��������� 
int IsEmpty(list*);         //�������, ������� ���������, ���� �� ������
void printList(list*);      //������� ������
void menu(void);     //�������, ������������ ����
void sum(list*);  //������� �������� ����� ������������� ���������
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
	menu();    // ������� ���� 
	cout << "--> ";

	cin >> s_choice;
	cin.ignore();
	while (!isProved(s_choice))
	{
		cout << "�������� ����� ���� �����: ";
		getline(cin, s_choice);
	}
	choice = stoi(s_choice);


	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "������� �����: "; // �������� ����� � ������
			cin >> s_value;
			cin.ignore();
			while (!isProved(s_value))
			{
				cout << "������� ����� �����: ";
				getline(cin, s_value);
			}
			value = stoi(s_value);

			insert(first, value);
			printList(first);
			break;

		case 2: if (!IsEmpty(first)) // ������� ����� �� ������
		{
			system("cls");
			cout << "������� ��������� �����: ";
			cin >> s_value;
			cin.ignore();
			while (!isProved(s_value))
			{
				cout << "������� ����� �����: ";
				getline(cin, s_value);
			}
			value = stoi(s_value);

			if (del(first, value))
			{
				cout << "������� �����: " << value << endl;
				printList(first);
			}

			else
				cout << "����� �� �������!" << endl;
		}
			  else
			cout << "������ ����!" << endl;
			break;

		case 3:
			system("cls");
			sum(first);	// ���������� �����	
			printList(first);
			break;

		case 4:
			system("cls");
			toFile(first); break;

		case 5:
			system("cls");
			fromFile(first); break;

		default:  cout << "������������ �����!" << endl;
			break;
		}
		menu();
		cout << "--> ";
		cin >> s_choice;
		cin.ignore();
		while (!isProved(s_choice))
		{
			cout << "�������� ����� ���� �����: ";
			getline(cin, s_choice);
		}
		choice = stoi(s_choice);
	}
	cout << "�����!" << endl;
}

void menu(void)  //����� ���� 
{
	cout << "\n�������� �����:" << endl;
	cout << " 1 - ���� �����" << endl;
	cout << " 2 - �������� �����" << endl;
	cout << " 3 - ���������� ����� ������������� ���������" << endl;
	cout << " 4 - ������ ���������� � ����" << endl;
	cout << " 5 - ���������� ���������� �� �����" << endl;
	cout << " 6 - �����" << endl;
}

void insert(list*& p, int value) //���������� ����� value � ������ 
{
	list* Ptr = new list;

	if (Ptr != NULL)     //���� �� �����?  
	{
		Ptr->number = value;
		Ptr->next = p;
		p = Ptr;
	}
	else
		cout << "�������� ���������� �� ���������" << endl;
}



float del(list*& p, int value)  // �������� ����� 
{
	list* previous, * current, * temp;

	if (value == p->number)
	{
		temp = p;
		p = p->next;    // ����������� ���� 
		delete temp;      //���������� ������������� ���� 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // ������� � ���������� 
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

int IsEmpty(list* p) //������  ������? (1-��, 0-���) 
{
	return p == NULL;
}

void printList(list* p)  //����� ������ 
{
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << " --> " << p->number;
			p = p->next;
		}
		cout << " -->NULL " << endl;
	}
}

void sum(list* p)  // ������� ����� ������������� ���������  
{
	float sm = 0;
	if (p == NULL)
		cout << "������ ����" << endl;

	else
	{
		while (p != NULL)
		{
			if (p->number > 0 )
				sm = sm + (p->number);
			p = p->next;
		}
		cout << "����� = " << sm << endl;
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
		cout << "������! " << endl;
	}

	while (temp)
	{
		buf = *temp;
		fout << temp->number << " --> ";
		temp = temp->next;
	}
	fout << "NULL";
	fout.close();
	cout << "������ ������� � ���� information.txt\n";
}

void fromFile(list*& p)          //���������� �� �����
{
	list buf, * first = nullptr;
	string str;

	ifstream fin;
	fin.open(inf);

	if (!fin.is_open())
	{
		cout << "������! " << endl;
	}

	while (!fin.eof())
	{
		str = " ";
		getline(fin, str);
		cout << "--> " << str;
	}

	fin.close();
	p = first;
	cout << "\n������ ������ �� ����� information.txt\n";
}





