//Разработать лямбда-функцию, которая принимает две строки и возвращает ту строку, которая длиннее.
#include <iostream>
#include <string>
using namespace std;



void main()
{
	setlocale(LC_ALL, "Rus");
	string str1 = "Hello, how are you?!"; //строка один
	string str2 = "I'm well, and how are you?"; //строка два
	
	int size_1 = str1.size();
	int size_2 = str2.size();

	auto f = [=]()
	{
		if (size_1>size_2)
		{
			for (char i : str1)
			{
				cout << i;
			}
			cout << endl;
		}

		else if (size_1 < size_2)
		{
			for (char i : str2)
			{
				cout << i;
			}
			cout << endl;
		}
		else
		{
			cout << "Строки равны! " << endl;
		}
	};

	f();




}
