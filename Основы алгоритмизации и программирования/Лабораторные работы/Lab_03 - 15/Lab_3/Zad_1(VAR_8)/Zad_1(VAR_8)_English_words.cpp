/*1. Скопировать из файла FILE1 в файл FILE2 все строки, кроме той строки,
в которой больше всего гласных букв. Напечатать номер этой строки.*/
#include <fstream>
#include <iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	const char* letters = "eyuioa";
	char buff[100], str[100];
	int valueOfLetters = 0, maxValueOfLetters = 0, number;
	ifstream ifile_1("txt1.txt");
	if (!ifile_1.is_open())
		cout << "Error\n";
	else {
		for (int k = 0; k < 4; k++) {
			ifile_1.getline(buff, 100);
			for (int i = 0; buff[i] != 0; i++) {
				for (int j = 0; letters[j] != 0; j++) {
					if (buff[i] == letters[j])
						valueOfLetters++;
				}
			}
			if (valueOfLetters > maxValueOfLetters) {
				maxValueOfLetters = valueOfLetters;
				number = k + 1;
			}
			valueOfLetters = 0;
		}
		ifile_1.close();
	}
	ofstream ofile_2("txt2.txt");
	ifstream ifile_1_2("txt1.txt");
	if (!ifile_1_2.is_open())
		cout << "Error\n";
	else {
		for (int k = 0; k < 4; k++) {
			ifile_1_2.getline(str, 100);
			if (k != number - 1)
				ofile_2 << str << endl;
			else ofile_2 << "Number of the row = " << number << endl;
		}
		ifile_1_2.close();
		ofile_2.close();
	}
}