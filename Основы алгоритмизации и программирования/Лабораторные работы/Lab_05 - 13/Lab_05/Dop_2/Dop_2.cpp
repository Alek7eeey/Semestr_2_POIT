//Склад.Наименование товара, цена, количество, процент торговой надбавки(5, 10, 15, 20, 35, 30).Выбор по наименованию.

#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
#include "check.h"

#define CNT 30
#define cls system("cls") 

enum TYPE
{
	NAD1 = 5,
	NAD2 = 10,
	NAD3 = 15,
	NAD4 = 20,
	NAD5 = 30,
	NAD6 = 35

};

union maskhuman
{
	char name[50],
		sum[20],
		kol[50],
		type[50],
		point[10];

} datas;

struct item
{
	char name[50],
		sum[20],
		kol[50];

	TYPE type;


	void GetDatas()
	{
		cout << "Наименование:\t\t\t\t" << name
			<< "\nЦена:\t\t\t\t\t" << sum
			<< "\nКоличество:\t\t\t\t" << kol
			<< "\nПроцент торговой надбавки:\t\t";

		switch (type)
		{
		case NAD1:
			cout << "5" << endl;
			break;
		case NAD2:
			cout << "10" << endl;
			break;
		case NAD3:
			cout << "15" << endl;
			break;
		case NAD4:
			cout << "20" << endl;
			break;
		case NAD5:
			cout << "30" << endl;
			break;
		case NAD6:
			cout << "35" << endl;
			break;
		}
	}

} items[CNT];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool isExit = false;
	int iter = 0;

	while (!isExit)
	{
		cls;
		cout << "Выберите пункт меню:\n"
			<< "1) Добавить товар\n"
			<< "2) Информация о товаре\n"
			<< "3) Информация о всех товарах\n"
			<< "4) Выход из системы\n"
			<< "Вводите: ";

		cin.getline(datas.point, 10);

		while (!isProved(datas.point, 1, 4))
		{
			cls;
			cout << "Выберите пункт меню:\n"
				<< "1) Добавить добавить\n"
				<< "2) Информация о товаре\n"
				<< "3) Информация о всех товарах\n"
				<< "4) Выход из системы\n"
				<< "Введите пункт от 1 до 4: ";

			cin.getline(datas.point, 10);
		}

		cls;
		switch (atoi(datas.point))
		{
		case 1: // add
		{
			{
				cout << "Наименоание:\t\t\t";
				cin.getline(datas.name, 50);


				assignStr(items[iter].name, datas.name);

			}
			cout << endl; cls;
			//	Цена
			cout << endl; cls;
			{
				cout << "Цена:\t\t\t";
				cin.getline(datas.sum, 20);

				while (!isProved(datas.sum))
				{
					cout << "Цена(число):\t\t\t";
					cin.getline(datas.sum, 20);
				}

				assignStr(items[iter].sum, datas.sum);

			}

			//	Цена
			cout << endl; cls;
			{
				cout << "Количество:\t\t\t";
				cin.getline(datas.kol, 20);

				while (!isProved(datas.kol))
				{
					cout << "Кщличество(число):\t\t\t";
					cin.getline(datas.kol, 20);
				}

				assignStr(items[iter].kol, datas.kol);

			}
			// Type
			cout << endl; cls;
			{
				cout << "Введите процент надбавки:\n"
					<< "1) 5\n"
					<< "2) 10\n"
					<< "3) 15\n"
					<< "4) 20\n"
					<< "5) 30\n"
					<< "6) 35\n"
					<< "Вводите: ";

				cin.getline(datas.type, 40);

				while (!isProved(datas.type, 1, 6))
				{
					cout << "Введите процент надбавки:\n"
						<< "1) 5\n"
						<< "2) 10\n"
						<< "3) 15\n"
						<< "4) 20\n"
						<< "5) 30\n"
						<< "6) 35\n"
						<< "Введите пункт от 1 до 6: ";

					cin.getline(datas.type, 40);
				}

				switch (atoi(datas.type))
				{
				case 1:
					items[iter++].type = NAD1;
					break;
				case 2:
					items[iter++].type = NAD2;
					break;
				case 3:
					items[iter++].type = NAD3;
					break;
				case 4:
					items[iter++].type = NAD4;
					break;
				case 5:
					items[iter++].type = NAD5;
					break;
				case 6:
					items[iter++].type = NAD6;
					break;
				}
			}
			// The end
			cls;

			cout << "Вы добавили товар: \n\n";
			items[iter - 1].GetDatas();

			cout << "\nДля продолжения нажмите любую клавишу!";
			cin.ignore();
			break;
		}
		case 2: // info
		{
			if (iter == 0)
			{
				cout << "Добавьте товар!";
				break;
			}

			char tovar[100],
				proverka[100];

			int pr = 0,
				k;

			cout << "Введите наименование товара: ";
			cin.getline(tovar, 100);

			for (int g = 0; g < iter; g++)
			{
				k = 0;
				assignStr(proverka, items[g].name);
				for (int i = 0; ; i++)
				{
					if (proverka[i] == tovar[k])
					{
						pr++;
					}
					k++;
					if (proverka[i] == '\0')
					{
						break;
					}
				}
				if (pr == k)
				{
					items[g].GetDatas();
				}
			}

			cout << "\nДля продолжения нажмите любую клавишу!";
			cin.ignore();
			break;
		}
		case 3: // output
		{
			if (iter == 0)
			{
				cout << "Добавьте горожанинов!";
				break;
			}

			for (int i = 0; i < iter; i++)
			{
				items[i].GetDatas();
				cout << endl;
			}

			cout << "\nДля продолжения нажмите любую клавишу!";
			cin.ignore();
			break;
		}
		case 4: // exit
		{
			isExit = true;
			cout << "Пока!"<<endl;
			break;
		}

		}
	}

	return 0;
}