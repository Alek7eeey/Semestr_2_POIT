//�����.������������ ������, ����, ����������, ������� �������� ��������(5, 10, 15, 20, 35, 30).����� �� ������������.

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
		cout << "������������:\t\t\t\t" << name
			<< "\n����:\t\t\t\t\t" << sum
			<< "\n����������:\t\t\t\t" << kol
			<< "\n������� �������� ��������:\t\t";

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
		cout << "�������� ����� ����:\n"
			<< "1) �������� �����\n"
			<< "2) ���������� � ������\n"
			<< "3) ���������� � ���� �������\n"
			<< "4) ����� �� �������\n"
			<< "�������: ";

		cin.getline(datas.point, 10);

		while (!isProved(datas.point, 1, 4))
		{
			cls;
			cout << "�������� ����� ����:\n"
				<< "1) �������� ��������\n"
				<< "2) ���������� � ������\n"
				<< "3) ���������� � ���� �������\n"
				<< "4) ����� �� �������\n"
				<< "������� ����� �� 1 �� 4: ";

			cin.getline(datas.point, 10);
		}

		cls;
		switch (atoi(datas.point))
		{
		case 1: // add
		{
			{
				cout << "�����������:\t\t\t";
				cin.getline(datas.name, 50);


				assignStr(items[iter].name, datas.name);

			}
			cout << endl; cls;
			//	����
			cout << endl; cls;
			{
				cout << "����:\t\t\t";
				cin.getline(datas.sum, 20);

				while (!isProved(datas.sum))
				{
					cout << "����(�����):\t\t\t";
					cin.getline(datas.sum, 20);
				}

				assignStr(items[iter].sum, datas.sum);

			}

			//	����
			cout << endl; cls;
			{
				cout << "����������:\t\t\t";
				cin.getline(datas.kol, 20);

				while (!isProved(datas.kol))
				{
					cout << "����������(�����):\t\t\t";
					cin.getline(datas.kol, 20);
				}

				assignStr(items[iter].kol, datas.kol);

			}
			// Type
			cout << endl; cls;
			{
				cout << "������� ������� ��������:\n"
					<< "1) 5\n"
					<< "2) 10\n"
					<< "3) 15\n"
					<< "4) 20\n"
					<< "5) 30\n"
					<< "6) 35\n"
					<< "�������: ";

				cin.getline(datas.type, 40);

				while (!isProved(datas.type, 1, 6))
				{
					cout << "������� ������� ��������:\n"
						<< "1) 5\n"
						<< "2) 10\n"
						<< "3) 15\n"
						<< "4) 20\n"
						<< "5) 30\n"
						<< "6) 35\n"
						<< "������� ����� �� 1 �� 6: ";

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

			cout << "�� �������� �����: \n\n";
			items[iter - 1].GetDatas();

			cout << "\n��� ����������� ������� ����� �������!";
			cin.ignore();
			break;
		}
		case 2: // info
		{
			if (iter == 0)
			{
				cout << "�������� �����!";
				break;
			}

			char tovar[100],
				proverka[100];

			int pr = 0,
				k;

			cout << "������� ������������ ������: ";
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

			cout << "\n��� ����������� ������� ����� �������!";
			cin.ignore();
			break;
		}
		case 3: // output
		{
			if (iter == 0)
			{
				cout << "�������� �����������!";
				break;
			}

			for (int i = 0; i < iter; i++)
			{
				items[i].GetDatas();
				cout << endl;
			}

			cout << "\n��� ����������� ������� ����� �������!";
			cin.ignore();
			break;
		}
		case 4: // exit
		{
			isExit = true;
			cout << "����!"<<endl;
			break;
		}

		}
	}

	return 0;
}