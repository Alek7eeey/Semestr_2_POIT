/*����������� ���������� ����������� ����� �� ����� N-����� ������������������ ���������.
����������� 2 ������� ��������: ����������� ��������; �������� ��������. */

#include <iostream>
using namespace std;

void rekurs(int,int,double*);

int main()
{
	setlocale(LC_ALL, "Rus");
	int start, finish, N;

	cout << "������� ���������� ����: ";
	cin >> N;

	if (N < 2)
		N = 2;

	double* arr = new double[N];

	cout << "�������� ������:" << endl;
	arr[0] = 0;
	arr[1] = 1;

	cout << arr[0] << " " << arr[1] << " ";

	start = clock();
	
	for (int i = 2; i < N; i++)
	{
		if (i % 10 == 0)
		{
			cout << "\n";
		}

		arr[i] = arr[i - 1] + arr[i - 2];
		cout << arr[i] << " ";
	}

	finish = clock();

	cout << "\n\n�������� ������: " << finish - start << " �����������" << endl;
	cout << "_____________________________________________________________________" << endl;
	
	cout << "����������� �����: " << endl;
	cout << arr[0] << " " << arr[1] << " ";

	start = clock();
	rekurs(N, 2, arr);
	finish = clock();

	cout << "\n\n����������� ������: " << finish - start << " �����������" << endl; \
	delete[] arr;

	cout << endl;
	return 0;

}

void rekurs(int N, int i, double* arr)
{
	if (i%10==0)
	{
		cout << endl;
	}
	arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[i++] << " ";

	if (N!=i)
	{
		rekurs(N, i, arr);
	}

}