/*2. Имеется информация об учениках младшей школы. Для всех учеников известны:
фамилия, имя и класс. Для учеников 1-х классов дополнительно известна их скорость чтения
(слов в минуту, тип short int). Для учеников 4-х классов известны баллы итоговой аттестации
(единый муниципальный тест от 1 до 100 баллов, тип float). Для учеников 2-х и 3-х классов
известны данные итоговой школьной контрольной по математике (оценки от 1 до 10 баллов,
тип short int). Описать структурный тип «ученик». Обязательно использовать тип union!
Написать процедуру, позволяющую ввести с клавиатуры данные для одного ученика. Используя
эту процедуру, ввести сведения об N учениках и сохранить их в текстовом файле. Распечатать
на экране содержимое данного файла в виде таблицы*/
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
        short readingSpeed;         // Для 1 класса
        float finalAssessmentScore; // Для 4 класса
        short mathTestScore;        // Для 2 и 3 классов
    } data;
};

void inputStudent(Student& student) {
    cout << "Введите фамилию: ";
    cin >> student.lastName;
    cout << "Введите имя: ";
    cin >> student.firstName;
    cout << "Введите класс (1-4): ";
    cin >> student.grade;

    if (student.grade == 1) {
        cout << "Введите скорость чтения (слов в минуту): ";
        cin >> student.data.readingSpeed;
    }
    else if (student.grade == 4) {
        cout << "Введите итоговые баллы (от 1 до 100): ";
        cin >> student.data.finalAssessmentScore;
    }
    else if (student.grade == 2 || student.grade == 3) {
        cout << "Введите баллы за тест (от 1 до 10): ";
        cin >> student.data.mathTestScore;
    }
    else {
        cout << "Некорректный класс!" << endl;
    }
}

int main() {
    int N;
    cout << "Введите количество учеников: ";
    cin >> N;

    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cout << "\nСтудент " << i + 1 << ":" << endl;
        inputStudent(students[i]);
    }

    ofstream file("students.txt");
    if (!file.is_open()) {
        cout << "Файл не удалось открыть." << endl;
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
        cout << "Файл не удалось открыть." << endl;
        return 1;
    }

    cout << "\n" << left << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(7) << "Класс" << setw(25) << "Данные" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    while (true) {
        Student student;
        inputFile >> student.lastName >> student.firstName >> student.grade;
        if (inputFile.fail()) break;
        cout << setw(15) << student.lastName << setw(15) << student.firstName << setw(7) << student.grade;
        if (student.grade == 1) {
            inputFile >> student.data.readingSpeed;
            cout << "Скорость чтения: " << student.data.readingSpeed << endl;
        }
        else if (student.grade == 4) {
            inputFile >> student.data.finalAssessmentScore;
            cout << "Итоговая оценка: " << student.data.finalAssessmentScore << endl;
        }
        else if (student.grade == 2 || student.grade == 3) {
            inputFile >> student.data.mathTestScore;
            cout << "Баллы за математику: " << student.data.mathTestScore << endl;
        }
    }
    inputFile.close();

    return 0;
}