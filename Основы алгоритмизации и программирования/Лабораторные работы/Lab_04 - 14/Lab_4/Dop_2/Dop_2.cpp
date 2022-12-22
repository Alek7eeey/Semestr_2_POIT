//Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения, номер поезда, время отправления.
//Написать программу, выполняющую ввод с клавиатуры данных в массив, состоящий из восьми элементов типа TRAIN
//(записи должны быть размещены в алфавитном порядке по названиям пунктов назначения); вывод на экран информации о поездах,
//отправляющихся после введенного с клавиатуры времени (если таких поездов нет, то вывести сообщение об этом).

#include <algorithm>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
#define size 3

void entertrain();
void output();
void timecheck();

struct trains
{
    string punct;
    int number;
    int timeOf;
};

struct trains train[size];

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
        cout << "2 - для вывода списка поездов в авлфавитном порядке\n";
        cout << "3 - определить, какие поезда отправляются позже указаного времени\n";
        cout << "4 - для выхода\n";
        cin >> choise;
        switch (choise)
        {
        case 1: entertrain(); break;
        case 2: output(); break;
        case 3: timecheck(); break;

        }
    } while (choise != 4);

}

void entertrain()
{
    int hours, minutes;

    for (int i = 0; i < size; i++)
    {

        cout << "\nВведите конечный пункт назначения: "; cin >> train[i].punct;
        cout << "\nВведите номер поезда: "; cin >> train[i].number;
        cout << "\nВведите время отправления поезда(в формате ЧЧММ): "; cin >> train[i].timeOf;
        hours = train[i].timeOf / 100;
        minutes = (train[i].timeOf - hours * 100);
        if (hours > 24 || minutes > 60)
        {
            cout << "вы должны вводить корректное время не больше 2400 и значение ММ не должно превышать 60\n";
            break;
        }
    }
}

void output()
{
    string buf;
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (train[i].punct > train[i + 1].punct) {
                buf = train[i].punct;
                train[i].punct = train[i + 1].punct;
                train[i + 1].punct = buf;
            }
        }
    }
    cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Пункт направления: " << train[i].punct << " Поезд номер: " << train[i].number << " Веремя отправки: " << train[i].timeOf << endl;
    }
    cout << "\n\n";
}

void timecheck()
{
    int hours, minutes, time;
    bool check = false;
    cout << "\nВведите время отправления поезда(в формате ЧЧММ): "; cin >> time;
    hours = time / 100;
    minutes = (time - hours * 100);
    if (hours > 24 || minutes > 60)
    {
        cout << "вы должны вводить корректное время не больше 2400 и значение ММ не должно превышать 60\n";
        exit(0);
    }
    cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        if (train[i].timeOf > time)
        {
            cout << "Пункт направления: " << train[i].punct << " Поезд номер: " << train[i].number << " Веремя отправки: " << train[i].timeOf << endl;
            check = true;
        }
    }
    if (check == false)
        cout << "Cегодня все поезда уже ушли((\n\n";
    cout << "\n\n";
}