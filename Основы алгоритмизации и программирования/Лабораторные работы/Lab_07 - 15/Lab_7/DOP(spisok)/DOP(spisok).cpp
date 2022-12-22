/*1)����������� �������, ������� ������� �� ����� ������ ������������� �������, ���� ����� ����.*/
/*2)����������� �������, ������� ������� ������ ������������� �������, ���� ����� ����.*/
/*3)����������� ������� �������� ��������� �����, ������� 3, ���� ����� ����.*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

struct Stack
{
	int data;
	Stack* next;
	Stack* head;
	Stack* end;
} *stk;

string str = "inf.txt", prov = "";


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

void push(int num, struct Stack* stack);
int pop(struct Stack*);
void show(struct Stack*);
void filein(struct Stack*);
void fileout(struct Stack*);
void del_otr(struct Stack*);
void RemoveNode(Stack* previous);
void del_pol(struct Stack*);
void delete3(struct Stack*);
void clear(struct Stack*);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Stack* MyStk = new Stack;
	stk = new Stack;
	stk->head = NULL;
	int choice;

	while (true) {
		system("cls");
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ����������(��������) �������� �� �����" << endl;
		cout << "3 - ����� �����" << endl;
		cout << "4 - ������ ����� � ����" << endl;
		cout << "5 - ���������� ���������� �� �����"<<endl;
		cout << "6 - �������� �� ����� ������� �������������� ��������" << endl;
		cout << "7- �������� �� ����� ������� �������������� ��������" << endl;
		cout << "8- �������� �� ����� ���������, ������� ������ 3" << endl;
		cout << "9 - �������� �����" << endl;
		cout << "10 - �����" << endl;
		
		getline(cin, prov);
		
		while (!isProved(prov, 1, 10))
		{
			system("cls");
			cout << "\n�������� ������� ���������:" << endl;
			cout << "1 - ���������� �������� � ����" << endl;
			cout << "2 - ����������(��������) �������� �� �����" << endl;
			cout << "3 - ����� �����" << endl;
			cout << "4 - ������ ����� � ����" << endl;
			cout << "5 - ���������� ���������� �� �����" << endl;
			cout << "6 - �������� �� ����� ������� �������������� ��������" << endl;
			cout << "7- �������� �� ����� ������� �������������� ��������" << endl;
			cout << "8- �������� �� ����� ���������, ������� ������ 3" << endl;
			cout << "9 - �������� �����" << endl;
			cout << "10 - �����" << endl;
			getline(cin, prov);
		}
		system("cls");
		switch (stoi(prov))
		{

		case 1: //���������� ��������� � ����
		{
			cout << "������� ����� ��� ���������� � ����" << "\t";
			getline(cin, prov);
			while (!isProved_2(prov))
			{
				system("cls");
				cout << "������� ������ ����� ��� ���������� � ����\t";
				getline(cin, prov);
			}

			push(stoi(prov), stk);
			cout << "����� ���������!" << endl;
			cout << "����: " << endl;
			show(stk);
			system("pause");
			break;
		}
		case 2: //�������� �������� �������� �� �����
		{
			choice = pop(stk);
			if (choice != -1)
			cout << "����������� �������: " << choice << endl;
			cout << "����: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 3: //����� �����
		{
			cout << "����: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 4: //������ ����� � ����
		{
			filein(stk);
			system("pause");
			break;
		}

		case 5: //���������� ���������� �� �����
		{
			fileout(stk);
			system("pause");
			break;
		}

		case 6: //�������� �� ����� ������� �������������� ��������
		{
			del_otr(stk);
			cout << "����: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 7: //�������� �� ����� ������� �������������� ��������
		{
			del_pol(stk);
			cout << "����: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 8:
		{
			delete3(stk);
			cout << "����: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 9:
		{
			clear(stk);
			system("pause");
			break;
		}
		
		case 10:
		{
			exit(0);
		}
		
		}
	}
}

void push(int x, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}

int pop(Stack* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}

	else
	{
		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}

void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void filein(Stack *myStk)
{
	ofstream file;
	file.open(str);
	int count = 0;
	
	if (!file.is_open())
	{
		cout << "������ �������� �����! " << endl;
	}

	else
	{
		Stack* e = myStk->head;    //����������� ��������� �� ������� �����
		int a;
		if (e == NULL)
			cout << "���� ����! ���� ������!" << endl;

		while (e != NULL)
		{
			a = e->data;          //������ �������� � ���������� a 
			file << a << " ";
			e = e->next;
			count++;
		}

		if(count!=0)
		cout << "���������� �������� � ����! " << endl;
		
		cout << endl;
	}
	file.close();
}

void fileout(Stack* myStk)
{

	ifstream file_2("inf.txt", ios::binary | ios::ate);
	int size = file_2.tellg();
	file_2.close();

	if (size == 0)
	{
		cout << "���� ����! " << endl;
	}

	else
	{
		string msg = " ";
		fstream file;
		file.open(str, fstream::in | fstream::out); //�������� ����� ��� ������ � ������
		if (!file.is_open())
		{
			cout << "������ �������� �����! " << endl;
		}

		else
		{
			while (!file.eof())
			{
				msg = " ";
				file >> msg;
				cout << msg << " ";
			}
		}
		cout << endl;
		file.close();
	}
}


void del_otr(Stack * myStack)
{
	int count = 0;
	Stack* tmp = myStack->head;
	// �������� ������
	if (myStack->head->data < 0)
	{
		myStack->head = myStack->head->next;
		delete tmp;
		count++;
		return;
	}

	// ��������� �� ������
	while (tmp->next)
	{
		// ���� ����� ������������� �������
		if (tmp->next->data < 0)
		{
			RemoveNode(tmp);
			count++;
			return;
		}
		tmp = tmp->next;
	}
	if (count==0)
	{
		cout << "������������� �������� ����������! " << endl;
	}
}

void RemoveNode(Stack* previous)
{
	Stack *to_del = previous->next;
	if (!to_del) return; // ���� ���������� �������� ���, �� ������
	previous->next = to_del->next; // �������� �� ������
	delete to_del; // ������ ������
}



void del_pol(Stack * myStack)
{
	int count = 0;
	Stack* tmp = myStack->head;
	// �������� ������
	if (myStack->head->data > 0)
	{
		myStack->head = myStack->head->next;
		delete tmp;
		count++;
		return;
	}

	// ��������� �� ������
	while (tmp->next)
	{
		// ���� ����� ������������� �������
		if (tmp->next->data > 0)
		{
			RemoveNode(tmp);
			count++;
			return;
		}
		tmp = tmp->next;
	}
	if (count == 0)
	{
		cout << "������������� �������� ����������! " << endl;
	}
}

void delete3(Stack* myStack) {
	
	int count = 0;
	Stack* tmp = myStack->head;
	// �������� ������
	if (myStack->head->data % 3 == 0)
	{
		myStack->head = myStack->head->next;
		delete tmp;
		count++;
		return;
	}

	// ��������� �� ������
	while (tmp->next)
	{
		// ���� ����� ������������� �������
		if (tmp->next->data % 3 == 0)
		{
			RemoveNode(tmp);
			count++;
			return;
		}
		tmp = tmp->next;
	}
	if (count == 0)
	{
		cout << "����� ������� 3 �����������! " << endl;
	}
}

void clear(Stack* stack)
{
	int count = 0;
	if (stack->head == NULL)
		cout << "���� ����! ���������� ��������� ��������!";
	
	while (stack->head != NULL)
	{
		Stack* f = stack->head;
		stack->head = stack->head->next;
		delete f;
		count++;
	}
	
	if (count!=0)
	{
		cout << "���� ������� ������! ";
	}
	cout << "\n";
}

