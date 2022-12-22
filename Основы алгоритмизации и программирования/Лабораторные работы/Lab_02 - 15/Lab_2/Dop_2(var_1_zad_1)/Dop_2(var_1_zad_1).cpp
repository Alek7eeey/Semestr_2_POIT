/*���� ��� ����� ������������ ����� � ������� fA � fB, ���������� �������� ������������� ������ M1 � M2 �� �������,
������ ��������� ������� ������� ����� �������� ���������� �������� ��������������� �������.
������� ���� ��� �� ��������� � ������ fC, ���������� ������������ ������ M1�M2.*/

#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");
	int row=3, column=3;
	int B[20][20], S[20][20], R[20][20];
	errno_t err, er, e;
	FILE* f, * g, * k;
	err = fopen_s(&f, "firstMATR.txt", "w");
	
	//cout << "������� ���������� ��������: ";
	//cin >> column;
	///*error(column);*/

	//cout << "������� ���������� �����: ";
	//cin >> row; //��� ������ column = row1
	///*error(row);*/

	if (err != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < column; j++) {
			B[i][j] = rand() % 99 + 1;
			fprintf(f, "%d, ", B[i][j]);
		}
		fputs("\n", f);
	}
	printf("������ �������� � ���� firstMATR.txt\n");

	er = fopen_s(&g, "secMATR.txt", "w");
	if (er != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < column; i++) {

		for (int j = 0; j < row; j++) {
			S[i][j] = rand() % 99 + 1;
			fprintf(g, "%d, ", S[i][j]);
		}
		fputs("\n", g);
	}
	printf("������ �������� � ���� secMATR.txt\n");

	e = fopen_s(&k, "rezMATR.txt", "w");
	if (er != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < column; j++) {

			R[i][j] = B[i][j] * S[j][i];
			fprintf(k, "%d, ", R[i][j]);
		}
		fputs("\n", k);
	}
	printf("������ �������� � ���� rezMATR.txt\n");
	fclose(k);
	fclose(g);
	fclose(f);
	return 0;
}