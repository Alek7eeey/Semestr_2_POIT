//������ � ���������� ������ ��������, ��������� �� ���� � ����, ����������� ���������, � �������� �� � ����. ��������� �� ����� ������, ���������� ���������� �������� � ����� ������� ����� � ������� ���.
//������ �� ���������� " hellow 123 how are you 24 "
#include <fstream>
#include <iostream>
using namespace std;
void main()
{

    setlocale(LC_ALL, "rus");
    cout << "������� ������: ";
    char buff[50], mx[50], max = 0;
    char S[255];// ����� ��� �������� ������������ �� ����� ������
    ofstream fout("File1.txt");   // �������� ������� fout ������ ofstream ��� ������ 
    cin.getline(S, 255); //���������� � S �� ��� ����� � ����������
    fout << S << endl; //�������� S � ���� � �������� ������� ������
    fout.close();
    fout.close();
    ifstream fin("File1.txt");    // �������� ������� fin ������ ifstream ��� ������  
    if (!fin.is_open())
        cout << "���� �� ����� ���� ������!\n";
    else
    {
        cout << "����� ������� �����: ";
        for (int i = 0; i < 7; i++) {
            fin.getline(buff, 50, ' ');
            if (i == 0 || max < strlen(buff)) {
                max = strlen(buff);
                for (int c = 0; c < strlen(buff); c++) {
                    mx[c] = buff[c];
                    cout << mx[c];
                }
                cout << endl << strlen(buff);
            }


        }

        fin.close();


    }
}