/*
Определить, верно ли расставлены скобки (символы между скобками не учитывать).
В качестве ответа вывести текст «скобки расставлены верно» или «скобки расставлены не верно».
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool prov(const string& s, int &count) 
{
    stack <char> stack;
   
    for (char c : s) {
        
        switch (c) {
        case '(': stack.push(')'); count++; break;
        case '[': stack.push(']'); count++; break;
        case '{': stack.push('}'); count++; break;
        case '<': stack.push('>'); count++; break;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stack.empty() || stack.top() != c) { //если пустой или не равен скобке
                return false;
            }
            stack.pop();
            break;
       
        default:
            break;
        }
    }
    return stack.empty();
}

void test(const string& s, int &count) 
{
    if (prov(s, count) && count > 0)
    {
        cout << '"' << s << "\" " << "скобки расставлены верно" << endl;
    }
    
    if (count == 0)
    {
        cout << "Скобки отсутствуют!" << endl;
    }

    else if(!prov(s, count) && count > 0)
    {
        cout << '"' << s << "\" " << "скобки расставлены не верно" << endl;
    }
    
}

void main() {
    setlocale(LC_ALL, "rus");
    
    while (true)
    {
        int count = 0;
        cout << "\nВведите строку с клавиатуры: ";
        string str;
        getline(cin, str);
        test(str, count);
    }

}