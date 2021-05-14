#include <iostream>
#include <iomanip>
#include"Computing.h"
#include"Files.h"
#include"Menu.h"
#include"Testing.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // ����� �����������
	Testing(); // ������������ �������
	while (true) {
		int i, j;
		int n = 1, m = 1;
		double **matrix = nullptr;
		delete[] matrix;
		int importYes = 1;
		int importNo = 2;
		int importDataAnswer = MenuImportData(); // ����� ������������� �������� ������
		if (importDataAnswer == importYes) { // ������ �������� ������ �� �����
			ifstream fin;
			bool fileReadCorrectCheck = 0;
			cout << "������� ���� � �����:" << endl;
			string path;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			fileReadCorrectCheck = FileReadCorrectChecking(path);
			while (fileReadCorrectCheck == false) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
			}
			fin.open(path);
			n = FileReadLineSize(path); // ������ �������� ����� ������ �� �����
			m = FileReadColumnSize(path); // ������ �������� ����� ������� �� �����
			fin.close();
			while (!((n > 0) && (m > 0))) { // �������� ������������ ����������� �������� ����� ������
				cout << "������������ �������� ����� ������ ��� ������� ������� � ������ �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // �������� ������������ �����
					cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				n = FileReadLineSize(path); // ������ �������� ����� ������ �� �����
				m = FileReadColumnSize(path); // ������ �������� ����� ������� �� �����
				fin.close();
			}
			fin.open(path);
			int countData = 0;
			double tempData = 0;
			while (fin) { // �������� ���������� ���������� ������
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
				cout << "� ����� ������������ ������. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // �������� ������������ �����
					cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				n = FileReadLineSize(path); // ������ �������� ����� ������ �� �����
				m = FileReadColumnSize(path); // ������ �������� ����� ������� �� �����
				fin.close();
				while (!((n > 0) && (m > 0))) { // �������� ������������ ����������� �������� ����� ������
					cout << "������������ �������� ����� ������ ��� ������� ������� � ������ �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
					while (fileReadCorrectCheck == false) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						fileReadCorrectCheck = FileReadCorrectChecking(path);
					}
					fin.open(path);
					n = FileReadLineSize(path); // ������ �������� ����� ������ �� �����
					m = FileReadColumnSize(path); // ������ �������� ����� ������� �� �����
					fin.close();
				}
				SetConsoleCP(866);
				tempData = 0;
				countData = 0;
				fin.open(path);
				while (fin) { // �������� ���������� ���������� ������
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
			// �������� �������
			matrix = new double*[m];
			for (i = 0; i < m; i++)
				matrix[i] = new double[n];
			matrix = FileReadMatrix(n, m, matrix, path); //������ �������� ��������� ������� �� �����
			cout << endl << "�������� �������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					cout << setw(6) << matrix[i][j];
				}
				cout << endl;
			}
		}
		else if (importDataAnswer == importNo) { // ���� �������� ������ � ����������
			cout << "������� ����� ������ �������: " << endl;
			n = NumInInt();
			while (!(n > 0)) {
				cout << "����������� ��������� ������. ����������, ���������� ��� ���: " << endl;
				n = NumInInt();
			}
			cout << "������� ����� ������� �������: " << endl;
			m = NumInInt();
			while (!(m > 0)) {
				cout << "����������� ��������� ������. ����������, ���������� ��� ���: " << endl;
				m = NumInInt();
			}
			// �������� �������
			matrix = new double*[m];
			for (i = 0; i < m; i++)
				matrix[i] = new double[n];
			cout << "������� �������� �������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					matrix[i][j] = NumInDouble();
				}
			}
			cout << endl << "�������� �������:" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					cout << setw(6) << matrix[i][j];
				}
				cout << endl;
			}
			if (MenuExportData() == true) { // ����������� ���������� �������� ������ � ����
				FileWriteData(n, m, matrix);
			}
		}
		else { // ���������� ��������� ������� ���������� �������
			cout << "������� ����� ������ �������: " << endl;
			n = NumInInt();
			while (!(n > 0)) {
				cout << "����������� ��������� ������. ����������, ���������� ��� ���: " << endl;
				n = NumInInt();
			}
			cout << "������� ����� ������� �������: " << endl;
			m = NumInInt();
			while (!(m > 0)) {
				cout << "����������� ��������� ������. ����������, ���������� ��� ���: " << endl;
				m = NumInInt();
			}
			// �������� �������
			matrix = new double*[m];
			for (i = 0; i < m; i++)
				matrix[i] = new double[n];
			srand((unsigned)time(NULL));
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					matrix[i][j] = 1 + rand() % 1000;
				}
			}
			cout << endl << "��������������� �������" << endl;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					cout << setw(6) << matrix[i][j];
				}
				cout << endl;
			}
			if (MenuExportData() == true) { // ����������� ���������� �������� ������ � ����
				FileWriteData(n, m, matrix);
			}
		}
		Sorting(matrix, m, n); // ����� ������� ���������� ������� ������� ��������
		// �������� �������
		for (i = 0; i < m; i++)
			delete[] matrix[i];
		delete[] matrix;
		if (Menu() == false) // ����� ��������� ���� ����� ������ ��������� 
			return false;
	}
	return 0;
}