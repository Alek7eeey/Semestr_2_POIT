/*Ученики. Ф.И.О., класс (цифра+буква),
предметы, оценки, средний балл. Выбор по среднему баллу. */

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

	cout << "Информация об учениках.\n";
	int choice;
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск информации (по среднему баллу) \n";
		cout << "4.Удаление информации из файла\n";
		cout << "5.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			for (int i = 0; i < size; i++)
			{
				clear;

				cout << "Информация про ученика номер " << i + 1 << "." << endl;

				cout << "Введите имя: ";
				cin >> information_about_pupils[i].name;
				cout << endl;
				cout << "Введите фамилию: ";
				cin >> information_about_pupils[i].surname;
				cout << endl;
				cout << "Введите отчество: ";
				cin >> information_about_pupils[i].fatherland;
				cout << endl;

				cout << "Введите класс(цифра + буква): ";
				cin >> information_about_pupils[i].class_of_student;
				cout << endl;

				cout << "Введите предмет номер 1: ";
				cin >> information_about_pupils[i].subjects_of_students.first_sub;
				cout << endl;
				cout << "Введите предмет номер 2: ";
				cin >> information_about_pupils[i].subjects_of_students.second_sub;
				cout << endl;
				cout << "Введите предмет номер 3: ";
				cin >> information_about_pupils[i].subjects_of_students.third_sub;

				cout << endl;
				cout << "Введите оценку за " << information_about_pupils[i].subjects_of_students.first_sub << " : ";
				cin >> information_about_pupils[i].marks_of_students.mark_n1;
				cout << endl;
				cout << "Введите оценку за: " << information_about_pupils[i].subjects_of_students.second_sub << " : ";
				cin >> information_about_pupils[i].marks_of_students.mark_n2;
				cout << endl;
				cout << "Введите оценку за: " << information_about_pupils[i].subjects_of_students.third_sub << " : ";
				cin >> information_about_pupils[i].marks_of_students.mark_n3;
				cout << endl;
				GPA[i] = (information_about_pupils[i].marks_of_students.mark_n1 + information_about_pupils[i].marks_of_students.mark_n2 + information_about_pupils[i].marks_of_students.mark_n3) / 3;
			}
			ofstream fout;
			fout.open(name_of_file);

			if (!fout.is_open())
			{
				cout << "Ошибка! " << endl;
			}

			else
			{
				for (int i = 0; i < size; i++)
				{
					fout << "Номер ученика: " << i + 1 << endl;
					fout << "Имя: " << information_about_pupils[i].name << endl;
					fout << "Фамилия: " << information_about_pupils[i].surname << endl;
					fout << "Отчество: " << information_about_pupils[i].fatherland << endl;
					fout << "Класс: " << information_about_pupils[i].class_of_student << endl;
					fout << "Предмет номер 1 - " << information_about_pupils[i].subjects_of_students.first_sub << ", оценка: " << information_about_pupils[i].marks_of_students.mark_n1 << endl;
					fout << "Предмет номер 2 - " << information_about_pupils[i].subjects_of_students.second_sub << ", оценка: " << information_about_pupils[i].marks_of_students.mark_n2 << endl;
					fout << "Предмет номер 3 - " << information_about_pupils[i].subjects_of_students.third_sub << ", оценка: " << information_about_pupils[i].marks_of_students.mark_n3 << endl;
					fout << "Средний балл: " << GPA[i] << endl;
					fout << "_______________________________________________" << endl;
				}
			}
			fout.close();
			clear;

			cout << "Строка(и) записаны" << endl;
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
				cout << "Ошибка! " << endl;
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
				cout << "Ошибка! " << endl;
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

			cout << "Введите средний балл ";
			cin >> sr_ball;

			cout << "\n1 - Вывести учеников со среднем баллом больше " << sr_ball << endl;
			cout << "\n2 - Вывести учеников со среднем баллом меньше " << sr_ball << endl;
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

						cout << "Номер ученика: " << i + 1 << endl;
						cout << "Имя: " << information_about_pupils[i].name << endl;
						cout << "Фамилия: " << information_about_pupils[i].surname << endl;
						cout << "Отчество: " << information_about_pupils[i].fatherland << endl;
						cout << "Класс: " << information_about_pupils[i].class_of_student << endl;
						cout << "Средний балл: " << GPA[i] << endl;
						cout << "_______________________________________________" << endl;
						fi++;
					}

					if (i == size-1 && fi == 0)
					{
						cout << "Учащихся с таким средним баллом нету!" << endl;
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

						cout << "Номер ученика: " << i + 1 << endl;
						cout << "Имя: " << information_about_pupils[i].name << endl;
						cout << "Фамилия: " << information_about_pupils[i].surname << endl;
						cout << "Отчество: " << information_about_pupils[i].fatherland << endl;
						cout << "Класс: " << information_about_pupils[i].class_of_student << endl;
						cout << "Средний балл: " << GPA[i] << endl;
						cout << "_______________________________________________" << endl;
						fi++;
					}

					if (i == size-1 && fi == 0)
					{
						cout << "Учащихся с таким средним баллом нету!" << endl;
					}

				}
				break;
			}

			}
			break;
		}
		case 4: {

			int d;
			cout << "\nНомер учащегося, про которого необходимо удалить информацию(для удаления всех строк нажать 99)" << endl;
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
				cout << "Ошибка! " << endl;
			}

			else
			{
				for (int i = 0; i < size; i++)
				{
					fout << "Номер ученика: " << i + 1 << endl;
					fout << "Имя: " << information_about_pupils[i].name << endl;
					fout << "Фамилия: " << information_about_pupils[i].surname << endl;
					fout << "Отчество: " << information_about_pupils[i].fatherland << endl;
					fout << "Класс: " << information_about_pupils[i].class_of_student << endl;
					fout << "Предмет номер 1 - " << information_about_pupils[i].subjects_of_students.first_sub << ", оценка: " << information_about_pupils[i].marks_of_students.mark_n1 << endl;
					fout << "Предмет номер 2 - " << information_about_pupils[i].subjects_of_students.second_sub << ", оценка: " << information_about_pupils[i].marks_of_students.mark_n2 << endl;
					fout << "Предмет номер 3 - " << information_about_pupils[i].subjects_of_students.third_sub << ", оценка: " << information_about_pupils[i].marks_of_students.mark_n3 << endl;
					fout << "Средний балл: " << GPA[i] << endl;
					fout << "_______________________________________________" << endl;
				}
			}
			fout.close();

			clear;
			cout << "Строка(ки) удалены!";
			break;
		};


		case 5:
		{
			clear;
			cout << "Пока!"<<endl;
			exit(0);  break;
		};
		}
	
	} while (choice != 5);
}


