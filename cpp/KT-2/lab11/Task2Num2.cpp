/*2. ������� ���������� �� �������� ������� �����. ��� ���� �������� ��������:
�������, ��� � �����. ��� �������� 1-� ������� ������������� �������� �� �������� ������
(���� � ������, ��� short int). ��� �������� 4-� ������� �������� ����� �������� ����������
(������ ������������� ���� �� 1 �� 100 ������, ��� float). ��� �������� 2-� � 3-� �������
�������� ������ �������� �������� ����������� �� ���������� (������ �� 1 �� 10 ������,
��� short int). ������� ����������� ��� �������. ����������� ������������ ��� union!
�������� ���������, ����������� ������ � ���������� ������ ��� ������ �������. ���������
��� ���������, ������ �������� �� N �������� � ��������� �� � ��������� �����. �����������
�� ������ ���������� ������� ����� � ���� �������*/
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

struct Student {
    string lastName;
    string firstName;
    short grade;
    union {
        short readingSpeed;         // ��� 1 ������
        float finalAssessmentScore; // ��� 4 ������
        short mathTestScore;        // ��� 2 � 3 �������
    } data;
};

void inputStudent(Student& student) {
    cout << "������� �������: ";
    cin >> student.lastName;
    cout << "������� ���: ";
    cin >> student.firstName;
    cout << "������� ����� (1-4): ";
    cin >> student.grade;

    if (student.grade == 1) {
        cout << "������� �������� ������ (���� � ������): ";
        cin >> student.data.readingSpeed;
    }
    else if (student.grade == 4) {
        cout << "������� �������� ����� (�� 1 �� 100): ";
        cin >> student.data.finalAssessmentScore;
    }
    else if (student.grade == 2 || student.grade == 3) {
        cout << "������� ����� �� ���� (�� 1 �� 10): ";
        cin >> student.data.mathTestScore;
    }
    else {
        cout << "������������ �����!" << endl;
    }
}

int main() {
    int N;
    cout << "������� ���������� ��������: ";
    cin >> N;

    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cout << "\n������� " << i + 1 << ":" << endl;
        inputStudent(students[i]);
    }

    ofstream file("students.txt");
    if (!file.is_open()) {
        cout << "���� �� ������� �������." << endl;
        return 1;
    }
    for (const auto& student : students) {
        file << student.lastName << " " << student.firstName << " " << student.grade << " ";
        if (student.grade == 1) {
            file << student.data.readingSpeed << endl;
        }
        else if (student.grade == 4) {
            file << student.data.finalAssessmentScore << endl;
        }
        else if (student.grade == 2 || student.grade == 3) {
            file << student.data.mathTestScore << endl;
        }
    }
    file.close();

    ifstream inputFile("students.txt");
    if (!inputFile.is_open()) {
        cout << "���� �� ������� �������." << endl;
        return 1;
    }

    cout << "\n" << left << setw(15) << "�������" << setw(15) << "���" << setw(7) << "�����" << setw(25) << "������" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    while (true) {
        Student student;
        inputFile >> student.lastName >> student.firstName >> student.grade;
        if (inputFile.fail()) break;
        cout << setw(15) << student.lastName << setw(15) << student.firstName << setw(7) << student.grade;
        if (student.grade == 1) {
            inputFile >> student.data.readingSpeed;
            cout << "�������� ������: " << student.data.readingSpeed << endl;
        }
        else if (student.grade == 4) {
            inputFile >> student.data.finalAssessmentScore;
            cout << "�������� ������: " << student.data.finalAssessmentScore << endl;
        }
        else if (student.grade == 2 || student.grade == 3) {
            inputFile >> student.data.mathTestScore;
            cout << "����� �� ����������: " << student.data.mathTestScore << endl;
        }
    }
    inputFile.close();

    return 0;
}