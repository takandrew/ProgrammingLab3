#include <iomanip>
#include"Menu.h"
#include"Files.h"
#include<stdlib.h>
#include <experimental/filesystem>
using namespace std::experimental::filesystem;

// �������� ������������� �����
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

//�������, �����������, �������� �� ���� ��������� ������ ��� ������. ��������� ���� � �����.
bool ReadOnlyChecking(string path) {
	LPCSTR name = path.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		cout << endl << "� ������ ���� ���������� �������� ������. �������� ������ ��� ������." << endl;
		return false;
	}
	else {
		return true;
	}
}

//�������, ����������� ������������ �����
bool FileCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "������������ ��� �����." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "������������ ��� �����. ��������� ������ ���������� ����� ����� ��������" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "������������ ������ �����. ��������� ���� ������� .txt" << endl;
		return false;
	}
	if (!FileExist(path)) {
		return true;
	}
	if (!is_regular_file(path)) {
		cout << endl << "���� �� �������� �������." << endl;
		return false;
	}
	return true;
}

//�������, ����������� ������������ �����, �� �������� ��������� ������
bool FileReadCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "������������ ��� �����." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "������������ ��� �����. ��������� ������ ���������� ����� ����� ��������" << endl;
		return false;
	}
	if (!FileExist(path)) {
		cout << endl << "����� �� ���������� ���� �� ����������" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "������������ ������ �����. ��������� ���� ������� .txt" << endl;
		return false;
	}
	if (!is_regular_file(path)) {
		cout << endl << "���� �� �������� �������." << endl;
		return false;
	}
	return true;
}

// �������, ����������� �������� �����
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

// ������ ����� ������ ������� �� �����
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


// ������ ����� ������� ������� �� �����
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

// ������ �������� ��������� ������� �� �����
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

// ������ �������� ������ � ����
void FileWriteData(int n, int m, double **matrix) {
	int i, j;
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "������� ���� � �����:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
		cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
		cout << "������� ���� � �����:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // �������� ������������� �����
		if (MenuReWrite() == true) { // ����������� ������ ���������� � ����
			fout.open(path);
			// ����� �������� ������ � ����
			fout << n << endl;
			fout << m << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << matrix[i][j] << endl;
				}
			}
		}
		else { // ����� �� ���������� � ����� ������� ���� � �����
			cout << "������� ���� � �����:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // ���� �������� �������������, ���������� ��� ������ ������� ���� � �����
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
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
			// ����� �������� ������ � ����
			fout << n << endl;
			fout << m << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << matrix[i][j] << endl;
				}
			}
		}
	}
	else { // ���� ����� �� ���������� 
		fout.open(path);
		// ����� �������� ������ � ����
		fout << n << endl;
		fout << m << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << matrix[i][j] << endl;
			}
		}
	}
	cout << endl << "���� ������� �������." << endl;
	fout.close();
}

// ������ ���������� ��������� � ����
void FileWriteResult(int m, int n, double** matrix, ResultCount bubleCount, ResultCount selectionCount,
	ResultCount insertionCount, ResultCount shellCount, ResultCount quickCount) {
	int i, j;
	// �������� � ���������� ��������� ������� ��� ����������� ����������
	double **bubbleMatrix = new double*[m];
	for (i = 0; i < m; i++)
		bubbleMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			bubbleMatrix[i][j] = matrix[i][j];
		}
	}
	bubbleMatrix = BubbleSort_MatrixExport(bubbleMatrix, m, n); // ����������� ����������
	// // �������� � ���������� ��������� ������� ��� ���������� �������
	double **selectionMatrix = new double*[m];
	for (i = 0; i < m; i++)
		selectionMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			selectionMatrix[i][j] = matrix[i][j];
		}
	}
	selectionMatrix = SelectionSort_MatrixExport(selectionMatrix, m, n); // ���������� �������
	// �������� � ���������� ��������� ������� ��� ���������� ��������
	double **insertionMatrix = new double*[m];
	for (i = 0; i < m; i++)
		insertionMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			insertionMatrix[i][j] = matrix[i][j];
		}
	}
	insertionMatrix = InsertionSort_MatrixExport(insertionMatrix, m, n); // ���������� ��������
	// �������� � ���������� ��������� ������� ��� ���������� �����
	double **shellMatrix = new double*[m];
	for (i = 0; i < m; i++)
		shellMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			shellMatrix[i][j] = matrix[i][j];
		}
	}
	shellMatrix = ShellSort_MatrixExport(shellMatrix, m, n); // ���������� �����
	// �������� � ���������� ��������� ������� ��� ������� ����������
	double **quickMatrix = new double*[m];
	for (i = 0; i < m; i++)
		quickMatrix[i] = new double[n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			quickMatrix[i][j] = matrix[i][j];
		}
	}
	quickMatrix = QuickSort_MatrixExport(quickMatrix, n, 0, (m - 1)); // ������� ����������
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "������� ���� � �����:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
		cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
		cout << "������� ���� � �����:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // �������� ������������� �����
		if (MenuReWrite() == true) { // ����������� ������ ���������� � ����
			fout.open(path);
			// ����� �������� ������ � ����
			fout << "�������� �������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << matrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "����������� ����������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << bubbleMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "���������� �������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << selectionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "���������� ��������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << insertionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "���������� �����:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << shellMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "������� ����������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << quickMatrix[i][j];
				}
				fout << endl;
			}
			fout << "��������� ���������� ������� ��������:" << endl;
			fout << "����� ����������" << setw(30) << "����� ���������" << setw(30) << "����� ������������" << endl;
			fout << "����������� ����������" << setw(16) << bubleCount.comparison << setw(30) << bubleCount.permutation << endl;
			fout << "���������� �������" << setw(20) << selectionCount.comparison << setw(30) << selectionCount.permutation << endl;
			fout << "���������� ��������" << setw(19) << insertionCount.comparison << setw(30) << insertionCount.permutation << endl;
			fout << "���������� �����" << setw(22) << shellCount.comparison << setw(30) << shellCount.permutation << endl;
			fout << "������� ����������" << setw(20) << quickCount.comparison << setw(30) << quickCount.permutation << endl;
		}
		else { // ����� �� ���������� � ����� ������� ���� � �����
			cout << "������� ���� � �����:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // ���� �������� �������������, ���������� ��� ������ ������� ���� � �����
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
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
			// ����� �������� ������ � ����
			fout << "�������� �������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << matrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "����������� ����������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << bubbleMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "���������� �������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << selectionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "���������� ��������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << insertionMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "���������� �����:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << shellMatrix[i][j];
				}
				fout << endl;
			}
			fout << endl << "������� ����������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					fout << setw(6) << quickMatrix[i][j];
				}
				fout << endl;
			}
			fout << "��������� ���������� ������� ��������:" << endl;
			fout << "����� ����������" << setw(30) << "����� ���������" << setw(30) << "����� ������������" << endl;
			fout << "����������� ����������" << setw(16) << bubleCount.comparison << setw(30) << bubleCount.permutation << endl;
			fout << "���������� �������" << setw(20) << selectionCount.comparison << setw(30) << selectionCount.permutation << endl;
			fout << "���������� ��������" << setw(19) << insertionCount.comparison << setw(30) << insertionCount.permutation << endl;
			fout << "���������� �����" << setw(22) << shellCount.comparison << setw(30) << shellCount.permutation << endl;
			fout << "������� ����������" << setw(20) << quickCount.comparison << setw(30) << quickCount.permutation << endl;
		}
	}
	else { // ���� ����� �� ���������� 
		fout.open(path);
		// ����� �������� ������ � ����
		fout << "�������� �������:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << matrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "����������� ����������:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << bubbleMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "���������� �������:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << selectionMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "���������� ��������:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << insertionMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "���������� �����:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << shellMatrix[i][j];
			}
			fout << endl;
		}
		fout << endl << "������� ����������:" << endl;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << setw(6) << quickMatrix[i][j];
			}
			fout << endl;
		}
		fout << "��������� ���������� ������� ��������:" << endl;
		fout << "����� ����������" << setw(30) << "����� ���������" << setw(30) << "����� ������������" << endl;
		fout << "����������� ����������" << setw(16) << bubleCount.comparison << setw(30) << bubleCount.permutation << endl;
		fout << "���������� �������" << setw(20) << selectionCount.comparison << setw(30) << selectionCount.permutation << endl;
		fout << "���������� ��������" << setw(19) << insertionCount.comparison << setw(30) << insertionCount.permutation << endl;
		fout << "���������� �����" << setw(22) << shellCount.comparison << setw(30) << shellCount.permutation << endl;
		fout << "������� ����������" << setw(20) << quickCount.comparison << setw(30) << quickCount.permutation << endl;
	}
	cout << endl << "���� ������� �������." << endl;
	fout.close();
	// �������� ���� ��������� ������
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
