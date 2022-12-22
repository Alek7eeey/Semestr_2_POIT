//Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля: ФИО студента, число экзаменов, полученные оценки.
//Определить функции для обработки отдельного объекта (например, для проверки, сданы ли все экзамены на 4 и 5).
//Написать функцию для обработки массива структур. В результате обработки требуется вычислить характеристику успеваемости студентов,
//то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах. 

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
#define size 2

void enterstud();
void goodmark();
void quality();

struct students
{
    char fio[50];
    int excount;
    int marks[20];

};

struct students stud[size];

int main()
{
    int choise;
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do
    {
        cout << "Введите:\n";
        cout << "1 - для ввода списка студентов\n";
        cout << "2 - для проверки сдал ли студент сессию\n";
        cout << "3 - определить сколько человек завалили сессию\n";
        cout << "4 - для выхода\n";
        cin >> choise;
        switch (choise)
        {
        case 1: enterstud(); break;
        case 2: goodmark(); break;
        case 3: quality(); break;

        }
    } while (choise != 4);

}

void enterstud()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Введите фамилию студента: "; cin >> stud[i].fio;
        cout << "\nВведите количество экзаменов: "; cin >> stud[i].excount;
        cout << "\nПоочерёдно введите все отметки:\n";
        for (int j = 0; j < stud[i].excount; j++)
        {
            cout << j + 1 << ") ";
            cin >> stud[i].marks[j];
        }
    }
}

void goodmark()
{
    int num;
    bool check = true;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ") " << stud[i].fio << endl;
    }
    cout << "\n";
    cout << "Выберите номер студента чтобы узнать, сдал ли он сессию: "; cin >> num;
    num--;

    for (int j = 0; j < stud[num].excount; j++)
    {
        if (stud[num].marks[j] < 4)
        {
            check = false;
        }
    }
    if (check == true)
        cout << "\nЭтот студент успешно сдал сессию\n\n";
    else
        cout << "\nЭтот студент сессию завалил\n\n";

}

void quality()
{

    float qual, bad = 0, raz = size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < stud[i].excount; j++)
        {
            if (stud[i].marks[j] < 4)
            {
                bad++;
                break;
            }
        }
    }
    qual = bad / raz;
    qual = qual * 100;
    cout << "\n\n" << qual << "% студентов не сдали сессию\n\n\n";
}