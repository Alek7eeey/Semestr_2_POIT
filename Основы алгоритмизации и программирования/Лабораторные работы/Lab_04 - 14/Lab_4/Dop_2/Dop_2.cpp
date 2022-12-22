//������� ��������� � ������ TRAIN, ���������� ����: �������� ������ ����������, ����� ������, ����� �����������.
//�������� ���������, ����������� ���� � ���������� ������ � ������, ��������� �� ������ ��������� ���� TRAIN
//(������ ������ ���� ��������� � ���������� ������� �� ��������� ������� ����������); ����� �� ����� ���������� � �������,
//�������������� ����� ���������� � ���������� ������� (���� ����� ������� ���, �� ������� ��������� �� ����).

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
        cout << "�������:\n";
        cout << "1 - ��� ����� ������ �������\n";
        cout << "2 - ��� ������ ������ ������� � ����������� �������\n";
        cout << "3 - ����������, ����� ������ ������������ ����� ��������� �������\n";
        cout << "4 - ��� ������\n";
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

        cout << "\n������� �������� ����� ����������: "; cin >> train[i].punct;
        cout << "\n������� ����� ������: "; cin >> train[i].number;
        cout << "\n������� ����� ����������� ������(� ������� ����): "; cin >> train[i].timeOf;
        hours = train[i].timeOf / 100;
        minutes = (train[i].timeOf - hours * 100);
        if (hours > 24 || minutes > 60)
        {
            cout << "�� ������ ������� ���������� ����� �� ������ 2400 � �������� �� �� ������ ��������� 60\n";
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
        cout << "����� �����������: " << train[i].punct << " ����� �����: " << train[i].number << " ������ ��������: " << train[i].timeOf << endl;
    }
    cout << "\n\n";
}

void timecheck()
{
    int hours, minutes, time;
    bool check = false;
    cout << "\n������� ����� ����������� ������(� ������� ����): "; cin >> time;
    hours = time / 100;
    minutes = (time - hours * 100);
    if (hours > 24 || minutes > 60)
    {
        cout << "�� ������ ������� ���������� ����� �� ������ 2400 � �������� �� �� ������ ��������� 60\n";
        exit(0);
    }
    cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        if (train[i].timeOf > time)
        {
            cout << "����� �����������: " << train[i].punct << " ����� �����: " << train[i].number << " ������ ��������: " << train[i].timeOf << endl;
            check = true;
        }
    }
    if (check == false)
        cout << "C������ ��� ������ ��� ����((\n\n";
    cout << "\n\n";
}