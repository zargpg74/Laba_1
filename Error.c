#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#include"Error.h"

void ErrorMatrix(int n)
{
	setlocale(0, "ru");
	if (n < 1)
	{
		system("cls");
		printf("Проверьте корректность введенных данных.\n");
		exit(n);
	}
}

void ErrorOpen(errno_t err) {
	if (err != 0) {
		system("cls");
		char error_str[100];
		strerror_s(error_str, sizeof(error_str), err);
		printf("%s\n", error_str);
		exit(err);
	}
}

void ErrorFile(FILE* input) {
	char pr;

	pr = getc(input);

	if (pr == EOF) {
		system("cls");
		printf("Файл пуст");
		exit(4);
	}

	while (pr != EOF) {
		if (pr != 45 && !(pr >= 48 && pr <= 57) && pr != 32 && pr != 10) {
			system("cls");
			printf("В файле найден посторониий элемент");
			exit(0);
		}
		pr = getc(input);
	}
}

void ErrorInput(int n1, int m1, int n) {
	if ((n1 != n) || (m1 != n)) {
		system("cls");
		printf("Матрица в файле не сответствует указанному размеру или не является квадратной. Пожалуйста, проверьте введенные данные\n");
		exit(1);
	}

	if (n < 1) {
		system("cls");
		printf("Невозможно вычислить определитель. Пожалуйста, проверьте введенные данные\n");
		exit(2);
	}
}

int CoutStr(FILE* input) {
	char pr = getc(input);
	int cout = 0;

	while (pr != EOF) {
		if (pr == 10) cout += 1;
		pr = getc(input);
	}
	return(cout + 1);
}

int CoutColum(FILE* input, int n) {
	char pr = getc(input);
	int cout = 0;

	while (pr != EOF) {
		if (pr == 32) cout += 1;
		pr = getc(input);
	}
	return((cout / n) + 1);
}