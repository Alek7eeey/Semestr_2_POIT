//���������. ����� �����, ����� ����������, ����� ������, ���� ������, ��������� ������, ���������� ����. ����� �� ������ ����������. 

using namespace std;
#include <iostream>
#include <string>
#include <Windows.h>
#define size 3

//bool isProved(string num)
//{
//	char nums[] = "0123456789";
//	bool isNotNum = false;
//
//	for (int i = 0; i < num.size(); i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (num[i] == nums[j])
//			{
//				isNotNum = false;
//				break;
//			}
//			
//            else
//			{
//				isNotNum = true;
//			}
//		}
//
//		if (isNotNum)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}

void input();
void output();
void searching();

struct planes
{
    char punct[40];
    int data, num, timeStar, cost, chairs;
} plane[size];

union zapis
{
    char punct[40];
    int data, num, timeStar, cost, chairs;
}buf;

int main()
{
    int choise;
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do
    {
        cout << "�������:\n";
        cout << "1 - ��� ����� ������ ����������\n";
        cout << "2 - ��� ������ ������ ����������\n";
        cout << "3 - ��� ������ ������ �� ������ ����������\n";
        cout << "4 - ��� ������\n";
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
        cout << "������� ����� �������: ";
      /*  string b;
        getline(cin, b);
        
        cin.ignore();
        while (!isProved(b))
        {
            cout << "������� ���������� ����� ������, �� �������� ����� ����������� �����: ";
            getline(cin, b);*/
        /*}*/
        cin>> plane[i].num;

        cout << "������� ����� ����������: "; 
        cin >> plane[i].punct;
        cout << "������� ���� ����������� (� ������� ����): "; cin >> plane[i].data;
        day = plane[i].data / 100;
        mont = plane[i].data - day * 100;
        if (day > 31 && mont > 12)
        {
            cout << "�� ����� ������������ ���� ��������� ����\n";
            break;
        }
        cout << "������� ����� ����������� (� ������� ����): "; cin >> plane[i].timeStar;
        hour = plane[i].timeStar / 100;
        min = plane[i].timeStar - hour * 100;
        if (hour > 12 && min > 60)
        {
            cout << "�� ����� ������������ ����� ��������� ����\n";
            break;
        }
        cout << "������� ��������� �����: "; cin >> plane[i].cost;
        cout << "������� ���������� ����: "; cin >> plane[i].chairs;
        cout << "\n";

    }
}

void output()
{
    for (int i = 0; i < size; i++)
    {
        buf.num = plane[i].num;
        cout << "����� �������: " << buf.num;
        strcpy_s(buf.punct, plane[i].punct);
        cout << " ����� �����������: " << buf.punct;
        buf.data = plane[i].data;
        cout << " ���� �����������: " << buf.data;
        buf.timeStar = plane[i].timeStar;
        cout << " ����� �����������: " << buf.timeStar;
        buf.cost = plane[i].cost;
        cout << " ���� ������: " << buf.cost;
        buf.chairs = plane[i].chairs;
        cout << " ���������� ����: " << buf.chairs;
        cout << "\n";
    }
}

void searching()
{
    bool check = false;
    cout << "������� ����� ����������, ��������� ����� ���� ������: "; cin >> buf.punct;
    for (int i = 0; i < size; i++)
    {
        if (buf.punct[0] == plane[i].punct[0] && buf.punct[1] == plane[i].punct[1] && buf.punct[2] == plane[i].punct[2] && buf.punct[3] == plane[i].punct[3])
        {
            buf.num = plane[i].num;
            cout << "����� �������: " << buf.num;
            strcpy_s(buf.punct, plane[i].punct);
            cout << " ����� �����������: " << buf.punct;
            buf.data = plane[i].data;
            cout << " ���� �����������: " << buf.data;
            buf.timeStar = plane[i].timeStar;
            cout << " ����� �����������: " << buf.timeStar;
            buf.cost = plane[i].cost;
            cout << " ���� ������: " << buf.cost;
            buf.chairs = plane[i].chairs;
            cout << " ���������� ����: " << buf.chairs;
            cout << "\n";
            check = true;
        }
    }
    if (check == false)
    {
        cout << "����� ������ � ��� ���.";
    }
}