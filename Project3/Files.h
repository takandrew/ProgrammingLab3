#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Computing.h"
#include<Windows.h>
using namespace std;

bool FileExist(string path); // �������� ������������� �����
void FileWriteData(int n, int m, double **matrix); // ������ �������� ������ � ����
int FileReadLineSize(string path); // ������ ����� ������ ������� �� �����
int FileReadColumnSize(string path); // ������ ����� ������� ������� �� �����
double** FileReadMatrix(int n, int m, double **matrix, string path); // ������ �������� ��������� ������� �� �����
void FileWriteResult(int m, int n, double** matrix, ResultCount bubleCount, ResultCount selectionCount,
	ResultCount insertionCount, ResultCount shellCount, ResultCount quickCount); // ������ ���������� ��������� � ����
bool ReadOnlyChecking(string path); //�������, �����������, �������� �� ���� ��������� ������ ��� ������. ��������� ���� � �����.
bool FileCorrectChecking(string path); //�������, ����������� ������������ �����
bool FileReadCorrectChecking(string path); //�������, ����������� ������������ �����, �� �������� ��������� ������
bool FileOpenChecking(string path); // �������, ����������� �������� �����