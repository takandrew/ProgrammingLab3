#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Computing.h"
#include<Windows.h>
using namespace std;

bool FileExist(string path); // Проверка существования файла
void FileWriteData(int n, int m, double **matrix); // Запись исходных данных в файл
int FileReadLineSize(string path); // Чтение длины строки матрицы из файла
int FileReadColumnSize(string path); // Чтение длины столбца матрицы из файла
double** FileReadMatrix(int n, int m, double **matrix, string path); // Чтение значений элементов матрицы из файла
void FileWriteResult(int m, int n, double** matrix, ResultCount bubleCount, ResultCount selectionCount,
	ResultCount insertionCount, ResultCount shellCount, ResultCount quickCount); // Запись результата программы в файл
bool ReadOnlyChecking(string path); //Функция, проверяющая, является ли файл доступным только для чтения. Принимает путь к файлу.
bool FileCorrectChecking(string path); //Функция, проверяющая корректность файла
bool FileReadCorrectChecking(string path); //Функция, проверяющая корректность файла, из которого считывают данные
bool FileOpenChecking(string path); // Функция, проверяющая открытие файла