#include<tchar.h>
#include "tree.h"
#include <fstream>
using namespace std;
int main()
{
	setlocale(0, "Russian");
	int key, choice, n, z = 0;
	Tree* rc;
	int c = 0;
	Tree* Root = NULL;
	for (;;)
	{
		cout << endl;
		cout << "1 -�������� ������\n";
		cout << "2 -����� ������\n";
		cout << "3 -�������� �������� c ���������� ������\n";
		cout << "4 -������ � ����\n";
		cout << "5 -������ �� �����\n";
		cout << "6 -������(����������) �����\n"; //�������� ������ ������ ����� ��������� ������ ������ ���������
		cout << "7 -������������(���������) ����� \n"; //������ ����� ��������� �������� ������  ������ ������ ���������
		cout << "8 -��������(����������) �����\n"; //������ ����� ��������� ������ ������ ��������� �������� ������
		cout << "9 -�������� �� ������������������\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2: print(Root, 0); break;
		case 3: Root = delet(Root);  break;

		case 5: print(Root, 0); break;
		case 6:  if (Root->key >= 0)
			view(Root);
			  else cout << "������ ������\n"; break;
		case 7: if (Root->key >= 0)
			view2(Root);
			  else cout << "������ ������\n"; break;
		case 8: if (Root->key >= 0)
			view3(Root);
			  else cout << "������ ������\n"; break;
		case 9:
			if (isBalanced(Root))
				cout << "������ ���������������";
			else
				cout << "������ �����������������";
			break;


		case 4: ofstream file1;
			file1.open("file1.txt");
			insert(Root, 0, file1);
			file1.close();
			break;


			/*case 2: if (Root->key >= 0)
				view(Root);
				  else cout << "������ ������\n"; break;
			case 3: if (Root->key >= 0)
				view2(Root);
				  else cout << "������ ������\n"; break;
			case 4: if (Root->key >= 0)
				view3(Root);
				  else cout << "������ ������\n"; break;


			case 6:
				if (isBalanced(Root))
					cout << "������ ���������������";
				else
					cout << "������ �����������������";
				break;
			case 7: delAll(Root); break;*/

			//case 8: exit(0);
		}
	}
}