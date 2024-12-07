/*Sort2. ���� ����������� N � ������ ����� ����� ����������� N.
������������� ������ ������ �� ����������� ������� ������� �������.
� �������� ���������� ��������������� ����� ����������� � ����� �������.
������� ���������� ������� ����� ������ �������� ����������.
����� ��������� ���������� ������� ����� ��������, � ���������� ��������
���� ������� ������� �������������� ������ �� ���������� ����� � ��������������� �������.
��� ������ ������� ��������������� ����� �������� �� ����������������� � ������� ������� |.
�������� ���������� �������� � ��������� ����*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int N;
	ofstream fout("output.txt");


	cout << "������� ������ �������: ";
	cin >> N;

	int* massNums = new int[N];

	cout << "������� �������� �������: ";

	for (int i = 0; i < N; i++) {
		cin >> massNums[i];
	}

	if (fout.is_open()) {
		int temp;
		int count = 0;

		// ���������� ������� ������� ������� ������� (����������� ����������)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (massNums[j] > massNums[j + 1]) {
					temp = massNums[j];
					massNums[j] = massNums[j + 1];
					massNums[j + 1] = temp;
				}
			}

			fout << "�������� " << i + 1 << ": ";
			for (int k = 0; k < N; k++) {
				fout << massNums[k] << " ";
				if (k == count) {
					fout << "| ";
				}
			}
			fout << endl;
			count++;
		}

		fout << "��������������� ������: ";
		for (int i = 0; i < N; i++) {
			fout << massNums[i] << " ";

			if (i == count) {
				fout << "| ";
			}
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
		return 1;
	}

	delete[] massNums;
	fout.close();

	cout << "������ ������� �������� � ���� output.txt" << endl;

	return 0;
}