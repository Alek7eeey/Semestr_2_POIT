#include <iostream>
using namespace std;

enum city {
	Minsk, Brest, Vitebsk, Gomel, Kiev
};

struct travel
{
	city punct;
	int day;
	int month;
}trav;

void main()
{ 
	setlocale(LC_ALL, "Rus");
	trav.punct = Grodno;
	trav.day = 5;
	trav.month = 11;
	cout << "����� ����������: " << trav.punct << endl;
	cout << "���� ��������: " << trav.day << "." << trav.month << endl;
	cin.get();
}