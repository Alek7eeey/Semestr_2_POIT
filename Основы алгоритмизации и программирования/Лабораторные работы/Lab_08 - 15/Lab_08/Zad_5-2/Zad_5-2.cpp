/*Создать очередь с вещественными числами, и заполнить ее с клавиатуры. 
Выполнить циклический сдвиг элементов в очереди так,
чтобы в ее начале был расположен наибольший элемент.*/

#include<iostream> 
#include <string>
#include <windows.h>
#include <queue>
using namespace std;

bool isProved_2(string num)
{
	char nums[] = "0123456789.";
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

bool isProved(string num)
{
	char nums[] = "-0123456789.";
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

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	queue <int> my_queue;
	string prov;
	int size, max = 0;
	cout << "Введите размерность очереди:\t" ;
	getline(cin, prov); //ввели 3
	while (!isProved_2(prov))
	{
		system("cls");
		cout << "Введите размерность очереди ВЕРНО:\t";
		getline(cin, prov);
	}
	size = stoi(prov);
	
	cout << endl;
	for (int h = 0; h < size; h++) {
		int a = 0;
		cout << "Введите " << h+1 << " элемент очереди:\t"; //ввели 10 100 1000
		getline(cin, prov);
		while (!isProved(prov))
		{
			cout << "Введите " << h + 1 << " элемент очереди ВЕРНО:\t";
			getline(cin, prov);
		}
		a = stoi(prov);
		my_queue.push(a);
	}

	cout << "\nСамый первый элемент в очереди: " << my_queue.front() << endl << endl;
	max = my_queue.front();

	for (int i = 0; i < size; i++)
	{
		int count = 0, per;
		if (my_queue.front() >= max)
		{
			max = my_queue.front();
			per = my_queue.front();
			my_queue.pop();
			my_queue.push(per);
			count++;
		}
		
		else
		{
			per = my_queue.front();
			my_queue.pop();
			my_queue.push(per);
			count++;
		}
		if (count == size-1)
		{
			break;
		}
	}

	cout << "Новая очередь: " << endl;
	for (int i = 0; i < size; i++)
	{
		int per, count = 0;
		
		if (my_queue.front() == max)
		{
			while (count!=size)
			{
				per = my_queue.front();
				cout << per << "\t";
				my_queue.pop();
				count++;
			}
			break;
		}

		else
		{
			per = my_queue.front();
			my_queue.pop();
			my_queue.push(per);
			count++;
		}
		
	}
	cout << endl;
}
