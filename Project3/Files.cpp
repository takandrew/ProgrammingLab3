#include <iomanip>
#include"Menu.h"
#include"Files.h"
#include<stdlib.h>
#include <experimental/filesystem>
using namespace std::experimental::filesystem;

// Проверка существования файла
bool FileExist(string path) {
	WIN32_FIND_DATA wfd;
	LPCSTR pathLPC = path.c_str();
	HANDLE hfind = ::FindFirstFile(pathLPC, &wfd);
	if (INVALID_HANDLE_VALUE != hfind) {
		::FindClose(hfind);
		return true;
	}
	return false;
}

//Функция, проверяющая, является ли файл доступным только для чтения. Принимает путь к файлу.
bool ReadOnlyChecking(string path) {
	LPCSTR name = path.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		cout << endl << "В данный файл невозможно записать данные. Доступен только для чтения." << endl;
		return false;
	}
	else {
		return true;
	}
}

//Функция, проверяющая корректность файла
bool FileCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "Некорректное имя файла." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "Некорректное имя файла. Требуется ввести расширение файла после названия" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "Некорректный формат файла. Необходим файл формата .txt" << endl;
		return false;
	}
	if (!FileExist(path)) {
		return true;
	}
	if (!is_regular_file(path)) {
		cout << endl << "Файл не является обычным." << endl;
		return false;
	}
	return true;
}

//Функция, проверяющая корректность файла, из которого считывают данные
bool FileReadCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "Некорректное имя файла." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "Некорректное имя файла. Требуется ввести расширение файла после названия" << endl;
		return false;
	}
	if (!FileExist(path)) {
		cout << endl << "Файла по указанному пути не существует" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "Некорректный формат файла. Необходим файл формата .txt" << endl;
		return false;
	}
	if (!is_regular_file(path)) {
		cout << endl << "Файл не является обычным." << endl;
		return false;
	}
	return true;
}

// Функция, проверяющая открытие файла
bool FileOpenChecking(string path) {
	if (!FileExist(path)) {
		ofstream fout;
		fout.open(path);
		if (!fout.is_open()) {
			if (!is_regular_file(path)) {
				return false;
			}
			else {
				remove(path);
				return false;
			}
		}
		fout.close();
		remove(path);
		return true;
	}
	else
		return true;
}

// Чтение длины строки матрицы из файла
int FileReadLineSize(string path) {
	int n;
	ifstream fin;
	fin.open(path);
	string line_size;
	fin >> line_size;
	n = atoi(line_size.c_str());
	fin.close();
	return n;
}


// Чтение длины столбца матрицы из файла
int FileReadColumnSize(string path) {
	int n, m;
	ifstream fin;
	fin.open(path);
	string line_size;
	fin >> line_size;
	n = atoi(line_size.c_str());
	string column_size;
	fin >> column_size;
	m = atoi(column_size.c_str());
	fin.close();
	return m;
}

// Чтение значений элементов матрицы из файла
double** FileReadMatrix(int n, int m, double **matrix, string path) {
	int i, j;
	ifstream fin;
	fin.open(path);
	string line_size;
	fin >> line_size;
	string column_size;
	fin >> column_size;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			fin >> matrix[i][j];
		}
	}
	fin.close();
	return matrix;
}

// Запись исходных данных в файл
void FileWriteData(int n, int m, double **matrix) {
	int i, j;
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "Введите путь к файлу:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
		cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
		cout << "Введите путь к файлу:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // Проверка существования файла
		if (MenuReWrite() == true) { // Возможность выбора перезаписи в файл
			fout.open(path);
			// Вывод исходных данных в файл
			fout << n << endl;
			fout << m << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << matrix[i][j] << endl;
				}
			}
		}
		else { // Отказ от перезаписи и выбор другого пути к файлу
			cout << "Введите путь к файлу:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
				cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // Цикл проверки существования, перезаписи или выбора другого пути к файлу
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
						cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
						cout << "Введите путь к файлу:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						readOnlyCheck = ReadOnlyChecking(path);
						fileCorrectCheck = FileCorrectChecking(path);
						fileOpenCheck = FileOpenChecking(path);
					}
				}
			}
			SetConsoleCP(866);
			fout.open(path);
			// Вывод исходных данных в файл
			fout << n << endl;
			fout << m << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << matrix[i][j] << endl;
				}
			}
		}
	}
	else { // Если файла не существует 
		fout.open(path);
		// Вывод исходных данных в файл
		fout << n << endl;
		fout << m << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << matrix[i][j] << endl;
			}
		}
	}
	cout << endl << "Файл успешно сохранён." << endl;
	fout.close();
}

// Запись результата программы в файл
void FileWriteResult(int m, int n, double** matrix, ResultCount bubleCount, ResultCount selectionCount,
	ResultCount insertionCount, ResultCount shellCount, ResultCount quickCount) {
	int i, j;
	// Создание и заполнение временной матрицы для пузырьковой сортировки
	double **bubbleMatrix = new double*[m];
	for (i = 0; i < m; i++)
		bubbleMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			bubbleMatrix[i][j] = matrix[i][j];
		}
	}
	bubbleMatrix = BubbleSort_MatrixExport(bubbleMatrix, m, n); // Пузырьковая сортировка
	// // Создание и заполнение временной матрицы для сортировки отбором
	double **selectionMatrix = new double*[m];
	for (i = 0; i < m; i++)
		selectionMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			selectionMatrix[i][j] = matrix[i][j];
		}
	}
	selectionMatrix = SelectionSort_MatrixExport(selectionMatrix, m, n); // Сортировка отбором
	// Создание и заполнение временной матрицы для сортировки вставкой
	double **insertionMatrix = new double*[m];
	for (i = 0; i < m; i++)
		insertionMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			insertionMatrix[i][j] = matrix[i][j];
		}
	}
	insertionMatrix = InsertionSort_MatrixExport(insertionMatrix, m, n); // Сортировка вставкой
	// Создание и заполнение временной матрицы для сортировки Шелла
	double **shellMatrix = new double*[m];
	for (i = 0; i < m; i++)
		shellMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			shellMatrix[i][j] = matrix[i][j];
		}
	}
	shellMatrix = ShellSort_MatrixExport(shellMatrix, m, n); // Сортировка Шелла
	// Создание и заполнение временной матрицы для быстрой сортировки
	double **quickMatrix = new double*[m];
	for (i = 0; i < m; i++)
		quickMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			quickMatrix[i][j] = matrix[i][j];
		}
	}
	quickMatrix = QuickSort_MatrixExport(quickMatrix, n, 0, (m - 1)); // Быстрая сортировка
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "Введите путь к файлу:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
		cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
		cout << "Введите путь к файлу:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // Проверка существования файла
		if (MenuReWrite() == true) { // Возможность выбора перезаписи в файл
			fout.open(path);
			// Вывод исходных данных в файл
			fout << "Исходная матрица:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << matrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Пузырьковая сортировка:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << bubbleMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Сортировка отбором:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << selectionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Сортировка вставкой:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << insertionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Сортировка Шелла:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << shellMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Быстрая сортировка:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << quickMatrix[i][j];
				}
				fout << endl;
			}
			fout << "Результат сортировки разными методами:" << endl;
			fout << "Метод сортировки" << setw(30) << "Число сравнений" << setw(30) << "Число перестановок" << endl;
			fout << "Пузырьковая сортировка" << setw(16) << bubleCount.comparison << setw(30) << bubleCount.permutation << endl;
			fout << "Сортировка отбором" << setw(20) << selectionCount.comparison << setw(30) << selectionCount.permutation << endl;
			fout << "Сортировка вставкой" << setw(19) << insertionCount.comparison << setw(30) << insertionCount.permutation << endl;
			fout << "Сортировка Шелла" << setw(22) << shellCount.comparison << setw(30) << shellCount.permutation << endl;
			fout << "Быстрая сортировка" << setw(20) << quickCount.comparison << setw(30) << quickCount.permutation << endl;
		}
		else { // Отказ от перезаписи и выбор другого пути к файлу
			cout << "Введите путь к файлу:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
				cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // Цикл проверки существования, перезаписи или выбора другого пути к файлу
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
						cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
						cout << "Введите путь к файлу:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						readOnlyCheck = ReadOnlyChecking(path);
						fileCorrectCheck = FileCorrectChecking(path);
						fileOpenCheck = FileOpenChecking(path);
					}
				}
			}
			SetConsoleCP(866);
			fout.open(path);
			// Вывод исходных данных в файл
			fout << "Исходная матрица:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << matrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Пузырьковая сортировка:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << bubbleMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Сортировка отбором:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << selectionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Сортировка вставкой:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << insertionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Сортировка Шелла:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << shellMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "Быстрая сортировка:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << quickMatrix[i][j];
				}
				fout << endl;
			}
			fout << "Результат сортировки разными методами:" << endl;
			fout << "Метод сортировки" << setw(30) << "Число сравнений" << setw(30) << "Число перестановок" << endl;
			fout << "Пузырьковая сортировка" << setw(16) << bubleCount.comparison << setw(30) << bubleCount.permutation << endl;
			fout << "Сортировка отбором" << setw(20) << selectionCount.comparison << setw(30) << selectionCount.permutation << endl;
			fout << "Сортировка вставкой" << setw(19) << insertionCount.comparison << setw(30) << insertionCount.permutation << endl;
			fout << "Сортировка Шелла" << setw(22) << shellCount.comparison << setw(30) << shellCount.permutation << endl;
			fout << "Быстрая сортировка" << setw(20) << quickCount.comparison << setw(30) << quickCount.permutation << endl;
		}
	}
	else { // Если файла не существует 
		fout.open(path);
		// Вывод исходных данных в файл
		fout << "Исходная матрица:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << matrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "Пузырьковая сортировка:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << bubbleMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "Сортировка отбором:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << selectionMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "Сортировка вставкой:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << insertionMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "Сортировка Шелла:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << shellMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "Быстрая сортировка:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << quickMatrix[i][j];
			}
			fout << endl;
		}
		fout << "Результат сортировки разными методами:" << endl;
		fout << "Метод сортировки" << setw(30) << "Число сравнений" << setw(30) << "Число перестановок" << endl;
		fout << "Пузырьковая сортировка" << setw(16) << bubleCount.comparison << setw(30) << bubleCount.permutation << endl;
		fout << "Сортировка отбором" << setw(20) << selectionCount.comparison << setw(30) << selectionCount.permutation << endl;
		fout << "Сортировка вставкой" << setw(19) << insertionCount.comparison << setw(30) << insertionCount.permutation << endl;
		fout << "Сортировка Шелла" << setw(22) << shellCount.comparison << setw(30) << shellCount.permutation << endl;
		fout << "Быстрая сортировка" << setw(20) << quickCount.comparison << setw(30) << quickCount.permutation << endl;
	}
	cout << endl << "Файл успешно сохранён." << endl;
	fout.close();
	// Удаление всех временных матриц
	for (i = 0; i < m; i++)
		delete[] bubbleMatrix[i];
	delete[] bubbleMatrix;
	for (i = 0; i < m; i++)
		delete[] selectionMatrix[i];
	delete[] selectionMatrix;
	for (i = 0; i < m; i++)
		delete[] insertionMatrix[i];
	delete[] insertionMatrix;
	for (i = 0; i < m; i++)
		delete[] shellMatrix[i];
	delete[] shellMatrix;
	for (i = 0; i < m; i++)
		delete[] quickMatrix[i];
	delete[] quickMatrix;
}
