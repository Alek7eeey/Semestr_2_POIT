#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void bubble_arr(int* , int);
void insert_arr(int*, int);
void choice_arr(int*, int);
void fast_arr(int*, int );

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int size;
	
	cout << "Введите размерность массива: ";
	cin >> size;
	int* A = new int[size];
	int* B = new int[size];
	int* C = new int[size];
	int* D = new int[size];
	int* E = new int[size];

	cout << "\nМассив A : " << endl;
	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 100-50;
		cout << A[i] << "\t";
		
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}
	
	//пузырьковая сортировка
	cout << "\n\n________________________________________________________________________" << endl;
	unsigned int start_time = clock(); // начальное время
	bubble_arr(B, size);
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	cout << "\nЗатраченное время = " << search_time <<" мс" << endl;
	cout << "____________________________________________________________________________" << endl;

	//сортировка вставкой (или методом Шелла)
	start_time = clock();
	insert_arr(C, size);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "\nЗатраченное время = " << search_time << " мс" << endl;
	cout << "__________________________________________________________________________" << endl;

	//сортировка выбором
	start_time = clock();
	choice_arr(D, size);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "\nЗатраченное время = " << search_time << " мс" << endl;
	cout << "__________________________________________________________________________" << endl;

	//быстрая сортировка
	start_time = clock();
	fast_arr(E, size);
	cout << "\nМассив 'E' в отсортированном виде (быстрая сортировка): " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << E[i] << "\t"; // выводим элементы массива
	}
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "\nЗатраченное время = " << search_time << " мс" << endl;
	cout << "__________________________________________________________________________" << endl;

	
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
	cout << endl << endl;
}

void bubble_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size-1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				int dop = arr[j]; // создали дополнительную переменную
				arr[j] = arr[j + 1]; // меняем местами
				arr[j + 1] = dop; // значения элементов
			}
		}
	}

	cout << "\nМассив 'B' в отсортированном виде(пузырьковая сортировка) : " << endl;

	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << "\t"; // выводим элементы массива
	}
}

void insert_arr(int* arr, int size)
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента

	for (int i = 1; i < size; i++)
	{
		temp = arr[i]; // инициализируем временную переменную текущим значением элемента массива
		item = i - 1; // запоминаем индекс предыдущего элемента массива

		while (item >= 0 && arr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[item + 1] = arr[item]; // перестановка элементов массива
			arr[item] = temp;
			item--;
		}
	}
	
	cout << "\nМассив 'C' в отсортированном виде (сортировка вставкой): " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t"; // выводим элементы массива
	}
}

void choice_arr(int* arr, int size)
{
	int min = arr[0];

	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr[i]> arr[j])
			{
				min = arr[i];
				arr[i] = arr[j];
				arr[j] = min;
			}
		}
	}

	cout << "\nМассив 'D' в отсортированном виде (сортировка выбором): " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t"; // выводим элементы массива
	}
}

void fast_arr(int* arr, int size)
{
	//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	//Центральный элемент массива
	int mid = arr[size / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (arr[i] < mid) {
			i++;
		}
	
		//В правой части пропускаем элементы, которые больше центрального
		while (arr[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		fast_arr(arr, j + 1);
	}
	if (i < size) {
		//"Првый кусок"
		fast_arr(&arr[i], size - i);
	}
}