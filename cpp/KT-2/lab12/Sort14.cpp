/*Sort14. ���� ����� ����� X � ��������� ����.
� ����� ������� ����� ����� �����, ������������� � ����������� �������.
� ������� ������ ��������� ������ ���������� ������ ������ ������ ��������� ����� X � �������� �����.
��������� ��������� ���������� � ����. ���� ������� �� ������, ������� -1. ����� � �������� ������ �� ����� 200*/
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int X;

	ifstream fin("input.txt");
	ofstream fout1("input.txt");
	ofstream fout2("output.txt");

	cout << "������� ����� X: ";
	cin >> X;

	int* massNums = new int[200];
	int count = 0;

	if (fout1.is_open()) {

		fout1 << X << endl;

		while (!fin.eof()) {
			if (count == 200) {
				break;
			}

			if (count == 0) {
				massNums[count] = rand() % 5;
				fout1 << massNums[count] << " ";
			}
			else {
				massNums[count] = massNums[count - 1] + rand() % 5;
				fout1 << massNums[count] << " ";
			}
			count++;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
		return 1;
	}

	if (fin.is_open()) {
		// �������� ����� ������ ������ ��������� ����� X � �������� ����� �����
		int left = 0;
		int right = count - 1;
		int middle;
		int index = -1;
		while (left <= right) {
			middle = (left + right) / 2;
			if (massNums[middle] == X) {
				index = middle;
				right = middle - 1;
			}
			else if (massNums[middle] < X) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		fout2 << index;
		delete[] massNums;
	}
	else {
		cout << "������ �������� �����!" << endl;
		return 1;
	}

	fin.close();
	fout1.close();
	fout2.close();

	cout << "������ ������� �������� � ����� input.txt � output.txt" << endl;

	return 0;
}