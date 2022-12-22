/*Написать функцию prost с переменным числом параметров,
которая находит все простые числа из интервалов. 
Интервалы задаются границами a и b. 
С помощью этой функции проверить несколько интервалов.*/

#include <iostream>

using namespace std;

void prost(int a,...)
{
    int* p = &a;
    
    for (int i = *(p+1); i < *(p+2); i++)
    {
        if (i == 1 || i == 0) {
            continue;
        }
        int flag = 1;

        for (int j = 2; j <= i / 2; ++j)

        {
            if (i % j == 0)
            {

                flag = 0;
                break;

            }

        }



        // флаг = 1 означает, что я прост

        // и флаг = 0 означает, что я не прост

        if (flag == 1)

            cout << i << " ";

    }
    
}

void main()
{
    setlocale(LC_ALL, "Rus");
    int start, finish, choice;
    active:
    
    cout << "Введите нижний порог интервала: ";
    cin >> start;

    cout << "Введите верхний порог интервала: ";
    cin >> finish;

    cout << "\nПростые числа между " << start << " и " << finish << " : ";

    prost(2, start, finish);

    cout << "\n\nЖелаете ещё раз выполнить проверку?! (1 - ДА, 2 - НЕТ)"<<endl;
    cin >> choice;

    switch (choice)
    {
    case 1: system("cls"); goto active;
    
    case 2: break;
    
    }


    cout << endl << endl;
  

}
   
