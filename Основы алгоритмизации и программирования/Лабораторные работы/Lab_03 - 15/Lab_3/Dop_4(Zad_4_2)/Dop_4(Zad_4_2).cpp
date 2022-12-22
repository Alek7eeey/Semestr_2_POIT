//Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл. Прочитать из файла данные, подсчитать количество символов в самом длинном слове и вывести его.
//Вводим на англисском " hellow 123 how are you 24 "
#include <fstream>
#include <iostream>
using namespace std;
void main()
{

    setlocale(LC_ALL, "rus");
    cout << "Введите строку: ";
    char buff[50], mx[50], max = 0;
    char S[255];// буфер для хранения считываемого из файла текста
    ofstream fout("File1.txt");   // создание объекта fout класса ofstream для записи 
    cin.getline(S, 255); //Запоминаем в S то что ввели с клавиатуры
    fout << S << endl; //Записали S в файл и дописали перенос строки
    fout.close();
    fout.close();
    ifstream fin("File1.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        cout << "Самое длинное слово: ";
        for (int i = 0; i < 7; i++) {
            fin.getline(buff, 50, ' ');
            if (i == 0 || max < strlen(buff)) {
                max = strlen(buff);
                for (int c = 0; c < strlen(buff); c++) {
                    mx[c] = buff[c];
                    cout << mx[c];
                }
                cout << endl << strlen(buff);
            }


        }

        fin.close();


    }
}