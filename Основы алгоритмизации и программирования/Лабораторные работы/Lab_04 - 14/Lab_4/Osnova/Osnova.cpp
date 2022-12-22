/*�������. �.�.�., ����� (�����+�����),
��������, ������, ������� ����. ����� �� �������� �����. */

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#define clear system("cls")
using namespace std;


struct subjects {
	string first_sub;
	string second_sub;
	string third_sub;

};

struct marks {
	double mark_n1;
	double mark_n2;
	double mark_n3;
};

struct pupils
{
	string name;
	string surname ;
	string fatherland ;
	string class_of_student ;
	struct subjects subjects_of_students;
	struct marks marks_of_students;
};

struct pupils bad;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int size = 3;

	double GPA[size];
	
	string name_of_file = "information.txt";

	struct pupils information_about_pupils[size];

	cout << "���������� �� ��������.\n";
	int choice;
	do
	{
		cout << "\n1.���� ������ � ���������� � ������ � ����\n";
		cout << "2.����� ������ �� �����\n";
		cout << "3.����� ���������� (�� �������� �����) \n";
		cout << "4.�������� ���������� �� �����\n";
		cout << "5.����� �� ���������\n\n";
		cout << "������� ����� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			for (int i = 0; i < size; i++)
			{
				clear;

				cout << "���������� ��� ������� ����� " << i + 1 << "." << endl;

				cout << "������� ���: ";
				cin >> information_about_pupils[i].name;
				cout << endl;
				cout << "������� �������: ";
				cin >> information_about_pupils[i].surname;
				cout << endl;
				cout << "������� ��������: ";
				cin >> information_about_pupils[i].fatherland;
				cout << endl;

				cout << "������� �����(����� + �����): ";
				cin >> information_about_pupils[i].class_of_student;
				cout << endl;

				cout << "������� ������� ����� 1: ";
				cin >> information_about_pupils[i].subjects_of_students.first_sub;
				cout << endl;
				cout << "������� ������� ����� 2: ";
				cin >> information_about_pupils[i].subjects_of_students.second_sub;
				cout << endl;
				cout << "������� ������� ����� 3: ";
				cin >> information_about_pupils[i].subjects_of_students.third_sub;

				cout << endl;
				cout << "������� ������ �� " << information_about_pupils[i].subjects_of_students.first_sub << " : ";
				cin >> information_about_pupils[i].marks_of_students.mark_n1;
				cout << endl;
				cout << "������� ������ ��: " << information_about_pupils[i].subjects_of_students.second_sub << " : ";
				cin >> information_about_pupils[i].marks_of_students.mark_n2;
				cout << endl;
				cout << "������� ������ ��: " << information_about_pupils[i].subjects_of_students.third_sub << " : ";
				cin >> information_about_pupils[i].marks_of_students.mark_n3;
				cout << endl;
				GPA[i] = (information_about_pupils[i].marks_of_students.mark_n1 + information_about_pupils[i].marks_of_students.mark_n2 + information_about_pupils[i].marks_of_students.mark_n3) / 3;
			}
			ofstream fout;
			fout.open(name_of_file);

			if (!fout.is_open())
			{
				cout << "������! " << endl;
			}

			else
			{
				for (int i = 0; i < size; i++)
				{
					fout << "����� �������: " << i + 1 << endl;
					fout << "���: " << information_about_pupils[i].name << endl;
					fout << "�������: " << information_about_pupils[i].surname << endl;
					fout << "��������: " << information_about_pupils[i].fatherland << endl;
					fout << "�����: " << information_about_pupils[i].class_of_student << endl;
					fout << "������� ����� 1 - " << information_about_pupils[i].subjects_of_students.first_sub << ", ������: " << information_about_pupils[i].marks_of_students.mark_n1 << endl;
					fout << "������� ����� 2 - " << information_about_pupils[i].subjects_of_students.second_sub << ", ������: " << information_about_pupils[i].marks_of_students.mark_n2 << endl;
					fout << "������� ����� 3 - " << information_about_pupils[i].subjects_of_students.third_sub << ", ������: " << information_about_pupils[i].marks_of_students.mark_n3 << endl;
					fout << "������� ����: " << GPA[i] << endl;
					fout << "_______________________________________________" << endl;
				}
			}
			fout.close();
			clear;

			cout << "������(�) ��������" << endl;
			cin.ignore();
			break;

		};

		case 2: {
			
			clear;
			ifstream fin;
			fin.open(name_of_file);

			string str;

			if (!fin.is_open())
			{
				cout << "������! " << endl;
			}
			else
			{
				while (!fin.eof())
				{
					str = " ";
					getline(fin, str);
					cout << str << endl;
				}
			}
			fin.close();
			break;
		}
		case 3: 
		{
			clear;

			ifstream fin;
			fin.open(name_of_file);

			char ch;
			int count = 0, index = 0;

			if (!fin.is_open())
			{
				cout << "������! " << endl;
			}
			else
			{
				while (fin.get(ch))
				{
					if (ch == ':')
					{
						count++;
					}

					if (count == 9)
					{
						if (ch >= '0' && ch <= '9')
						{
							GPA[index] = ch-'0';
							index++;
							count = 0;
						}

						if (index==size)
						{
							break;
						}
					}
					
				}
			}
			fin.close();

			
			int sr_ball;
			int choice_2;

			cout << "������� ������� ���� ";
			cin >> sr_ball;

			cout << "\n1 - ������� �������� �� ������� ������ ������ " << sr_ball << endl;
			cout << "\n2 - ������� �������� �� ������� ������ ������ " << sr_ball << endl;
			cin >> choice_2;

			cout << endl;

			switch (choice_2)
			{
			case 1: {

				int fi = 0;
				clear;

				for (int i = 0; i < size; i++)
				{
					if (GPA[i] > sr_ball)
					{

						cout << "����� �������: " << i + 1 << endl;
						cout << "���: " << information_about_pupils[i].name << endl;
						cout << "�������: " << information_about_pupils[i].surname << endl;
						cout << "��������: " << information_about_pupils[i].fatherland << endl;
						cout << "�����: " << information_about_pupils[i].class_of_student << endl;
						cout << "������� ����: " << GPA[i] << endl;
						cout << "_______________________________________________" << endl;
						fi++;
					}

					if (i == size-1 && fi == 0)
					{
						cout << "�������� � ����� ������� ������ ����!" << endl;
					}


				}
				break;
			}

			case 2: {

				int fi = 0;
				clear;

				for (int i = 0; i < size; i++)
				{

					if (GPA[i] < sr_ball)
					{

						cout << "����� �������: " << i + 1 << endl;
						cout << "���: " << information_about_pupils[i].name << endl;
						cout << "�������: " << information_about_pupils[i].surname << endl;
						cout << "��������: " << information_about_pupils[i].fatherland << endl;
						cout << "�����: " << information_about_pupils[i].class_of_student << endl;
						cout << "������� ����: " << GPA[i] << endl;
						cout << "_______________________________________________" << endl;
						fi++;
					}

					if (i == size-1 && fi == 0)
					{
						cout << "�������� � ����� ������� ������ ����!" << endl;
					}

				}
				break;
			}

			}
			break;
		}
		case 4: {

			int d;
			cout << "\n����� ���������, ��� �������� ���������� ������� ����������(��� �������� ���� ����� ������ 99)" << endl;
			cin>>d;

			int co = size;

			if (d != 99)
			{
				for (int i = 0; i < co; i++)
				{	
					if (i==d-1)
					{
						information_about_pupils[i] = bad;
						GPA[i] = 0;
					}
				}
			}
			if (d == 99)
			{
				for (int i = 0; i < co; i++)
				{
					information_about_pupils[i] = bad;
					GPA[i] = 0;
				}
			}

			ofstream fout;
			fout.open(name_of_file);

			if (!fout.is_open())
			{
				cout << "������! " << endl;
			}

			else
			{
				for (int i = 0; i < size; i++)
				{
					fout << "����� �������: " << i + 1 << endl;
					fout << "���: " << information_about_pupils[i].name << endl;
					fout << "�������: " << information_about_pupils[i].surname << endl;
					fout << "��������: " << information_about_pupils[i].fatherland << endl;
					fout << "�����: " << information_about_pupils[i].class_of_student << endl;
					fout << "������� ����� 1 - " << information_about_pupils[i].subjects_of_students.first_sub << ", ������: " << information_about_pupils[i].marks_of_students.mark_n1 << endl;
					fout << "������� ����� 2 - " << information_about_pupils[i].subjects_of_students.second_sub << ", ������: " << information_about_pupils[i].marks_of_students.mark_n2 << endl;
					fout << "������� ����� 3 - " << information_about_pupils[i].subjects_of_students.third_sub << ", ������: " << information_about_pupils[i].marks_of_students.mark_n3 << endl;
					fout << "������� ����: " << GPA[i] << endl;
					fout << "_______________________________________________" << endl;
				}
			}
			fout.close();

			clear;
			cout << "������(��) �������!";
			break;
		};


		case 5:
		{
			clear;
			cout << "����!"<<endl;
			exit(0);  break;
		};
		}
	
	} while (choice != 5);
}


