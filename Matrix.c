#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

#include"Matrix.h"
#include"Error.h"

int Input(int** matrix, int n)
{
	setlocale(0, "ru");

	printf("\nВыберете варианты ввода:\n\nНажмите 1 чтобы осуществить ввод с клавиатуры\nНажмите 2 чтобы соуществить ввод из файла\nНажмите 3 чтобы осуществить ввод рандомом\n");
	int k;
	printf("Ваш вариант: ");
	scanf_s("%d", &k);
	system("cls");

	printf("Размер вашей матрицы: %d\n", n);
	switch (k)
	{
	case 1:
		printf("Вы выбрали ввод с клавиатуры. Пожалуйста, введите матрицу: \n");
		system("pause");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf_s("%d", &matrix[i][j]);
			}
			printf("\n");
		}
		system("cls");
		printf("Ваша матрица:\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
		break;


	case 2:
		printf("Вы выбрали ввод из файла. Ввод будет осуществляться из файла matrix.txt\n");
		system("pause");
		FILE* input;
		errno_t err = fopen_s(&input, "matrix.txt", "r");
		ErrorOpen(err);
		ErrorFile(input);
		rewind(input);
		int n1, m1;
		n1 = CoutStr(input);
		rewind(input);
		m1 = CoutColum(input, n);
		rewind(input);
		ErrorInput(n1, m1, n);
		system("cls");
		printf("Ваша матрица: \n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fscanf_s(input, "%d", &matrix[i][j]);
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		err = fclose(input);
		ErrorOpen(err);
		break;


	case 3:
		printf("Вы выбрали ввод рандомом.\n");
		system("pause");
		system("cls");
		printf("Ваша матрица: \n");
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 0 + rand() % 100;
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
		break;
	}

	return(matrix);
}



int Determinant(int** matrix, int n)
{
	int t = 0, p = 0;
	float det = 0;
	clock_t start, end;

	switch (n) {

	case 1:
		start = clock();
		det = matrix[0][0];
		end = clock();
		break;

	case 2:
		start = clock();
		det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
		end = clock();
		break;

	case 3:
		start = clock();
		det = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]);
		end = clock();
		break;
	default:
		start = clock();
		p = 0;
		for (int i = 0; i < n - 1; i++)
		{
			t = 1;
			while (matrix[i][i] == 0)
			{
				for (int j = 0; j < n; j++)
				{
					matrix[i][j] = det;
					matrix[i][j] = matrix[i + t][j];
					matrix[i + t][j] = det;
				}
				p++;
				t++;
			}

			for (int k = i + 1; k < n; k++)
			{
				det = matrix[k][i] / matrix[i][i];
				for (int j = 0; j < n; j++)
					matrix[k][j] -= matrix[i][j] * det;
			}
		}

		det = pow(-1, p);
		for (int i = 0; i < n; i++)
			det *= matrix[i][i];
		end = clock();
		break;
	}

	printf("Время выполнения: %lf\n", (end - start) / (CLOCKS_PER_SEC));
	printf("Определитель матрицы: %f\n", det);
}

void Matrix(int** matrix, int n)
{
	Input(matrix, n);
	Determinant(matrix, n);
}