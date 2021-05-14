#pragma once
int NumInInt(); // �������� ������������ ��������� �������� ���������� ���� int
double NumInDouble(); // �������� ������������ ��������� �������� ���������� ���� double

struct ResultCount {
	int comparison; // ���������
	int permutation; // ������������
};

ResultCount BubbleSort(double** matrix, int m, int n, ResultCount bubbleCount); // ����������� ����������
ResultCount SelectionSort(double** matrix, int m, int n, ResultCount selectionCount); // ���������� �������
ResultCount InsertionSort(double** matrix, int m, int n, ResultCount insertionCount); // ���������� ��������
ResultCount ShellSort(double** matrix, int m, int n, ResultCount shellCount); // ���������� �����
ResultCount QuickSort(double** matrix, int m, int n, int left, int right, ResultCount quickCount); // ������� ����������
ResultCount QuickSort_working(double** tempMatrix, int j, int n, int left, int right, ResultCount quickCount); // �������
                                                                                          //���������� ��� ������ �������
void Sorting(double** matrix, int m, int n); // �������������� �������, ���������� � ���� ��� ����������
double** BubbleSort_MatrixExport(double** tempMatrix, int m, int n); // ����������� ���������� ��� ������������
double** SelectionSort_MatrixExport(double** tempMatrix, int m, int n); // ���������� ������� ��� ������������
double** InsertionSort_MatrixExport(double** tempMatrix, int m, int n); // ���������� �������� ��� ������������
double** ShellSort_MatrixExport(double** tempMatrix, int m, int n); // ���������� ����� ��� ������������
double** QuickSort_MatrixExport(double** tempMatrix, int n, int left, int right); // ������� ���������� ��� ������������
int Maximum(int first, int second); // ����������� ������������� ��������
int Minimum(int first, int second); // ����������� ������������ ��������