/*�������� ������� prost � ���������� ������ ����������,
������� ������� ��� ������� ����� �� ����������. 
��������� �������� ��������� a � b. 
� ������� ���� ������� ��������� ��������� ����������.*/

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



        // ���� = 1 ��������, ��� � �����

        // � ���� = 0 ��������, ��� � �� �����

        if (flag == 1)

            cout << i << " ";

    }
    
}

void main()
{
    setlocale(LC_ALL, "Rus");
    int start, finish, choice;
    active:
    
    cout << "������� ������ ����� ���������: ";
    cin >> start;

    cout << "������� ������� ����� ���������: ";
    cin >> finish;

    cout << "\n������� ����� ����� " << start << " � " << finish << " : ";

    prost(2, start, finish);

    cout << "\n\n������� ��� ��� ��������� ��������?! (1 - ��, 2 - ���)"<<endl;
    cin >> choice;

    switch (choice)
    {
    case 1: system("cls"); goto active;
    
    case 2: break;
    
    }


    cout << endl << endl;
  

}
   
