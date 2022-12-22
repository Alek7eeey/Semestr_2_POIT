
#include <stdlib.h>
#include <iostream>
using namespace std;


void main()
{
	setlocale(LC_ALL, "Rus");
    int chislo, choice = 0, chislo_PC, otvet, count = 0;
    
    active:
    cout << "Введите число: ";
    cin >> chislo;

    if (chislo >= 1 && chislo <= 2147483647)
    {
        int* arr = new int[chislo];

        for (int i = 0; i < chislo; i++)
        {
            arr[i] = i;
        }

        chislo_PC = chislo / 2;

        while (true)
        {
            count++;

            if (chislo > 1)
                chislo /= 2;
            else
                chislo = 1;

            if (choice == 2)
                chislo_PC -= chislo;

            if (choice == 1)
                chislo_PC += chislo;

            if (choice == 3)
            {
                system("color f5");
                cout << "Количество попыток: " << count-1 << endl;
                break;
            }

            cout << "\n" << arr[chislo_PC] << " - это ваше число?\n";

            cout << "\n1 - мало\n2 - много\n3 - угадал" << endl << endl;
            cin >> choice;
        }

        delete[] arr;
    }

    else
    {
        cout << "Некорректный ввод данных! " << endl;
    }
}