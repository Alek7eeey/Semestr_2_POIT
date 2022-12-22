/*1. Скопировать из файла FILE1 в файл FILE2 все строки, которые содержат только одно слово. Найти самое короткое слово в  файле FILE2.
2. Ввести с клавиатуры две строки символов, состоящих из слов, разделенных пробелами,
и записать их в файл. Прочитать из файла данные.
Найти самое короткое слово в первой строке и самое длинное во второй строке. Посчитать количество гласных букв в этих словах. 
*/
#include <iostream>
#include <fstream>
#include<windows.h>
#include<string>
// ifstream (для ввода в файл)
// ofstream (для вывода из файла)
// fstream  (для ввода/вывода)
// << - операция включения >> - операция извлечения
// fout.open("Имя файла") - это строка. Если не находит файл то создаёт сама
//fout.is_open() - проверяет получилось открыть файл или нет возвращает true or false
// fout <<"данные файла"; -запись данных в файл
//fout.close(); -закрытие файла

using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* buff3 = new char[200];//для большего слова
    char* buff2 = new char[200];//для меньшего слова
    char* buff = new char[200];// макс длинна строки 200символов. буфер для хранения считываемого из файла текста
    ofstream fout("t.txt");   // создание объекта fout класса ofstream для записи 

    for (int i = 0; i < 2; i++) {


        cout << "введите " << i + 1 << " строку" << endl;
        string a;
        getline(cin, a);;
        fout << a;
        if (i < 1) {
            fout << "\n";
        }
    }
    fout.close();

    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";


    int min_len = 9999, max_len = 0, now_len = 0, lenofstr = 0, glasn1 = 0, glasn = 0, numnum = 0;

    while (!fin.eof())
    {
        fin.getline(buff, 200, '\n');

        lenofstr = strlen(buff);


        //поиск короткого слова в первой стркое
        if (numnum == 0) {

            for (int i = 0, z = 0, x = 0, c = 0; i <= lenofstr; i++) {

                if ((buff[i] != ' ') && (buff[i] != '\0') && (buff[i] != '\n')) {
                    z++;
                }
                // && - и 
                // || - или
                if (z > 0) {
                    if ((buff[i] == ' ') || (buff[i] == '\0') || (buff[i] == '\n')) {
                        now_len = z;
                        x = z;
                        c = (i - z);
                        z = 0;
                        if (min_len > now_len) {
                            min_len = now_len;

                            for (; c <= i; c++, z++) {
                                buff2[z] = buff[c];
                                if (c == i) {
                                    z = z + 1;
                                    buff2[z] = '\0';
                                    z = 0;
                                }
                            }
                        }
                    }
                }
            }
        }

        // конец поиска короткого слова в первой строке

        // Поиск длинного слова во второй строке
        if (numnum == 1) {
            for (int i = 0, z = 0, x = 0, c = 0; i <= lenofstr; i++) {
                if ((buff[i] != ' ') && (buff[i] != '\0') && (buff[i] != '\n')) {
                    z++;
                }
                // && - и 
                // || - или
                if (z > 0) {
                    if ((buff[i] == ' ') || (buff[i] == '\0') || (buff[i] == '\n')) {
                        now_len = z;
                        x = z;
                        c = (i - z);
                        z = 0;
                        if (max_len < now_len) {
                            max_len = now_len;

                            for (; c <= i; c++, z++) {
                                buff3[z] = buff[c];
                                if (c == i) {
                                    z = z + 1;
                                    buff3[z] = '\0';
                                    z = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        numnum = 1;
    }
    fin.close();
    //A, E, I, O, U
    char glasnyje[11] = { 'A','E','I','O','U','a','e','i','o','u','\0' };

    cout << "Cамое короткое слово " << endl;

    for (int k = 0; k < 200; k++) {
        if (buff2[k] == '\0') { cout << endl; break; }
        cout << buff2[k];
    }
    for (int m = 0; m < 11; m++) {
        for (int n = 0; n < strlen(buff2); n++) {
            if (buff2[n] == glasnyje[m]) {
                glasn++;
            }
        }
    }
    cout << "Гласных = " << glasn << endl;




    cout << "Cамое длинное слово " << endl;
    for (int k = 0; k < 200; k++) {
        if (buff3[k] == '\0') { cout << endl; break; }
        cout << buff3[k];
    }

    for (int m = 0; m < 11; m++) {
        for (int n = 0; n < strlen(buff3); n++) {
            if (buff3[n] == glasnyje[m]) {
                glasn1++;
            }
        }
    }
    cout << "Гласных = " << glasn1 << endl;

    delete[] buff;
    delete[] buff2;
    delete[] buff3;
}