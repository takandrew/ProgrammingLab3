#pragma once
int NumInInt(); // Проверка корректности вводимого значения переменной типа int
double NumInDouble(); // Проверка корректности вводимого значения переменной типа double

struct ResultCount {
	int comparison; // Сравнения
	int permutation; // Перестановки
};

ResultCount BubbleSort(double** matrix, int m, int n, ResultCount bubbleCount); // Пузырьковая сортировка
ResultCount SelectionSort(double** matrix, int m, int n, ResultCount selectionCount); // Сортировка отбором
ResultCount InsertionSort(double** matrix, int m, int n, ResultCount insertionCount); // Сортировка вставкой
ResultCount ShellSort(double** matrix, int m, int n, ResultCount shellCount); // Сортировка Шелла
ResultCount QuickSort(double** matrix, int m, int n, int left, int right, ResultCount quickCount); // Быстрая сортировка
ResultCount QuickSort_working(double** tempMatrix, int j, int n, int left, int right, ResultCount quickCount); // Быстрая
                                                                                          //сортировка для одного столбца
void Sorting(double** matrix, int m, int n); // Результирующая функция, включающая в себя все сортировки
double** BubbleSort_MatrixExport(double** tempMatrix, int m, int n); // Пузырьковая сортировка для тестирования
double** SelectionSort_MatrixExport(double** tempMatrix, int m, int n); // Сортировка отбором для тестирования
double** InsertionSort_MatrixExport(double** tempMatrix, int m, int n); // Сортировка вставкой для тестирования
double** ShellSort_MatrixExport(double** tempMatrix, int m, int n); // Сортировка Шелла для тестирования
double** QuickSort_MatrixExport(double** tempMatrix, int n, int left, int right); // Быстрая сортировка для тестирования
int Maximum(int first, int second); // Возвращение максимального значения
int Minimum(int first, int second); // Возвращение минимального значения