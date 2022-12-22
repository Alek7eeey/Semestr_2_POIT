/*1)Разработать функцию, которая удаляет из стека первый отрицательный элемент, если такой есть.*/
/*2)Разработать функцию, которая удаляет первый положительный элемент, если такой есть.*/
/*3)Разработать функцию удаления элементов стека, кратных 3, если такие есть.*/

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
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение(удаление) элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Запись стека в файл" << endl;
		cout << "5 - Считывание информации из файла"<<endl;
		cout << "6 - Удаление из стека первого отрицательного элемента" << endl;
		cout << "7- Удаление из стека первого положительного элемента" << endl;
		cout << "8- Удаление из стека элементов, которые кратны 3" << endl;
		cout << "9 - Отчистка стека" << endl;
		cout << "10 - Выход" << endl;
		
		getline(cin, prov);
		
		while (!isProved(prov, 1, 10))
		{
			system("cls");
			cout << "\nВыберите команду корректно:" << endl;
			cout << "1 - Добавление элемента в стек" << endl;
			cout << "2 - Извлечение(удаление) элемента из стека" << endl;
			cout << "3 - Вывод стека" << endl;
			cout << "4 - Запись стека в файл" << endl;
			cout << "5 - Считывание информации из файла" << endl;
			cout << "6 - Удаление из стека первого отрицательного элемента" << endl;
			cout << "7- Удаление из стека первого положительного элемента" << endl;
			cout << "8- Удаление из стека элементов, которые кратны 3" << endl;
			cout << "9 - Отчистка стека" << endl;
			cout << "10 - Выход" << endl;
			getline(cin, prov);
		}
		system("cls");
		switch (stoi(prov))
		{

		case 1: //добавление элементов в стек
		{
			cout << "Введите число для добавления в стек" << "\t";
			getline(cin, prov);
			while (!isProved_2(prov))
			{
				system("cls");
				cout << "Введите ВЕРНОЕ число для добавления в стек\t";
				getline(cin, prov);
			}

			push(stoi(prov), stk);
			cout << "Число добавлено!" << endl;
			cout << "Стек: " << endl;
			show(stk);
			system("pause");
			break;
		}
		case 2: //удаление верхнего элемента из стека
		{
			choice = pop(stk);
			if (choice != -1)
			cout << "Извлеченный элемент: " << choice << endl;
			cout << "Стек: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 3: //вывод стека
		{
			cout << "Стек: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 4: //Запись стека в файл
		{
			filein(stk);
			system("pause");
			break;
		}

		case 5: //Считывание информации из файла
		{
			fileout(stk);
			system("pause");
			break;
		}

		case 6: //Удаление из стека первого отрицательного элемента
		{
			del_otr(stk);
			cout << "Стек: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 7: //Удаление из стека первого положительного элемента
		{
			del_pol(stk);
			cout << "Стек: " << endl;
			show(stk);
			system("pause");
			break;
		}

		case 8:
		{
			delete3(stk);
			cout << "Стек: " << endl;
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

void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}

int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}

	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}

void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
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
		cout << "Ошибка открытия файла! " << endl;
	}

	else
	{
		Stack* e = myStk->head;    //объявляется указатель на вершину стека
		int a;
		if (e == NULL)
			cout << "Стек пуст! Файл пустой!" << endl;

		while (e != NULL)
		{
			a = e->data;          //запись значения в переменную a 
			file << a << " ";
			e = e->next;
			count++;
		}

		if(count!=0)
		cout << "Информация записана в файл! " << endl;
		
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
		cout << "Файл пуст! " << endl;
	}

	else
	{
		string msg = " ";
		fstream file;
		file.open(str, fstream::in | fstream::out); //открытие файла для чтения и записи
		if (!file.is_open())
		{
			cout << "Ошибка открытия файла! " << endl;
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
	// Удаление головы
	if (myStack->head->data < 0)
	{
		myStack->head = myStack->head->next;
		delete tmp;
		count++;
		return;
	}

	// Итерируем по списку
	while (tmp->next)
	{
		// если нашли отрицательный элемент
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
		cout << "Отрицательные элементы отсутсвуют! " << endl;
	}
}

void RemoveNode(Stack* previous)
{
	Stack *to_del = previous->next;
	if (!to_del) return; // Если следующего элемента нет, то уходим
	previous->next = to_del->next; // вынимаем из списка
	delete to_del; // чистим память
}



void del_pol(Stack * myStack)
{
	int count = 0;
	Stack* tmp = myStack->head;
	// Удаление головы
	if (myStack->head->data > 0)
	{
		myStack->head = myStack->head->next;
		delete tmp;
		count++;
		return;
	}

	// Итерируем по списку
	while (tmp->next)
	{
		// если нашли положительный элемент
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
		cout << "Положительные элементы отсутсвуют! " << endl;
	}
}

void delete3(Stack* myStack) {
	
	int count = 0;
	Stack* tmp = myStack->head;
	// Удаление головы
	if (myStack->head->data % 3 == 0)
	{
		myStack->head = myStack->head->next;
		delete tmp;
		count++;
		return;
	}

	// Итерируем по списку
	while (tmp->next)
	{
		// если нашли положительный элемент
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
		cout << "Числа кратные 3 отсутствуют! " << endl;
	}
}

void clear(Stack* stack)
{
	int count = 0;
	if (stack->head == NULL)
		cout << "Стек пуст! Невомзожно выполнить операцию!";
	
	while (stack->head != NULL)
	{
		Stack* f = stack->head;
		stack->head = stack->head->next;
		delete f;
		count++;
	}
	
	if (count!=0)
	{
		cout << "Стек успешно очищен! ";
	}
	cout << "\n";
}

