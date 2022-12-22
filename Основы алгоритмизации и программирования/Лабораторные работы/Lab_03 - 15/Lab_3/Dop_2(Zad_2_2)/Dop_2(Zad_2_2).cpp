/*Ввести строку символов,
состоящую из групп цифр и нулей, и записать ее в файл.
Прочитать из файла данные и вывести самую короткую группу. */

#include <fstream>
#include <iostream>
using namespace std;

void main()
{
    int m = 0;
    setlocale(LC_ALL, "rus");
    cout << "Лаки_джон\nМакдональс\nБогатый_регион\nБагратион\nАпельсин\n";
    
    char buff[50], count[100];            // буфер для хранения считываемого из файла текста
    ofstream fout("FILE1.txt");   // создание объекта fout класса ofstream для записи 
    fout << "Лаки_джон\nМакдональс\nБогатый_регион\nБагратион\nАпельсин\n"; // запись строки в файл
    fout.close();
    
    ifstream fin("FILE1.txt");    // создание объекта fin класса ifstream для чтения  
    ofstream FILE2("FILE2.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        ifstream f2("FILE2.txt");
        for (int i = 0; i < 2; i++) {
            fin.getline(buff, 50, 'А');// считывание строки из файла
            fin.getline(buff, 50);
            FILE2 << "А" << buff << endl;
        }
        for (int i = 0; i < 50; i++) {
            f2.getline(count, 50);
           
            if ((count[i] == '\n') || (count[i] == ' '))
                m++;
        }
        cout << "\nДанные во второй файл записаны! " <<endl;
        f2.close();
        fin.close();
        FILE2.close();
    }
}