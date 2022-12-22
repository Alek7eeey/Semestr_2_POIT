/*Разработать лямбда-функцию, которая принимает две строки и возвращает конкатенацию этих строк.*/
#include <iostream>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	string str1 = "Programming ";
	string str2 = "language C/C++";

	auto foo = [](string str1, string str2) {
	
		string str3 = str1 + str2;
		return str3;

	};

	string str = foo(str1, str2);

	for (auto s : str)
	{
		cout << s;
	}

	cout << endl;
}