//���������. ����� �����, ����� ����������,
//����� ������, ���� ������, ��������� ������,
//���������� ����. ����� �� ���� ������.
//���� ������ ����������� � ������� �������� ����,
//����� ���������� - � ������� ������������.

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

enum destination {
	Kiev,
	Warsaw,
	Berlin,
	Vilnius,
	London,
	nothing
};

struct flights
{
	string flight_number;
	destination punct;
	string departure_time;
	struct departure_date
	{
		int dd : 6;
		int mm : 5;
		int yyyy :15;
	} date;
	
	string cost;
	int number_of_seats;

	~flights() {
		flight_number = "";
		departure_time = "";
		punct = destination::nothing;
		date.dd = 0;
		date.mm = 0;
		date.yyyy = 0;
		cost = "";
		number_of_seats = 0;
	}
};

void input(flights* flights, int);
void output(flights* flights, int);
void removal(flights* flights, int);
void search(flights* flights, int);
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
	int kol;
	cout << "������� ���������� ����������: ";
	cin >> kol;
	flights* f = new flights[kol];

		input(f, kol);

	int ans;

	do {
		cout << "1) ����� ���������� � ��������� �� �����\n2) �������� ���������� �� ���� ������\n3) ����� ����� �� ���� ������\n4) �����\n\n";
		cin >> ans;

		switch (ans)
		{
		case 1: output(f, kol);
			break;
		case 2: removal(f, kol);
			break;
		case 3: search(f, kol);
		
		default: cout<<"������� ������������ ������!\n";
			break;
		}
	} while (ans != 4);

	delete[] f;
}

void input(flights* flights, int kol)
{
	for (int i = 0; i < kol; i++)
	{
		system("cls");
		cout << "������� ����� ���������: ";
		cin>>flights[i].flight_number;

		string puncts;
		cout << "�������� ����� ����������(Kiev, Warsaw, Berlin, Vilnius, London): ";
		cin >> puncts;

		if (puncts == "Kiev")
		{
			flights[i].punct = destination::Kiev;
		}

		if (puncts == "Warsaw")
		{
			flights[i].punct = destination::Warsaw;
		}

		if (puncts == "Berlin")
		{
			flights[i].punct = destination::Berlin;
		}

		if (puncts == "Vilnius")
		{
			flights[i].punct = destination::Vilnius;
		}

		if (puncts == "London")
		{
			flights[i].punct = destination::London;
		}

		cout << "������� ����� ������: ";
		cin>>flights[i].departure_time;

		string date, info;
		int counter = 0;

		cout << "������� ���� ������: ",
			cin >> date;

		date.push_back('.'); //� ����� ������ ������������ �����

		for (int j = 0; j < date.size(); j++) {

			if (date[j] <= '9' && date[j] >= '0') {
				info += date[j];
			}

			else if (date[j] == '.') {

				switch (counter)
				{
				case 0: flights[i].date.dd = stoi(info);
					info = "";
					break;

				case 1: flights[i].date.mm = stoi(info);
					info = "";
					break;

				case 2: flights[i].date.yyyy = stoi(info);
					info = "";
					break;

				default: cout << "������� �������� ������\n";
					break;
				}
				
				counter++;
			}

			else
				cout << "������� �������� ������" << endl;
		}
		cout << "������� ��������� ������: ";
		cin>>flights[i].cost;

		cout << "������� ���������� ����: ";
		cin >> flights[i].number_of_seats;
		cout << endl;
	}
}

void output(flights* flights, int amount) {//����� ���������� � ���� ���������
	
	system("cls");
	cout<< "���������� �� ���������:\n\n";
	
	for (int i = 0; i < amount; i++)
	{
			cout << "����� ���������: " << flights[i].flight_number << endl;
			
			if (flights[i].punct == 0)
			{
				cout << "����� ����������: ����" << endl;
			}

			if (flights[i].punct == 1)
			{
				cout << "����� ����������: �������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 2)
			{
				cout << "����� ����������: ������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 3)
			{
				cout << "����� ����������: �������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 4)
			{
				cout << "����� ����������: ������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 5)
			{
				cout << "����� ����������: -" << endl;
			}
			
			cout << "���� ������: " << flights[i].date.dd << '.' << flights[i].date.mm <<'.' << flights[i].date.yyyy << endl;
			cout << "����� ������: " << flights[i].departure_time << "\n";
			cout << "��������� ������: " << flights[i].cost << endl;
			cout << "���������� ���������� ����: " << flights[i].number_of_seats << endl;
			cout << "___________________________________________________________________" << endl;
	}
}

void removal(flights* flights, int amount) {//�������� ������ �� ���� ������
	
	system("cls");
	string name_del;
	cout << "������� ����� �����, ������� ������� ������� �� ���� ������: ";
	cin >> name_del;

	int count = 0;
	
	for (int i = 0; i < amount; i++)
	{
		if (name_del == flights[i].flight_number)
		{
			flights[i].~flights();
			cout << "�������!" << endl;
			count++;
			break;
		}
	}

	if (count == 0)
		cout << "���� �� ������!\n";
}

void search(flights* flights, int amount) {//����� ����� �� ���� ������
	
	system("cls");
	string year;
	int count = 0;
	
	cout << "������� ����� ������, �� �������� ����� ����������� �����: ";
		cin >> year;

		cin.ignore();
		while (!isProved(year))
		{
			cout << "������� ���������� ����� ������, �� �������� ����� ����������� �����: ";
			cin >> year;
		}
	
	for (int i = 0; i < amount; i++)
	{
		if (flights[i].date.dd == stoi(year))
		{
			cout << "����� ���������: " << flights[i].flight_number << endl;
		
			if (flights[i].punct == 0)
			{
				cout << "����� ����������: ����" << endl;
			}

			if (flights[i].punct == 1)
			{
				cout << "����� ����������: �������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 2)
			{
				cout << "����� ����������: ������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 3)
			{
				cout << "����� ����������: �������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 4)
			{
				cout << "����� ����������: ������" << flights[i].punct << endl;
			}

			if (flights[i].punct == 5)
			{
				cout << "����� ����������: -" << endl;
			}
			
			cout << "���� ������: " << flights[i].date.dd << '.' << flights[i].date.mm <<'.'<< flights[i].date.yyyy << endl;
			cout << "����� ������: " << flights[i].departure_time << "\n";
			cout << "��������� ������: " << flights[i].cost << endl;
			cout << "���������� ���������� ����: " << flights[i].number_of_seats << endl;
			cout << "___________________________________________________________________" << endl;
			count++;
		}
	}
	
	if (count == 0) {
		cout << "�������� �� ������!\n\n";
	}

}

