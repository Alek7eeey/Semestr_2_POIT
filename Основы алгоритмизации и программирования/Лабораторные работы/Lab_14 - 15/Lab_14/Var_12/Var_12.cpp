// ============================= ������� 12 ================================
//����������� ������������ ���-������� ��� �������� �����. 
//������� ������ ����������� ���� ������ ����� ��� ���������� 50% ����������.

#include "Hash.h"
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	/*AA* a1 = new  AAA{1, (char*)"one"};
	AAA* a12 = new  AAA{ 1, (char*)"one2" };
	AAA* a13 = new  AAA{ 1, (char*)"one3" };
	AAA* a2 = new  AAA{ 2, (char*)"two" };
	AAA* a3 = new  AAA{ 3, (char*)"three" };
	AAA* a4 = new  AAA{ 4, (char*)"four" };
	AAA* a42 = new  AAA{ 4, (char*)"four2" };
	AAA* a5 = new  AAA{ 5, (char*)"five" };
	AAA* a6 = new  AAA{ 6, (char*)"six" };
	AAA* a62 = new  AAA{ 6, (char*)"six2" };
	AAA* a7 = new  AAA{ 7, (char*)"seven" };
	AAA* a8 = new  AAA{ 8, (char*)"eight" };
	AAA* a71 = new  AAA{ 7, (char*)"seven1" };
	AAA* a72 = new  AAA{ 7, (char*)"seven2" };
	AAA* a73 = new  AAA{ 7, (char*)"seven3" };
	AAA* a81 = new  AAA{ 8, (char*)"eight2" };*/
	int siz = 16, choice, k;
	cout << "������� ������ ���-�������" << endl; 	cin >> siz;
	Object H = create(siz, key);
	/*H.insert(a0);
	H.insert(a1);
	H.insert(a12);
	H.insert(a13);
	H.insert(a2);
	H.insert(a3);
	H.insert(a4);
	H.insert(a42);
	H.insert(a5);
	H.insert(a6);
	H.insert(a62);
	H.insert(a7);
	H.insert(a8);
	H.insert(a71);
	H.insert(a81);
	H.insert(a72);*/
	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);

			break;
		case 2: { AAA* a = new AAA;
			char* str = new char[20];
			cout << "������� ����" << endl;	cin >> k;
			a->key = k;
			cout << "������� ������" << endl; cin >> str;
			a->mas = str;
			cout << H.N << " " << H.size << endl;

			if ((double)H.N > ((double)(H.size) * 0.5F)) // 12 ������� // if ((double)H.N > (double)(H.size) * 0.7) ----- 14 �������
			{
				cout << "������� ��������� �� 50%(50% = " << ((double)(H.size) * 0.5) << " ���������� ��������� � ������� " << H.N << ") ����������� � 2 ����" << endl;
				Object H1 = create(H.size * 2, key); //	Object H1 = create(H.size*3, key); ------ 14 �������
				for (int i = 0; i < H.size; i++)
				{
					H1.data[i] = H.data[i];
				}
				H1.N = H.N;
				H1.insert(a);
				H = H1;
			}
			else
				H.insert(a);
		} break;
		case 3: {  cout << "������� ���� ��� ��������" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "������� ���� ��� ������" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "������� �� ������" << endl;
			else
				AAA_print(H.search(k));
		}  break;
		}
	}
	return 0;
}