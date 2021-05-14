#include<iostream>
#include <iomanip>
#include <Windows.h>
#include "Computing.h"
#include "Files.h"
#include "Menu.h"
using namespace std;

// �������� ������������ ��������� �������� ���������� ���� double
double NumInDouble() {
	double variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "����������� ��������� ������. ����������, ������� �����: " << endl;
	}
	return variable;
}

// �������� ������������ ��������� �������� ���������� ���� int
int NumInInt() {
	int variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "����������� ��������� ������. ����������, ������� �����: " << endl;
	}
	return variable;
}

// ����������� ����������
ResultCount BubbleSort(double** matrix, int m, int n, ResultCount bubbleCount) {
	double temp;
	int i, j;
	double **tempMatrix = new double*[m];
	for (i = 0; i < m; i++)
		tempMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			tempMatrix[i][j] = matrix[i][j];
		}
	}
	int stopCount = -1;
	while (stopCount != 0) {
		stopCount = 0;
		for (i = 0; i < (m-1); i++) {
			for (j = 0; j < n; j++) {
				if (tempMatrix[i][j] > tempMatrix[i + 1][j]) {
					temp = tempMatrix[i][j];
					tempMatrix[i][j] = tempMatrix[i + 1][j];
					tempMatrix[i + 1][j] = temp;
					bubbleCount.permutation++;
					stopCount++;
				}
				bubbleCount.comparison++;
			}
		}
	}
	cout << "����������� ����������:" << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << setw(6) << tempMatrix[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < m; i++)
		delete[] tempMatrix[i];
	delete[] tempMatrix;
	return bubbleCount;
}

// ����������� ������������� ��������
int Maximum(int first, int second) {
	if (first > second)
		return first;
	else
		return second;
}

// ����������� ������������ ��������
int Minimum(int first, int second) {
	if (first > second)
		return second;
	else
		return first;
}

// ���������� �������
ResultCount SelectionSort(double** matrix, int m, int n, ResultCount selectionCount) {
	int i, j, k;
	double **tempMatrix = new double*[m];
	for (i = 0; i < m; i++)
		tempMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			tempMatrix[i][j] = matrix[i][j];
		}
	}
	double temp = tempMatrix[0][0];
	for (k = 0; k < Maximum(n, m); k++) {
		for (i = k+1; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (tempMatrix[k][j] > tempMatrix[i][j]) {
					temp = tempMatrix[k][j];
					tempMatrix[k][j] = tempMatrix[i][j];
					tempMatrix[i][j] = temp;
					selectionCount.permutation++;
				}
				selectionCount.comparison++;
			}
		}
	}
	cout << "C��������� �������:" << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << setw(6) << tempMatrix[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < m; i++)
		delete[] tempMatrix[i];
	delete[] tempMatrix;
	return selectionCount;
}

// ���������� ��������
ResultCount InsertionSort(double** matrix, int m, int n, ResultCount insertionCount) {
	int i, j, k;
	double temp = 0;
	double **tempMatrix = new double*[m];
	for (i = 0; i < m; i++)
		tempMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			tempMatrix[i][j] = matrix[i][j];
		}
	}
	for (j = 0; j < n; j++) {
		for (i = 1; i < m; i++) {
			temp = tempMatrix[i][j];
			for (k = i - 1; k >= 0; k--) {
				if (tempMatrix[k][j] > temp) {
					insertionCount.comparison++;
					tempMatrix[k + 1][j] = tempMatrix[k][j];
					insertionCount.permutation++;
				}
				else {
					insertionCount.comparison++;
					break;
				}
			}
			tempMatrix[k + 1][j] = temp;
		}
	}
	cout << "C��������� ��������:" << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << setw(6) << tempMatrix[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < m; i++)
		delete[] tempMatrix[i];
	delete[] tempMatrix;
	return insertionCount;
}

// ���������� �����
ResultCount ShellSort(double** matrix, int m, int n, ResultCount shellCount) {
	int i, j, k, l;
	double temp = 0;
	double **tempMatrix = new double*[m];
	for (i = 0; i < m; i++)
		tempMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			tempMatrix[i][j] = matrix[i][j];
		}
	}
	for (j = 0; j < n; j++) {
		for (i = m / 2; i > 0; i /= 2) {
			for (k = i; k < m; k++) {
				for (l = k - i; l >= 0; l-=i) {
					if (tempMatrix[l][j] > tempMatrix[l + i][j]) {
						shellCount.comparison++;
						temp = tempMatrix[l][j];
						tempMatrix[l][j] = tempMatrix[l + i][j];
						tempMatrix[l + i][j] = temp;
						shellCount.permutation++;
					}
					else {
						shellCount.comparison++;
						break;
					}
				}
			}
		}
	}
	cout << "C��������� �����:" << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << setw(6) << tempMatrix[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < m; i++)
		delete[] tempMatrix[i];
	delete[] tempMatrix;
	return shellCount;
}

// ������� ����������
ResultCount QuickSort(double** matrix, int m, int n, int left, int right, ResultCount quickCount) {
	int i, j;
	double **tempMatrix = new double*[m];
	for (i = 0; i < m; i++)
		tempMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			tempMatrix[i][j] = matrix[i][j];
		}
	}
	for (j = 0; j < n; j++) {
		quickCount = QuickSort_working(tempMatrix, j, n, left, right, quickCount);
	}
	cout << "������� ����������:" << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << setw(6) << tempMatrix[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < m; i++)
		delete[] tempMatrix[i];
	delete[] tempMatrix;
	return quickCount;
}

// ������� ���������� ��� ������ �������
ResultCount QuickSort_working(double** tempMatrix, int j, int n, int left, int right, ResultCount quickCount) {
	int l = left;
	int r = right;
	double temp, middle;
	bool whileOne, whileTwo;
	middle = tempMatrix[(l + r) / 2][j];
	while (l <= r) {
		whileOne = false; whileTwo = false;
		while ((tempMatrix[l][j] < middle) && (l >= left)) {
			l++;
			whileOne = true;
			quickCount.comparison++;
		}
		if (whileOne == false)
			quickCount.comparison++;
		while ((tempMatrix[r][j] > middle) && (r <= right)) {
			r--;
			whileTwo = true;
			quickCount.comparison++;
		}
		if (whileTwo == false)
			quickCount.comparison++;
		if (l <= r) {
			if (tempMatrix[l][j] != tempMatrix[r][j]) {
				temp = tempMatrix[l][j];
				tempMatrix[l][j] = tempMatrix[r][j];
				tempMatrix[r][j] = temp;
				quickCount.permutation++;
			}
			l++;
			r--;
		}
	}
	if (r > left)
		quickCount = QuickSort_working(tempMatrix, j, n, left, r, quickCount);
	if (l < right)
		quickCount = QuickSort_working(tempMatrix, j, n, l, right, quickCount);
	return quickCount;
}

// �������������� �������, ���������� � ���� ��� ����������
void Sorting(double** matrix, int m, int n) {
	ResultCount bubleCount, selectionCount, insertionCount, shellCount, quickCount;
	bubleCount.comparison = 0;
	bubleCount.permutation = 0;
	selectionCount.comparison = 0;
	selectionCount.permutation = 0;
	insertionCount.comparison = 0;
	insertionCount.permutation = 0;
	shellCount.comparison = 0;
	shellCount.permutation = 0;
	quickCount.comparison = 0;
	quickCount.permutation = 0;
	bubleCount = BubbleSort(matrix, m, n, bubleCount);
	selectionCount = SelectionSort(matrix, m, n, selectionCount);
	insertionCount = InsertionSort(matrix, m, n, insertionCount);
	shellCount = ShellSort(matrix, m, n, shellCount);
	quickCount = QuickSort(matrix, m, n, 0, (m-1), quickCount);
	cout << "��������� ���������� ������� ��������:" << endl;
	cout << "����� ����������" << setw(30) << "����� ���������" << setw(30) << "����� ������������" << endl;
	cout << "����������� ����������" << setw(16) << bubleCount.comparison << setw(30) << bubleCount.permutation << endl;
	cout << "���������� �������" << setw(20) << selectionCount.comparison << setw(30) << selectionCount.permutation << endl;
	cout << "���������� ��������" << setw(19) << insertionCount.comparison << setw(30) << insertionCount.permutation << endl;
	cout << "���������� �����" << setw(22) << shellCount.comparison << setw(30) << shellCount.permutation << endl;
	cout << "������� ����������" << setw(20) << quickCount.comparison << setw(30) << quickCount.permutation << endl;
	if (MenuResult() == true) { // ����������� ������ ����������
		FileWriteResult(m, n, matrix, bubleCount, selectionCount, insertionCount, shellCount, quickCount);
	}
}

// ����������� ���������� ��� ������������
double** BubbleSort_MatrixExport(double** tempMatrix, int m, int n) {
	double temp;
	int i, j;
	int stopCount = -1;
	while (stopCount != 0) {
		stopCount = 0;
		for (i = 0; i < (m - 1); i++) {
			for (j = 0; j < n; j++) {
				if (tempMatrix[i][j] > tempMatrix[i + 1][j]) {
					temp = tempMatrix[i][j];
					tempMatrix[i][j] = tempMatrix[i + 1][j];
					tempMatrix[i + 1][j] = temp;
					stopCount++;
				}
			}
		}
	}
	return tempMatrix;
}

// ���������� ������� ��� ������������
double** SelectionSort_MatrixExport(double** tempMatrix, int m, int n) {
	int i, j, k;
	double temp = tempMatrix[0][0];
	for (k = 0; k < Maximum(n, m); k++) {
		for (i = k+1; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (tempMatrix[k][j] > tempMatrix[i][j]) {
					temp = tempMatrix[k][j];
					tempMatrix[k][j] = tempMatrix[i][j];
					tempMatrix[i][j] = temp;
				}
			}
		}
	}
	return tempMatrix;
}

// ���������� �������� ��� ������������
double** InsertionSort_MatrixExport(double** tempMatrix, int m, int n) {
	int i, j, k;
	double temp = 0;
	for (j = 0; j < n; j++) {
		for (i = 1; i < m; i++) {
			temp = tempMatrix[i][j];
			for (k = i - 1; (k >= 0) && (tempMatrix[k][j] > temp); k--) {
				tempMatrix[k + 1][j] = tempMatrix[k][j];
			}
			tempMatrix[k + 1][j] = temp;
		}
	}
	return tempMatrix;
}

// ���������� ����� ��� ������������
double** ShellSort_MatrixExport(double** tempMatrix, int m, int n) {
	int i, j, k, l;
	double temp = 0;
	for (j = 0; j < n; j++) {
		for (i = m / 2; i > 0; i /= 2) {
			for (k = i; k < m; k++) {
				for (l = k - i; (l >= 0) && (tempMatrix[l][j] > tempMatrix[l + i][j]); l--) {
					temp = tempMatrix[l][j];
					tempMatrix[l][j] = tempMatrix[l + i][j];
					tempMatrix[l + i][j] = temp;
				}
			}
		}
	}
	return tempMatrix;
}

// ������� ���������� ��� ������������
double** QuickSort_MatrixExport(double** tempMatrix, int n, int left, int right) {
	ResultCount quickCount;
	quickCount.comparison = 0;
	quickCount.permutation = 0;
	int j;
	for (j = 0; j < n; j++) {
		quickCount = QuickSort_working(tempMatrix, j, n, left, right, quickCount);
	}
	return tempMatrix;
}