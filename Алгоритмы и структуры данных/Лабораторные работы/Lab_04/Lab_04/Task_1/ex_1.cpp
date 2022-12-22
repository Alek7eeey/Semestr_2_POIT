#include <iostream>
#include <string>
using namespace std;

void choice_arr(int* arr, int size)
{
	int min = arr[0];

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				min = arr[i];
				arr[i] = arr[j];
				arr[j] = min;
			}
		}
	}
}

bool isProved(string num)
{
	char nums[] = "0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (num[i] == nums[j])
			{
				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int kol, max_sum = 0;
	string a;
	cout << "������� ���������� �������: ";

	getline(cin, a);

	while (true)
	{
		while (!isProved(a)) //���� true
		{
			cout << "������� ������ ���������� �������(1 - 10000):  ";
			getline(cin, a);
		}
		kol = stoi(a);

		if (kol > 0 && kol <= 10000)
		{
			break;
		}
		else
		{
			cout << "������� ������ ���������� �������(1 - 10000):  ";
			getline(cin, a);
		}
	}

	cout << "\n���� �� �����: \n";

	int* arr = new int[kol];
	

	for (int i = 0; i < kol; i++)
	{
		arr[i] = rand() % 100+1;
		cout << arr[i] << " ";
	}

	cout << "\n\n������� ���������� ������� �� �����: " << endl;
	
	choice_arr(arr, kol); // ���������� �������
	
	int begin = 0, end = kol - 1;

	for (int i = 0; i < kol; i++)
	{
		if ((i + 1) % 2 == 0) // ������ �������
		{
			cout << arr[begin++] << " "; //����� �������� � ������ �������
		}
		else
		{
			max_sum += arr[end];
			cout << arr[end--] << " "; //����� �������� � ����� �������
		}
	}
	cout << "\n������������ �����: " << max_sum;
	
	cout << endl << endl;

	delete[] arr;
	
}