
#include <iostream>
#include "heap.h"
using namespace std;
using namespace heap;

heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP
        rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else if (A2->x > A1->x)
        rc = heap::LESS;
    return rc;
#undef A2
#undef A1
}

int main()
{
    setlocale(LC_ALL, "rus");
    int k, choice, i;
    heap::Heap h1 = heap::create(30, cmpAAA);
    heap::Heap h2 = heap::create(30, cmpAAA);
    do
    {
        cout << "1 - ����� ���� �� �����\n";  //����� ���� �� �����
        cout << "2 - �������� �������\n";
        cout << "3 - ������� ������������ �������\n";
        cout << "4 - ������� ����������� �������\n";
        cout << "5 - ������� i-�� �������\n";
        cout << "6 - �������� ������� � ���� 2\n";
        cout << "7 - ����� ���� 2 �� �����\n";
        cout << "8 - ��������� �������� �� 2 ���� � 1��\n";
        cout << "0 - �����\n";
        cout << "�������� �����: "; cin >> choice;
        switch (choice)
        {
        case 0: break;
        case 1: h1.scan(0); break;
        case 2: {
            AAA* a = new AAA;
            cout << "������ ����: "; cin >> k;
            a->x = k;
            h1.insert(a);
        } break;
        case 3: h1.extractMax();
            break;
        case 4: h1.extractMin(); break;
        case 5: cout << "������� ���������� ����� ��������: "; cin >> i;
            h1.extractIt(i); break;
        case 6: {
            AAA* a = new AAA;
            cout << "������ ����: "; cin >> k;
            a->x = k;
            h2.insert(a);
        } break;
        case 7: h2.scan(0); break;
        case 8: unionHeap(&h1, &h2); break;
        default: cout << endl << "������� �������� �������!" << endl;
        }
    } while (choice != 0);
}

