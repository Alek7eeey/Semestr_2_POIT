// Реализация хеш - таблицы в Cи

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct set
{
    int key;
    int data;
};
struct set* array;
int capacity = 10;
int size = 0;

int hashFunction(int key)
{
    return (key % capacity);
}

int checkPrime(int n)
{
    int i;
    if (n == 1 || n == 0)
    {
        return 0;
    }
    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int getPrime(int n)
{
    if (n % 2 == 0)
    {
        n++;
    }
    while (!checkPrime(n))
    {
        n += 2;
    }
    return n;
}
void init_array()
{
    capacity = getPrime(capacity);
    array = (struct set*)malloc(capacity * sizeof(struct set));
    for (int i = 0; i < capacity; i++)
    {
        array[i].key = 0;
        array[i].data = 0;
    }
}

void insert(int key, int data)
{
    int index = hashFunction(key);
    if (array[index].data == 0)
    {
        array[index].key = key;
        array[index].data = data;
        size++;
        printf("\n Ключ (%d) вставлен \n", key);
    }
    else if (array[index].key == key)
    {
        array[index].data = data;
    }
    else
    {
        printf("\n Возникла коллизия \n");
    }
}

void remove_element(int key)
{
    int index = hashFunction(key);
    if (array[index].data == 0)
    {
        printf("\n Данного ключа не существует \n");
    }
    else
    {
        array[index].key = 0;
        array[index].data = 0;
        size--;
        printf("\n Ключ (%d) удален \n", key);
    }
}
void display()
{
    int i;
    for (i = 0; i < capacity; i++)
    {
        if (array[i].data == 0)
        {
            printf("\n array[%d]: / ", i);
        }
        else
        {
            printf("\n Ключ: %d array[%d]: %d \t", array[i].key, i, array[i].data);
        }
    }
}

int size_of_hashtable()
{
    return size;
}

int main()
{
    int choice, key, data, n;
    int c = 0;
    init_array();

    do
    {
        printf("1.Вставить элемент в хэш-таблицу"
            "\n2.Удалить элемент из хэш-таблицы"
            "\n3.Узнать размер хэш-таблицы"
            "\n4.Вывести хэш-таблицу"
            "\n\n Пожалуйста, выберите нужный вариант: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Введите ключ -:\t");
            scanf("%d", &key);
            printf("Введите данные-:\t");
            scanf("%d", &data);
            insert(key, data);

            break;

        case 2:

            printf("Введите ключ, который хотите удалить-:");
            scanf("%d", &key);
            remove_element(key);

            break;

        case 3:

            n = size_of_hashtable();
            printf("Размер хеш-таблицы-:%d\n", n);

            break;

        case 4:

            display();

            break;

        default:

            printf("Неверно введены данные\n");
        }

        printf("\nПродолжить? (Нажмите 1, если да): ");
        scanf("%d", &c);

    } while (c == 1);
}