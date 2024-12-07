/*Five14. � ��������� ����� ��������� ������ ��������.
��� ������� ������� ������ ��� ���� ��� �� �����������.
������������� ��� ������ �� �����: ����(����.)+�������(����.).
��� ���������� ������������ ������-����������.
��������������� ������ ������� � ������ ��������� ����, �������� �� ��������.
��� ������� �������� 15 �������, ��� ����� ��� 3 �������.
������� ��������� �� ������ ����, � ����� ��� �� �������*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

// ������� ��� ��������� ��������� �������
string generateRandomLastName() {
    vector<string> lastNames = { "������", "������", "�������", "��������", "�������", "��������", "�������",
                                "�������", "������", "�������", "������", "�����", "�������", "���������", "��������" };
    return lastNames[rand() % lastNames.size()];
}

// ������-���������� � ������ ������ (�� ��������) � ������� (�� �����������)
void shakerSort(string* students, int* scores, int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // ������ ����� ������� (���������� �� ������) � ��������� ������� ��� ������ ������
        for (int i = start; i < end; ++i) {
            if (scores[i] < scores[i + 1] || (scores[i] == scores[i + 1] && students[i] > students[i + 1])) {
                swap(scores[i], scores[i + 1]);
                swap(students[i], students[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        // ������ ������ ������ (���������� �� ��������) � ��������� ������ ��� ������ ��������
        for (int i = end - 1; i >= start; --i) {
            if (scores[i] < scores[i + 1] || (scores[i] == scores[i + 1] && students[i] > students[i + 1])) {
                swap(scores[i], scores[i + 1]);
                swap(students[i], students[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

// ��������� �������� ������ ��� ����������
void generateTestData(const string& filename, int n) {
    ofstream fout(filename);
    fout << n << endl;
    for (int i = 0; i < n; ++i) {
        fout << generateRandomLastName() << " " << rand() % 101 << endl; // ��������� ���������� ��������� � �������
    }
    fout.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    string inputFileName = "students.txt";
    string outputFileName = "sorted_students.txt";

    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;

    generateTestData(inputFileName, n); // ��������� ��������� ������

    ifstream fin(inputFileName);
    ofstream fout(outputFileName);

    if (!fin.is_open()) {
        cout << "������ �������� �������� �����!" << endl;
        return 1;
    }

    int studentCount;
    fin >> studentCount;

    string* students = new string[studentCount];
    int* scores = new int[studentCount];

    for (int i = 0; i < studentCount; i++) {
        fin >> students[i] >> scores[i];
    }

    fin.close();

    // ���������� ���������
    shakerSort(students, scores, studentCount);

    if (!fout.is_open()) {
        cout << "������ �������� ��������� �����!" << endl;
        return 1;
    }

    fout << studentCount << endl;

    // ����� ��������������� ������ � ����
    for (int i = 0; i < studentCount; i++) {
        fout << left << setw(15) << students[i] << right << setw(3) << scores[i] << endl;
    }

    fout.close();

    delete[] students;
    delete[] scores;

    cout << "���������� ���������. ���������� �������� � ���� " << outputFileName << endl;

    return 0;
}
