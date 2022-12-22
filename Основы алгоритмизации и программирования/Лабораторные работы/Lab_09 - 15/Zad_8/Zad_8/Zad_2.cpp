//������� ������ ������������  �������� ������ �� ������ �� ��������� �����
//������� ������ �������������  �������� ������ �� ������ �� ��������� �����
//������� �������� ����� ��������� ������ � �������� ��������� x.

#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
const unsigned int CITY_SIZE = 20;

struct adress
{
    int id;
    char name[CITY_SIZE];
    adress* next;
    adress* prev;
};

void menu()
{
    cout << endl;
    cout << "1 - ���� ��������\n";
    cout << "2 - �������� �����\n";
    cout << "3 - ����� �� �����\n";
    cout << "4 - �����\n";
    cout << "5 - �������� � ����.\n";
    cout << "6 - ������� �� �����.\n";
    cout << "7 - ����� �����������.\n";
    cout << "8 - ����� ������������.\n";
    cout << "9 - ���������, ������� ��������� ����� ������� ���� ���\n";
    cout << "10 - �����.\n";
}

void insert(adress* e, adress** phead, adress** plast)
{
    adress* p = *plast;
    if (*plast == NULL)
    {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
    }
    else
    {
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
    }
}

adress* setElement()
{
    adress* temp = new adress();
    if (!temp)
    {
        cerr << "������ ��������� ������.";
        return NULL;
    }
    cout << "������� id: ";
    cin >> temp->id;
    cout << "������� ���: ";
    cin >> temp->name;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void outputlist(adress** phead, adress** plast)
{
    adress* t = *phead;
    while (t)
    {
        cout << t->id << " " << t->name << endl;
        t = t->next;
    }
    cout << "\n";
}

void find(int name, adress** phead)
{
    adress* t = *phead;
    while (t)
    {
        if (name == t->id) break;
        t = t->next;
    }
    if (!t)
        cerr << "id �� �������\n";
    else
        cout << t->id << " " << t->name << endl;
}

void delet(int name, adress** phead, adress** plast)
{
    struct adress* t = *phead;
    while (t)
    {
        if (name == t->id) break;
        t = t->next;
    }
    if (!t)
        cerr << "id �� �������.\n";
    else
    {
        if (*phead == t)
        {
            *phead = t->next;
            if (*phead)
            {
                (*phead)->prev = NULL;
            }
            else
                *plast = NULL;
        }
        else
        {
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        cout << "������� �����.\n";
    }

}


void writeToFile(adress** phead)
{
    adress* t = *phead;
    FILE* fp;
    errno_t err = fopen_s(&fp, "mlist.dat", "w");
    if (err)
    {
        cerr << "���� �� �����������." << endl;
        exit(1);
    }
    cout << "���������� � ����.\n";
    while (t)
    {
        fwrite(t, sizeof(adress), 1, fp);
        t = t->next;
    }
    fclose(fp);
}

void readFromFile(adress** phead, adress** plast)
{
    adress* t;
    FILE* fp;
    errno_t err = fopen_s(&fp, "mlist.dat", "rb");
    if (err)
    {
        cout << "���� �� �����������.\n";
        exit(1);
    }
    while (*phead)
    {
        *plast = (*phead)->next;
        delete* phead;
        *phead = *plast;
    }
    *phead = *plast = NULL;
    cout << "�������� �� �����" << endl;
    while (!feof(fp))
    {
        t = new adress();
        if (!t)
        {
            cerr << "������ ��������� ������.\n";
        }
        if (1 != fread(t, sizeof(adress), 1, fp)) break;
        insert(t, phead, plast);
    }
    fclose(fp);
}

void findMin(adress** phead)
{
    adress* t = *phead;
    int min = t->id;
    while (t != NULL)
    {
        if (t->id < min)
        {
            min = t->id;
        }
        t = t->next;

    }
    cout << "����������� id: " << min << endl;
}

void findMax(adress** phead)
{
    adress* t = *phead;
    int max = t->id;
    while (t != NULL)
    {
        if (t->id > max)
        {
            max = t->id;
        }
        t = t->next;

    }
    cout << "������������ id: " << max << endl;
}

void countX(adress** phead, char k[CITY_SIZE])
{
    adress* t = *phead;
    int count = 0;
    while (t != NULL)
    {
        if (!strcmp(k, t->name))
        {
            count++;
        }
        t = t->next;

    }
    cout << "��������� � ������ " << k << " � ����� ������ " << count << " ����\n";
}


void main()
{
    adress* head = NULL;
    adress* last = NULL;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choise;
    char k[CITY_SIZE];
    menu();
    cout << endl;
    cin >> choise;
    while (choise != 10)
    {
        switch (choise)
        {
        case 1: insert(setElement(), &head, &last);
            break;
        case 2: int dname;
            outputlist(&head, &last);
            cout << "������� id: ";
            cin >> dname;
            delet(dname, &head, &last);
            break;
        case 3: outputlist(&head, &last);
            break;
        case 4: int fname;
            cout << "������� id: ";
            cin >> fname;
            find(fname, &head);
            break;
        case 5:
            writeToFile(&head);
        case 6: readFromFile(&head, &last); break;
        case 7: findMin(&head); break;
        case 8: findMax(&head); break;
        case 9: cout << "������� �������� ��������: "; cin >> k;
            countX(&head, k);
        }
        menu();
        cout << "\n";
        cin >> choise;
    }

}



