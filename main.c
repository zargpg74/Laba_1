#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<locale.h>

#include"Error.h"
#include"Matrix.h"

typedef struct Matrix
{
	int** matrix;
};

void main()
{
	struct Matrix mtr;
	setlocale(0, "ru");
	system("cls");
	printf("Программа для вычисления определителя матрицы\n");
	system("pause");
	system("cls");

	printf("Введите размер матрицы: ");
	int n;
	scanf_s("%d", &n);
	ErrorMatrix(n);

	mtr.matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		mtr.matrix[i] = (int*)malloc(n * sizeof(int));
	}

	Matrix(mtr.matrix, n);

	for (int i = 0; i < n; i++)
	{
		free(mtr.matrix[i]);
	}
	free(mtr.matrix);
}