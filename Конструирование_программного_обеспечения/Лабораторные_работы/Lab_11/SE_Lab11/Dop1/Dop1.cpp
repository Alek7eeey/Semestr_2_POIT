/*Разработать функцию, проверяющую является ли число положительным.
Реализацию выполнить через лямбда, которое возвращает true (число положительное) false (в противном случае)*/
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	
	cout << "For exit - enter 0" << endl << endl;
	while (true) 
	{
		int num;
		cout << "Enter number, please: ", cin >> num;
		
		if (num == 0)
		{
			exit(0);
		}

		else
		{
			auto res = [num] {
				if (num > 0)
				{
					cout << "True ";
					return true;
				}

				if (num < 0)
				{
					cout << "False ";
					return false;
				}
			};

			int k = res();
			cout << "( " << k << " )" << endl;
		}
		
	}

}