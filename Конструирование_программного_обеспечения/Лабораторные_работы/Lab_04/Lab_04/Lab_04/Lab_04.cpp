#include<string>
#include <iostream>
#include <windows.h>
using namespace std;

int function_visYear(int year1, int month_day1[]);
int function_numberDay(int year1, int* number, int month_day1[], int month1);
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F3");
	int birthday, birthday_day, birthday_month, data, year, day, month, day_number = 0,
		day_for_birthday, number_birthday = 0, number1 = 0, number2 = 0;

	const int size_of_month = 12;

	int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int month_day_visakosny[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	string name[size_of_month] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������"};

	cout << "������� ���� � ������� ��������(��� ��������): "; cin >> data;
	cout << "������� ���� ��� ���������: "; cin >> birthday;

	if (data > 0 && data < 31129999 && birthday > 0 && birthday < 31129999)
	{
		birthday_day = birthday / 1000000;
		birthday_month = (birthday - birthday_day * 1000000) / 10000;

		day = data / 1000000;
		month = (data - day * 1000000) / 10000;
		year = (data - day * 1000000 - month * 10000);

		if (year % 4 == 0 && year % 100 != 0)
		{

			if (month > 0 && month <= 12 && birthday_month > 0 && birthday_month <= 12 && day <= month_day_visakosny[month - 1] && birthday_day <= month_day_visakosny[birthday_month - 1])
			{

				cout << day << month << " ( " << name[month - 1] << " )" << year << endl;

				function_visYear(year, month_day);

				function_numberDay(year, &number1, month_day, month);

				day_number = number1 + day;

				for (int i = 0; i < birthday_month - 1; i++)
				{
					number2 += month_day[i];
				}

				number_birthday = number2 + birthday_day;
				day_for_birthday = number_birthday - day_number;

				if (day_for_birthday < 0)
				{
					day_for_birthday *= (-1);
					day_for_birthday += 365;
				}

				cout << "���������� �����: " << day_number << endl;
				cout << "���������� ����� ��� ��������: " << number_birthday << endl;
				cout << "���� �� ���������� ��� ��������: " << day_for_birthday << endl;
				cout << "�������� ������: " << name[month-1] << endl;
			}

			else
			{
				system("cls");
				cout << "\nError!" << endl;
			}

		}

		else
		{
			if (month > 0 && month <= 12 && birthday_month > 0 && birthday_month <= 12 && day <= month_day[month - 1] && birthday_day <= month_day[birthday_month - 1])
				{

				cout << day << month << " ( " << name[month - 1] << " )" << year << endl;

					function_visYear(year, month_day);

					function_numberDay(year, &number1, month_day, month);

					day_number = number1 + day;

					for (int i = 0; i < birthday_month - 1; i++)
					{
						number2 += month_day[i];
					}
					number_birthday = number2 + birthday_day;
					day_for_birthday = number_birthday - day_number;

					if (day_for_birthday < 0)
					{
						day_for_birthday *= (-1);
						day_for_birthday += 365;
					}

					cout << "���������� �����: " << day_number << endl;
					cout << "���������� ����� ��� ��������: " << number_birthday << endl;
					cout << "���� �� ���������� ��� ��������: " << day_for_birthday << endl;
					cout << "�������� ������: " << name[month-1] << endl;
				}

				else
				{
					system("cls");
					cout << "\nError!" << endl;
				}
		}
	}


	else
	{
		system("cls");
		cout << "\nError!" << endl;
	}


}

int function_numberDay(int year1, int* number, int month_day1[], int month1)
{
	for (int i = 0; i < month1 - 1; i++)
	{
		*number += month_day1[i];
	}
	return year1;
}

int function_visYear(int year1, int month_day1[])
{
	if (year1 % 4 == 0 && year1 % 100 != 0)
	{
		cout << "���� ��� ����������! " << endl;
		cout << "���� ������������ ����������� 12 ��������!" << endl;
		month_day1[1] = 29;

	}
	else
	{
		cout << "��� �� ����������!" << endl;
		cout << "���� ������������ ����������� 13 ��������!" << endl;
	}
	return month_day1[1];
}