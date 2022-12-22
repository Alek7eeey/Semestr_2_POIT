#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

typedef string stroke;

struct phone_number {

	stroke country_code;
	stroke provaider;
	stroke phone;
	stroke name;

	
};

bool isProved(string num)
{
	char nums[] = "0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
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

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;

		cout << "Введите количество телефонов, которые необходимо сохранить: ";
		cin >> size;

	phone_number* telephone = new phone_number[size];	

	for (int i = 0; i < size; i++)
	{
		system("cls");
		cout << "Телефон #" << i+1 << endl;
		cout << "Введите код страны: ";
		cin >> (telephone + i)->country_code;
		
		cin.ignore();
		while(!isProved( (telephone + i)->country_code) )
		{
			cout << "Введите правильный код страны: ";
			getline(cin, (telephone + i)->country_code);
		}

		cout << "Введите провайдера: ";
		cin >> (telephone+i)->provaider;
		
		cin.ignore();
		while (!isProved( (telephone + i)->provaider) )
		{
			cout << "Введите правильный номер провайдера: ";
			getline(cin, (telephone + i)->provaider);
		}

		cout << "Введите номер телефона: ";
		cin >> (telephone+i)->phone;
		
		cin.ignore();
		while (!isProved ( (telephone + i)->phone) )
		{
			cout << "Введите правильный номер телефона: ";
			getline(cin, (telephone + i)->phone);
		}

		cout << "Введите имя владельца: ";
		cin >> (telephone+i)->name;
	}

	int count = 0;
	int ch = 0;
	while (ch!=4)
	{
		cout << "\n\nВыберите операцию, которую хотите выполнить: " << endl;
		cout << "1 - вывод данных " << endl;
		cout << "2 - поиск по коду страны" << endl;
		cout << "3 - поиск по провайдеру" << endl;
		cout << "4 - выход" << endl;
		cin >> ch;

		if (ch == 1)
		{
			system("cls");
			for (int i = 0; i < size; i++)
			{
				cout << (telephone + i)->country_code<<"("<< (telephone + i)->provaider<<")"
					<< (telephone + i)->phone<<endl;
				cout << "Имя владельца: "<< (telephone + i)->name;
				cout << "\n___________________________________________________" << endl;
			}
		}

		if (ch == 2)
		{
			system("cls");
			stroke code;
			cout << "Введите код страны для поиска: ";
			cin >> code;

			cin.ignore();
			while (!isProved(code))
			{
				cout << "Введите правильный код страны: ";
				getline(cin, code);
			}

			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (code == telephone[i].country_code)
				{
					cout << (telephone + i)->country_code << "(" << (telephone + i)->provaider << ")"
						<< (telephone + i)->phone << endl;
					cout << "Имя владельца: " << (telephone + i)->name;
					cout << "\n___________________________________________________" << endl;
					count++;
				}
			}
			
			if (count == 0)
			{
				cout << "Номера с таким кодом страны отсутствуют! " << endl;
			}

		}

		if (ch == 3)
		{
			system("cls");
			stroke prov;
			cout << "Введите провайдера для поиска: ";
			cin >> prov;

			cin.ignore();
			while (!isProved(prov))
			{
				cout << "Введите правильный код страны: ";
				getline(cin, prov);
			}
			
			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (prov == telephone[i].provaider)
				{
					cout << (telephone + i)->country_code << "(" << (telephone + i)->provaider << ")"
						<< (telephone + i)->phone << endl;
					cout << "Имя владельца: " << (telephone + i)->name;
					cout << "\n___________________________________________________" << endl;
					count++;
				}

			}
			
			if (count == 0)
			{
				cout << "Номера с таким провайдером отсутствуют! " << endl;
			}
		}

		if (ch == 4)
		{
			delete[] telephone;
			exit(0);
		}
	}


	delete[] telephone;

}