/*2. Даны два файла целых чисел, содержащие элементы матрицы A
размерности nxn и B размерности n x 1 по строкам,
причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы.
Создать файл той же структуры с именем C, содержащий произведение матриц А и В.*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

bool isProved(char* num)
{
    char nums[] = "0123456789";
    bool isNotNum = false;

    for (int i = 0; num[i] != '\0'; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (num[i] == nums[j])
            {
                isNotNum = false;
                break;
            }
            else
            {
                isNotNum = true;
            }
        }

        if (isNotNum)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    char n[10]; errno_t err;
    FILE* f;
    FILE* g;
    FILE* q;
   
    printf("Write size of massive: ");
    cin.getline(n, 10);
   
    while (!isProved(n))
    {
        printf("Write size of massive: ");
        cin.getline(n, 10);
    }

    int n_new = atoi(n);

        err = fopen_s(&f, "1.txt", "w"); //создание первого файла

        if (err != 0) {
            return EXIT_FAILURE; //Макрос EXIT_FAILURE используется для возвращения ОС кода о неудачном завершении программы.
        }

        int** mas = new int* [n_new];
        for (int i = 0; i < n_new; i++)
        {
            mas[i] = new int[n_new];
        }

        for (int i = 0; i < n_new; i++)
        {
            for (int j = 0; j < n_new; j++)
            {
                mas[i][j] = rand() % 10;
                fprintf(f, "%d ", mas[i][j]);
            }
            fprintf(f, "\n");
        }
        fclose(f);

        err = fopen_s(&f, "2.txt", "w"); //создание второго файла
        char r[10];
        printf("Write size of array: ");
        cin.getline(r, 10);

        while (!isProved(r))
        {
            printf("Write size of array: ");
            cin.getline(r, 10);
        }

        int r_new = atoi(r);
       
            int** masarr = new int* [r_new];

            for (int j = 0; j < r_new; j++)
            {
                masarr[j] = new int[1];
            }

            for (int j = 0; j < r_new; j++) {
                masarr[j][0] = rand() % 10;
                fprintf(f, "%d ", mas[j][0]);
                fprintf(f, "\n");
            }
            fclose(f);

            err = fopen_s(&f, "С.txt", "w"); //создать файл с произведением матриц
            int** arrmas = new int* [n_new];

            for (int i = 0; i < n_new; i++)
            {
                arrmas[i] = new int[n_new];
            }

            for (int i = 0; i < n_new; i++)
            {
                arrmas[i][0] = 0;
                for (int j = 0; j < n_new; j++)
                {
                    arrmas[i][0] += mas[i][j] * masarr[j][0];
                }
            }

            for (int i = 0; i < n_new; i++)
            {
                fprintf(f, "%d ", arrmas[i][0]);
                fprintf(f, "\n");
            }

            fclose(f);
}
