/*3. ������ �� ����������. ������� ��������� Student, ������� �������� ��� ��������,
������� � ������� ����. ����������� ������� ��� ���������� ��������, ������ ���������� �
��������, �������� ���������� ��������� � ������� ������� ������ (��������, ���� 4.0) �
����� ��������� �� ��������. �������� ����������� ��������� ���������� � �������� �
���������� ������ �������� ����� ��� ����������� ���������.*/
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

/*��������� ��������*/
struct Student {
    string name;
    int age;
    float averageScore;
};

/*�������� ��������*/
void addStudent(vector<Student>& students) {
    Student student;
    cout << "������� ��� ��������: ";
    cin >> student.name;
    cout << "������� ������� ��������: ";
    cin >> student.age;
    cout << "������� ������� ���� ��������: ";
    cin >> student.averageScore;
    students.push_back(student);
}

/*������� ���������� � ��������*/
void displayStudent(const Student& student) {
    cout << "���: " << student.name << ", �������: " << student.age << ", ������� ����: " << student.averageScore << endl;
}

/*���������� ���������� ��������� � ������� ������� ������*/ // ���� 4.0
int countHighScoreStudents(const vector<Student>& students, float threshold = 4.0) {
    int count = 0;
    for (const auto& student : students) {
        if (student.averageScore > threshold) {
            count++;
        }
    }
    return count;
}

/*����� ��������� �� ��������*/
vector<Student> findStudentsByAge(const vector<Student>& students, int age) {
    vector<Student> result;
    for (const auto& student : students) {
        if (student.age == age) {
            result.push_back(student);
        }
    }
    return result;
}
/*�������� ���������� � ��������*/
void modifyStudent(Student& student) {
    cout << "��������� ���������� � �������� " << student.name << endl;
    cout << "������� ����� ��� (�������: " << student.name << "): ";
    cin >> student.name;
    cout << "������� ����� ������� (�������: " << student.age << "): ";
    cin >> student.age;
    cout << "������� ����� ������� ���� (�������: " << student.averageScore << "): ";
    cin >> student.averageScore;
}

/*��������� ������� ����*/
float calculateAverageScore(const vector<Student>& students) {
    if (students.empty()) return 0.0f;
    float total = 0.0f;
    for (const auto& student : students) {
        total += student.averageScore;
    }
    return total / students.size();
}

/*������� �������*/
int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n����:\n";
        cout << "1. �������� ��������\n";
        cout << "2. ������� ���������� � ���������\n";
        cout << "3. ���������� ���������� ��������� � ������� ������� ������\n";
        cout << "4. ����� ��������� �� ��������\n";
        cout << "5. �������� ���������� � ��������\n";
        cout << "6. ��������� ������� ����\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            for (const auto& student : students) {
                displayStudent(student);
            }
            break;
        case 3: {
            int count = countHighScoreStudents(students);
            cout << "���������� ��������� �� ������� ������ ���� 4.0: " << count << endl;
            break;
        }
        case 4: {
            int age;
            cout << "������� ������� ��� ������: ";
            cin >> age;
            vector<Student> found = findStudentsByAge(students, age);
            for (const auto& student : found) {
                displayStudent(student);
            }
            break;
        }
        case 5: {
            string name;
            cout << "������� ��� �������� ��� ���������: ";
            cin >> name;
            bool found = false;
            for (auto& student : students) {
                if (student.name == name) {
                    modifyStudent(student);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "������� � ������ " << name << " �� ������.\n";
            }
            break;
        }
        case 6: {
            int subChoice;
            cout << "��������� ������� ���� ���:\n";
            cout << "1. ���� ���������\n";
            cout << "2. ��������� �� ��������\n";
            cout << "�������� �������: ";
            cin >> subChoice;
            if (subChoice == 1) {
                float average = calculateAverageScore(students);
                cout << "����� ������� ����: " << average << endl;
            }
            else if (subChoice == 2) {
                int age;
                cout << "������� �������: ";
                cin >> age;
                vector<Student> found = findStudentsByAge(students, age);
                float average = calculateAverageScore(found);
                cout << "������� ���� ��������� ��������� " << age << ": " << average << endl;
            }
            else {
                cout << "������������ �����.\n";
            }
            break;
        }
        case 0:
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "������������ �����. ���������� �����.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}