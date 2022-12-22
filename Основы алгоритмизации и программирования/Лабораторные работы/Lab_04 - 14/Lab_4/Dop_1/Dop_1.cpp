//���������� ��������� ��� ������������� ���������� � ������� ��������� ���������, ���������� ����: ��� ��������, ����� ���������, ���������� ������.
//���������� ������� ��� ��������� ���������� ������� (��������, ��� ��������, ����� �� ��� �������� �� 4 � 5).
//�������� ������� ��� ��������� ������� ��������. � ���������� ��������� ��������� ��������� �������������� ������������ ���������,
//�� ���� ��������� ����� ���������, ������� �������� �� 4 � 5, � ������ ����� ���������, � ���������. 

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
        cout << "�������:\n";
        cout << "1 - ��� ����� ������ ���������\n";
        cout << "2 - ��� �������� ���� �� ������� ������\n";
        cout << "3 - ���������� ������� ������� �������� ������\n";
        cout << "4 - ��� ������\n";
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
        cout << "������� ������� ��������: "; cin >> stud[i].fio;
        cout << "\n������� ���������� ���������: "; cin >> stud[i].excount;
        cout << "\n��������� ������� ��� �������:\n";
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
    cout << "�������� ����� �������� ����� ������, ���� �� �� ������: "; cin >> num;
    num--;

    for (int j = 0; j < stud[num].excount; j++)
    {
        if (stud[num].marks[j] < 4)
        {
            check = false;
        }
    }
    if (check == true)
        cout << "\n���� ������� ������� ���� ������\n\n";
    else
        cout << "\n���� ������� ������ �������\n\n";

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
    cout << "\n\n" << qual << "% ��������� �� ����� ������\n\n\n";
}