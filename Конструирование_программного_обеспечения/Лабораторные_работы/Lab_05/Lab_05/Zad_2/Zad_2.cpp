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

		cout << "������� ���������� ���������, ������� ���������� ���������: ";
		cin >> size;

	phone_number* telephone = new phone_number[size];	

	for (int i = 0; i < size; i++)
	{
		system("cls");
		cout << "������� #" << i+1 << endl;
		cout << "������� ��� ������: ";
		cin >> (telephone + i)->country_code;
		
		cin.ignore();
		while(!isProved( (telephone + i)->country_code) )
		{
			cout << "������� ���������� ��� ������: ";
			getline(cin, (telephone + i)->country_code);
		}

		cout << "������� ����������: ";
		cin >> (telephone+i)->provaider;
		
		cin.ignore();
		while (!isProved( (telephone + i)->provaider) )
		{
			cout << "������� ���������� ����� ����������: ";
			getline(cin, (telephone + i)->provaider);
		}

		cout << "������� ����� ��������: ";
		cin >> (telephone+i)->phone;
		
		cin.ignore();
		while (!isProved ( (telephone + i)->phone) )
		{
			cout << "������� ���������� ����� ��������: ";
			getline(cin, (telephone + i)->phone);
		}

		cout << "������� ��� ���������: ";
		cin >> (telephone+i)->name;
	}

	int count = 0;
	int ch = 0;
	while (ch!=4)
	{
		cout << "\n\n�������� ��������, ������� ������ ���������: " << endl;
		cout << "1 - ����� ������ " << endl;
		cout << "2 - ����� �� ���� ������" << endl;
		cout << "3 - ����� �� ����������" << endl;
		cout << "4 - �����" << endl;
		cin >> ch;

		if (ch == 1)
		{
			system("cls");
			for (int i = 0; i < size; i++)
			{
				cout << (telephone + i)->country_code<<"("<< (telephone + i)->provaider<<")"
					<< (telephone + i)->phone<<endl;
				cout << "��� ���������: "<< (telephone + i)->name;
				cout << "\n___________________________________________________" << endl;
			}
		}

		if (ch == 2)
		{
			system("cls");
			stroke code;
			cout << "������� ��� ������ ��� ������: ";
			cin >> code;

			cin.ignore();
			while (!isProved(code))
			{
				cout << "������� ���������� ��� ������: ";
				getline(cin, code);
			}

			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (code == telephone[i].country_code)
				{
					cout << (telephone + i)->country_code << "(" << (telephone + i)->provaider << ")"
						<< (telephone + i)->phone << endl;
					cout << "��� ���������: " << (telephone + i)->name;
					cout << "\n___________________________________________________" << endl;
					count++;
				}
			}
			
			if (count == 0)
			{
				cout << "������ � ����� ����� ������ �����������! " << endl;
			}

		}

		if (ch == 3)
		{
			system("cls");
			stroke prov;
			cout << "������� ���������� ��� ������: ";
			cin >> prov;

			cin.ignore();
			while (!isProved(prov))
			{
				cout << "������� ���������� ��� ������: ";
				getline(cin, prov);
			}
			
			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (prov == telephone[i].provaider)
				{
					cout << (telephone + i)->country_code << "(" << (telephone + i)->provaider << ")"
						<< (telephone + i)->phone << endl;
					cout << "��� ���������: " << (telephone + i)->name;
					cout << "\n___________________________________________________" << endl;
					count++;
				}

			}
			
			if (count == 0)
			{
				cout << "������ � ����� ����������� �����������! " << endl;
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