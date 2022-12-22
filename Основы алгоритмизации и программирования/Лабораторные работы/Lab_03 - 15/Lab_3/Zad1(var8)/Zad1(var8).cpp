/*1. ����������� �� ����� FILE1 � ���� FILE2 ��� ������, ����� ��� ������,
� ������� ������ ����� ������� ����. ���������� ����� ���� ������.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");

	char mas[20] = { '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�' }; //������ ���� ������� ����
	string str = "������_����\n������_���\n������_���\n������_������"; //������ � �����

	ofstream f1;
	f1.open("File1.txt"); //�������� ����� 

	if (!f1.is_open())
	{
		cout << "Error!" << endl;
	}

	else
	{
		f1 << str << endl; //���������� ����������� �����

	}
	f1.close();

	ofstream f2;
	f1.open("File2.txt"); //�������� ������� �����

	if (!f1.is_open())
	{
		cout << "Error!" << endl;
	}
	f2.close();

	ifstream fin;
	fin.open("File1.txt"); //���������� ���������� �� ������� �����

	int kol = 0, save_kol = 0, sbu = 0, num = 0;

	if (!f1.is_open())
	{
		cout << "Error!" << endl;
	}

	else
	{
		char ch;
		while (fin.get(ch))   //������������ ���������� �����
		{
			cout << ch;
			for (int j = 0; j < 100; j++)
			{
				if (ch == mas[j]) //�������� �� ������� �����
				{
					kol++; //������� ���������� �������
					break;
				}
			}

			if (ch == '\n') //����� ����� ������
			{
				sbu++;  //������ ������ ������

				if (kol >= save_kol) //����� ������ � ���������� ����������� �������
				{
					num = sbu; //����� ������ � ���������� ����������� �������
					save_kol = kol; // ���������� ������� � ������ � ���������� ����������� �������
				}

				kol = 0;
			}
		}
	}

	cout << "���������� ���������� ������� � ������ ����� " << num << endl;
	fin.close();
	int count = 0, value = 0;

	for (int i = 0; i < 49; i++) //������� ���������� ���� � ������ � ���������� ����������� �������
	{

		if (str[i] == '\n')
		{
			count++;
		}

		if (count == num - 1)
		{
			value++;

			if (str[i] == '\0')
			{
				break;
			}
		}

	}
	value -= 2;

	int sbf = 0, finish_sbu = 0;

	count = 0;

	for (int i = 0; i < 49; i++) //������� ��������� ������� ������ � ���������� ����������� �������
	{
		sbf++;

		if (str[i] == '\n')
		{
			count++;
		}

		if (count == num - 1)
		{
			finish_sbu = sbf;
			break;
		}
	}

	cout << "-----------------------------------" << endl;

	str.erase(finish_sbu, value); //�������� ������ � ���������� ����������� �������

	f2.open("File2.txt"); //������ ������ �� ������ ����

	if (!f2.is_open())
	{
		cout << "Error!" << endl;
	}

	else
	{
		f2 << str;
		cout << "\n������ �������� � ����!";
	}
	f2.close();


	cout << endl << endl;

}