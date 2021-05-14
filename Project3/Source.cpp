#include <iostream>
#include <iomanip>
#include"Computing.h"
#include"Files.h"
#include"Menu.h"
#include"Testing.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // Вывод приветствия
	Testing(); // Тестирование модулей
	while (true) {
		int i, j;
		int n = 1, m = 1;
		double **matrix = nullptr;
		delete[] matrix;
		int importYes = 1;
		int importNo = 2;
		int importDataAnswer = MenuImportData(); // Выбор происхождения исходных данных
		if (importDataAnswer == importYes) { // Чтение исходных данных из файла
			ifstream fin;
			bool fileReadCorrectCheck = 0;
			cout << "Введите путь к файлу:" << endl;
			string path;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			fileReadCorrectCheck = FileReadCorrectChecking(path);
			while (fileReadCorrectCheck == false) { // Проверка корректности файла
				cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
			}
			fin.open(path);
			n = FileReadLineSize(path); // Чтение значения длины строки из файла
			m = FileReadColumnSize(path); // Чтение значения длины столбца из файла
			fin.close();
			while (!((n > 0) && (m > 0))) { // Проверка корректности полученного значения длины строки
				cout << "Некорректное значение длины строки или столбца матрицы в данном файле. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // Проверка корректности файла
					cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				n = FileReadLineSize(path); // Чтение значения длины строки из файла
				m = FileReadColumnSize(path); // Чтение значения длины столбца из файла
				fin.close();
			}
			fin.open(path);
			int countData = 0;
			double tempData = 0;
			while (fin) { // Проверка количества полученных данных
				fin >> tempData;
				if (fin.fail()) {
					break;
				}
				if (countData == ((n*m) + 2))
					break;
				countData++;
			}
			fin.close();
			while (countData != ((n*m) + 2)) {
				cout << "В файле недостаточно данных. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // Проверка корректности файла
					cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				n = FileReadLineSize(path); // Чтение значения длины строки из файла
				m = FileReadColumnSize(path); // Чтение значения длины столбца из файла
				fin.close();
				while (!((n > 0) && (m > 0))) { // Проверка корректности полученного значения длины строки
					cout << "Некорректное значение длины строки или столбца матрицы в данном файле. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
					while (fileReadCorrectCheck == false) { // Проверка корректности файла
						cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
						cout << "Введите путь к файлу:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						fileReadCorrectCheck = FileReadCorrectChecking(path);
					}
					fin.open(path);
					n = FileReadLineSize(path); // Чтение значения длины строки из файла
					m = FileReadColumnSize(path); // Чтение значения длины столбца из файла
					fin.close();
				}
				SetConsoleCP(866);
				tempData = 0;
				countData = 0;
				fin.open(path);
				while (fin) { // Проверка количества полученных данных
					fin >> tempData;
					if (fin.fail()) {
						break;
					}
					if (countData == ((n*m) + 2))
						break;
					countData++;
				}
				fin.close();
			}
			// Создание матрицы
			matrix = new double*[m];
			for (i = 0; i < m; i++)
				matrix[i] = new double[n];
			matrix = FileReadMatrix(n, m, matrix, path); //Чтение значения элементов матрицы из файла
			cout << endl << "Исходная матрица:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					cout << setw(6) << matrix[i][j];
				}
				cout << endl;
			}
		}
		else if (importDataAnswer == importNo) { // Ввод исходных данных с клавиатуры
			cout << "Введите длину строки матрицы: " << endl;
			n = NumInInt();
			while (!(n > 0)) {
				cout << "Некорректно введенные данные. Пожалуйста, попробуйте еще раз: " << endl;
				n = NumInInt();
			}
			cout << "Введите длину столбца матрицы: " << endl;
			m = NumInInt();
			while (!(m > 0)) {
				cout << "Некорректно введенные данные. Пожалуйста, попробуйте еще раз: " << endl;
				m = NumInInt();
			}
			// Создание матрицы
			matrix = new double*[m];
			for (i = 0; i < m; i++)
				matrix[i] = new double[n];
			cout << "Введите значения матрицы:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					matrix[i][j] = NumInDouble();
				}
			}
			cout << endl << "Исходная матрица:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					cout << setw(6) << matrix[i][j];
				}
				cout << endl;
			}
			if (MenuExportData() == true) { // Возможность сохранения исходных данных в файл
				FileWriteData(n, m, matrix);
			}
		}
		else { // Заполнение элементов матрицы случайными числами
			cout << "Введите длину строки матрицы: " << endl;
			n = NumInInt();
			while (!(n > 0)) {
				cout << "Некорректно введенные данные. Пожалуйста, попробуйте еще раз: " << endl;
				n = NumInInt();
			}
			cout << "Введите длину столбца матрицы: " << endl;
			m = NumInInt();
			while (!(m > 0)) {
				cout << "Некорректно введенные данные. Пожалуйста, попробуйте еще раз: " << endl;
				m = NumInInt();
			}
			// Создание матрицы
			matrix = new double*[m];
			for (i = 0; i < m; i++)
				matrix[i] = new double[n];
			srand((unsigned)time(NULL));
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					matrix[i][j] = 1 + rand() % 1000;
				}
			}
			cout << endl << "Сгенерированная матрица" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					cout << setw(6) << matrix[i][j];
				}
				cout << endl;
			}
			if (MenuExportData() == true) { // Возможность сохранения исходных данных в файл
				FileWriteData(n, m, matrix);
			}
		}
		Sorting(matrix, m, n); // Вызов функции сортировки матрицы разными методами
		// Удаление матрицы
		for (i = 0; i < m; i++)
			delete[] matrix[i];
		delete[] matrix;
		if (Menu() == false) // Вызов основного меню после работы программы 
			return false;
	}
	return 0;
}