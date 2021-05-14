#include<iostream>
#include <iomanip>
#include"Computing.h"

using namespace std;

// Тестирование модулей
void Testing() {
	int i, j;
	int zero = 0, two = 2, three = 3, four = 4;
	bool errorFirst = false; // Переменная для нахождения ошибок в первом тестировании
	bool errorSecond = false; // Переменная для нахождения ошибок в втором тестировании
	bool errorThird = false; // Переменная для нахождения ошибок в третьем тестировании
	bool errorFourth = false; // Переменная для нахождения ошибок в четвертом тестировании
	bool errorFifth = false; // Переменная для нахождения ошибок в пятом тестировании

	// Создание и заполнение матрицы для первого тестирования
	double **firstMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		firstMatrix[i] = new double[2];
	firstMatrix[0][0] = 32;		firstMatrix[0][1] = 52;
	firstMatrix[1][0] = -44;	firstMatrix[1][1] = 13;
	firstMatrix[2][0] = -2;		firstMatrix[2][1] = -15;

	// Создание и заполнение матрицы для второго тестирования
	double **secondMatrix = new double*[2];
	for (i = 0; i < 2; i++)
		secondMatrix[i] = new double[2];
	secondMatrix[0][0] = 2;	secondMatrix[0][1] = 1;
	secondMatrix[1][0] = 4;	secondMatrix[1][1] = 3;

	// Создание и заполнение матрицы для третьего тестирования
	double **thirdMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		thirdMatrix[i] = new double[2];
	thirdMatrix[0][0] = -11;	thirdMatrix[0][1] = -24;
	thirdMatrix[1][0] = -15;	thirdMatrix[1][1] = -50;
	thirdMatrix[2][0] = -5;		thirdMatrix[2][1] = -1;

	// Создание и заполнение матрицы для четвертого тестирования
	double **fourthMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		fourthMatrix[i] = new double[2];
	fourthMatrix[0][0] = 50;	fourthMatrix[0][1] = 34;
	fourthMatrix[1][0] = 20;	fourthMatrix[1][1] = 32;
	fourthMatrix[2][0] = 7;		fourthMatrix[2][1] = 12;

	// Создание и заполнение матрицы для пятого тестирования
	double **fifthMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		fifthMatrix[i] = new double[4];
	fifthMatrix[0][0] = 0;	fifthMatrix[0][1] = 0;	fifthMatrix[0][2] = 0;	fifthMatrix[0][3] = 0;
	fifthMatrix[1][0] = 0;	fifthMatrix[1][1] = 0;	fifthMatrix[1][2] = 0;	fifthMatrix[1][3] = 0;
	fifthMatrix[2][0] = 0;	fifthMatrix[2][1] = 0;	fifthMatrix[2][2] = 0;	fifthMatrix[2][3] = 0;

	// Создание и заполнение отсортированной матрицы для первого тестирования
	double **firstSortedMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		firstSortedMatrix[i] = new double[2];
	firstSortedMatrix[0][0] = -44;	firstSortedMatrix[0][1] = -15;
	firstSortedMatrix[1][0] = -2;	firstSortedMatrix[1][1] = 13;
	firstSortedMatrix[2][0] = 32;	firstSortedMatrix[2][1] = 52;

	// Создание и заполнение отсортированной матрицы для второго тестирования
	double **secondSortedMatrix = new double*[2];
	for (i = 0; i < 2; i++)
		secondSortedMatrix[i] = new double[2];
	secondSortedMatrix[0][0] = 2;	secondSortedMatrix[0][1] = 1;
	secondSortedMatrix[1][0] = 4;	secondSortedMatrix[1][1] = 3;

	// Создание и заполнение отсортированной матрицы для третьего тестирования
	double **thirdSortedMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		thirdSortedMatrix[i] = new double[2];
	thirdSortedMatrix[0][0] = -15;	thirdSortedMatrix[0][1] = -50;
	thirdSortedMatrix[1][0] = -11;	thirdSortedMatrix[1][1] = -24;
	thirdSortedMatrix[2][0] = -5;	thirdSortedMatrix[2][1] = -1;

	// Создание и заполнение отсортированной матрицы для четвертого тестирования
	double **fourthSortedMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		fourthSortedMatrix[i] = new double[2];
	fourthSortedMatrix[0][0] = 7;	fourthSortedMatrix[0][1] = 12;
	fourthSortedMatrix[1][0] = 20;	fourthSortedMatrix[1][1] = 32;
	fourthSortedMatrix[2][0] = 50;	fourthSortedMatrix[2][1] = 34;

	// Создание и заполнение отсортированной матрицы для пятого тестирования
	double **fifthSortedMatrix = new double*[3];
	for (i = 0; i < 3; i++)
		fifthSortedMatrix[i] = new double[4];
	fifthSortedMatrix[0][0] = 0;	fifthSortedMatrix[0][1] = 0;	fifthSortedMatrix[0][2] = 0;	fifthSortedMatrix[0][3] = 0;
	fifthSortedMatrix[1][0] = 0;	fifthSortedMatrix[1][1] = 0;	fifthSortedMatrix[1][2] = 0;	fifthSortedMatrix[1][3] = 0;
	fifthSortedMatrix[2][0] = 0;	fifthSortedMatrix[2][1] = 0;	fifthSortedMatrix[2][2] = 0;	fifthSortedMatrix[2][3] = 0;

	// Первое тестирование. Пузырьковая сортировка
	BubbleSort_MatrixExport(firstMatrix, three, two);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (firstMatrix[i][j] != firstSortedMatrix[i][j])
				errorFirst = true;
		}
	}

	// Второе тестирование. Сортировка отбором
	SelectionSort_MatrixExport(secondMatrix, two, two);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			if (secondMatrix[i][j] != secondSortedMatrix[i][j])
				errorSecond = true;
		}
	}

	// Третье тестирование. Сортировка вставкой
	InsertionSort_MatrixExport(thirdMatrix, three, two);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (thirdMatrix[i][j] != thirdSortedMatrix[i][j])
				errorThird = true;
		}
	}

	// Четвертое тестирование. Сортировка Шелла
	ShellSort_MatrixExport(fourthMatrix, three, two);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (fourthMatrix[i][j] != fourthSortedMatrix[i][j])
				errorFourth = true;
		}
	}

	// Пятое тестирование. Быстрая сортировка
	QuickSort_MatrixExport(fifthMatrix, four, zero, two);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			if (fifthMatrix[i][j] != fifthSortedMatrix[i][j])
				errorFifth = true;
		}
	}

	// Удаление всех матриц
	for (i = 0; i < 3; i++)
		delete[] firstMatrix[i];
	delete[] firstMatrix;

	for (i = 0; i < 3; i++)
		delete[] firstSortedMatrix[i];
	delete[] firstSortedMatrix;

	for (i = 0; i < 2; i++)
		delete[] secondMatrix[i];
	delete[] secondMatrix;

	for (i = 0; i < 2; i++)
		delete[] secondSortedMatrix[i];
	delete[] secondSortedMatrix;

	for (i = 0; i < 3; i++)
		delete[] thirdMatrix[i];
	delete[] thirdMatrix;

	for (i = 0; i < 3; i++)
		delete[] thirdSortedMatrix[i];
	delete[] thirdSortedMatrix;

	for (i = 0; i < 3; i++)
		delete[] fourthMatrix[i];
	delete[] fourthMatrix;

	for (i = 0; i < 3; i++)
		delete[] fourthSortedMatrix[i];
	delete[] fourthSortedMatrix;

	for (i = 0; i < 3; i++)
		delete[] fifthMatrix[i];
	delete[] fifthMatrix;

	for (i = 0; i < 3; i++)
		delete[] fifthSortedMatrix[i];
	delete[] fifthSortedMatrix;

	if (!((errorFirst) || (errorSecond) || (errorThird) || (errorFourth) || (errorFifth))) // Проверка успешности тестирования
		cout << "Тестирование проведено успешно." << endl;
	else {
		if (errorFirst != false)
			cout << "Тестирование неотсортированной матрицы провалено." << endl;
		if (errorSecond != false)
			cout << "Тестирование изначально отсортированной матрицы провалено." << endl;
		if (errorThird != false)
			cout << "Тестирование с матрицей из полностью отрицательных чисел провалено." << endl;
		if (errorFourth != false)
			cout << "Тестирование с матрицей из полностью положительных чисел провалено." << endl;
		if (errorFifth != false)
			cout << "Тестирование с матрицей из полностью одинаковых чисел провалено." << endl;
		cout << "Тестирование провалено." << endl;
	}
}