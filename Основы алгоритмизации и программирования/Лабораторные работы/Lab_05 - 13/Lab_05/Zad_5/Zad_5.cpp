//Авиарейсы. Номер рейса, пункт назначения, время вылета, дата вылета, стоимость билета, количество мест. Выбор по пункту назначения. 

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
        cout << "Введите:\n";
        cout << "1 - для ввода списка авиарейсов\n";
        cout << "2 - для вывода списка авиарейсов\n";
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
        cout << "Введите номер самолёта: ";
      /*  string b;
        getline(cin, b);
        
        cin.ignore();
        while (!isProved(b))
        {
            cout << "Введите корректное число вылета, по которому нужно осуществить поиск: ";
            getline(cin, b);*/
        /*}*/
        cin>> plane[i].num;

        cout << "Введите пункт назначения: "; 
        cin >> plane[i].punct;
        cout << "Введите дату отправления (в формате ДДММ): "; cin >> plane[i].data;
        day = plane[i].data / 100;
        mont = plane[i].data - day * 100;
        if (day > 31 && mont > 12)
        {
            cout << "Вы ввели некорректную дату повторите ввод\n";
            break;
        }
        cout << "Введите время отправления (в формате ЧЧММ): "; cin >> plane[i].timeStar;
        hour = plane[i].timeStar / 100;
        min = plane[i].timeStar - hour * 100;
        if (hour > 12 && min > 60)
        {
            cout << "Вы ввели некорректное время повторите ввод\n";
            break;
        }
        cout << "Введите стоимость билта: "; cin >> plane[i].cost;
        cout << "Введтие количество мест: "; cin >> plane[i].chairs;
        cout << "\n";

    }
}

void output()
{
    for (int i = 0; i < size; i++)
    {
        buf.num = plane[i].num;
        cout << "Номер самолёта: " << buf.num;
        strcpy_s(buf.punct, plane[i].punct);
        cout << " Пункт отправления: " << buf.punct;
        buf.data = plane[i].data;
        cout << " Дата отправления: " << buf.data;
        buf.timeStar = plane[i].timeStar;
        cout << " Время отправления: " << buf.timeStar;
        buf.cost = plane[i].cost;
        cout << " Цена билета: " << buf.cost;
        buf.chairs = plane[i].chairs;
        cout << " Количество мест: " << buf.chairs;
        cout << "\n";
    }
}

void searching()
{
    bool check = false;
    cout << "Введите пункт назначения, программа найдёт этот самолёт: "; cin >> buf.punct;
    for (int i = 0; i < size; i++)
    {
        if (buf.punct[0] == plane[i].punct[0] && buf.punct[1] == plane[i].punct[1] && buf.punct[2] == plane[i].punct[2] && buf.punct[3] == plane[i].punct[3])
        {
            buf.num = plane[i].num;
            cout << "Номер самолёта: " << buf.num;
            strcpy_s(buf.punct, plane[i].punct);
            cout << " Пункт отправления: " << buf.punct;
            buf.data = plane[i].data;
            cout << " Дата отправления: " << buf.data;
            buf.timeStar = plane[i].timeStar;
            cout << " Время отправления: " << buf.timeStar;
            buf.cost = plane[i].cost;
            cout << " Цена билета: " << buf.cost;
            buf.chairs = plane[i].chairs;
            cout << " Количество мест: " << buf.chairs;
            cout << "\n";
            check = true;
        }
    }
    if (check == false)
    {
        cout << "Таких рейсов у нас нет.";
    }
}