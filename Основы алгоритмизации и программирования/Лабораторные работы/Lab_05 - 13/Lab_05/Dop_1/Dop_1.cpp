//Вокзал. Номер поезда, пункт назначения, время прибытия, время отправления. Выбор по пункту назначения.

using namespace std;
#include <iostream>
#include <string>
#include <Windows.h>
#define size 3

void input();
void output();
void searching();

struct trains
{
    char punct[40];
    int data, num, timeStar, timeEnd;
} train[size];

union zapis
{
    char punct[40];
    int data, num, timeStar, timeEnd;
}buf;

int main()
{
    int choise;
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do
    {
        cout << "Введите:\n";
        cout << "1 - для ввода списка поездов\n";
        cout << "2 - для вывода списка поездов\n";
        cout << "3 - для поиска поезда по пункту следования\n";
        cout << "4 - для выхода\n";
        cin >> choise;
        switch (choise)
        {
        case 1: input(); break;
        case 2: output();  break;
        case 3: searching(); break;
        }
    } while (choise != 4);
}

void input()
{
    int day, mont, min, hour;

    for (int i = 0; i < size; i++)
    {
        cout << "Введите номер поезда: "; cin >> train[i].num;
        cout << "Введите пункт назначения: "; cin >> train[i].punct;
        cout << "Введите дату отправления (в формате ДДММ): "; cin >> train[i].data;
        day = train[i].data / 100;
        mont = train[i].data - day * 100;
        if (day > 31 && mont > 12)
        {
            cout << "Вы ввели некорректную дату повторите ввод\n";
            break;
        }
        cout << "Введите время отправления (в формате ЧЧММ): "; cin >> train[i].timeStar;
        hour = train[i].timeStar / 100;
        min = train[i].timeStar - hour * 100;
        if (hour > 12 && min > 60)
        {
            cout << "Вы ввели некорректное время повторите ввод\n";
            break;
        }
        cout << "Введите время прибытия (в формате ЧЧММ): "; cin >> train[i].timeEnd;
        hour = train[i].timeEnd / 100;
        min = train[i].timeEnd - hour * 100;
        if (hour > 12 && min > 60)
        {
            cout << "Вы ввели некорректное время повторите ввод\n";
            break;
        }
        cout << "\n";

    }
}

void output()
{
    for (int i = 0; i < size; i++)
    {
        buf.num = train[i].num;
        cout << "Номер поезда: " << buf.num;
        strcpy_s(buf.punct, train[i].punct);
        cout << " Пункт отправления: " << buf.punct;
        buf.data = train[i].data;
        cout << " Дата отправления: " << buf.data;
        buf.timeStar = train[i].timeStar;
        cout << " Время отправления: " << buf.timeStar;
        buf.timeEnd = train[i].timeEnd;
        cout << " Время прибытия: " << buf.timeEnd;
        cout << "\n";
    }
}

void searching()
{
    bool check = false;
    cout << "Введите пункт назначения, программа найдёт этот поезд: "; cin >> buf.punct;
    for (int i = 0; i < size; i++)
    {
        if (buf.punct[0] == train[i].punct[0] && buf.punct[1] == train[i].punct[1] && buf.punct[2] == train[i].punct[2] && buf.punct[3] == train[i].punct[3])
        {
            buf.num = train[i].num;
            cout << "Номер поезда: " << buf.num;
            strcpy_s(buf.punct, train[i].punct);
            cout << " Пункт отправления: " << buf.punct;
            buf.data = train[i].data;
            cout << " Дата отправления: " << buf.data;
            buf.timeStar = train[i].timeStar;
            cout << " Время отправления: " << buf.timeStar;
            buf.timeEnd = train[i].timeEnd;
            cout << " Время прибытия: " << buf.timeEnd;
            cout << "\n";
            check = true;
        }
    }
    if (check == false)
    {
        cout << "Таких поездов у нас нет.";
    }
}