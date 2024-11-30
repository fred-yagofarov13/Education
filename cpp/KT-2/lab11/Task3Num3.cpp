/*3. Работа со студентами. Создать структуру Student, которая содержит имя студента,
возраст и средний балл. Реализовать функции для добавления студента, вывода информации о
студенте, подсчета количества студентов с высоким средним баллом (например, выше 4.0) и
поиск студентов по возрасту. Добавить возможность изменения информации о студенте и
вычисления общего среднего балла для определённых студентов.*/
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

/*Структура студента*/
struct Student {
    string name;
    int age;
    float averageScore;
};

/*Добавить студента*/
void addStudent(vector<Student>& students) {
    Student student;
    cout << "Введите имя студента: ";
    cin >> student.name;
    cout << "Введите возраст студента: ";
    cin >> student.age;
    cout << "Введите средний балл студента: ";
    cin >> student.averageScore;
    students.push_back(student);
}

/*Вывести информацию о студенте*/
void displayStudent(const Student& student) {
    cout << "Имя: " << student.name << ", Возраст: " << student.age << ", Средний балл: " << student.averageScore << endl;
}

/*Подсчитать количество студентов с высоким средним баллом*/ // выше 4.0
int countHighScoreStudents(const vector<Student>& students, float threshold = 4.0) {
    int count = 0;
    for (const auto& student : students) {
        if (student.averageScore > threshold) {
            count++;
        }
    }
    return count;
}

/*Поиск студентов по возрасту*/
vector<Student> findStudentsByAge(const vector<Student>& students, int age) {
    vector<Student> result;
    for (const auto& student : students) {
        if (student.age == age) {
            result.push_back(student);
        }
    }
    return result;
}
/*Обновить информацию о студенте*/
void modifyStudent(Student& student) {
    cout << "Изменение информации о студенте " << student.name << endl;
    cout << "Введите новое имя (текущее: " << student.name << "): ";
    cin >> student.name;
    cout << "Введите новый возраст (текущий: " << student.age << "): ";
    cin >> student.age;
    cout << "Введите новый средний балл (текущий: " << student.averageScore << "): ";
    cin >> student.averageScore;
}

/*Вычислить средний балл*/
float calculateAverageScore(const vector<Student>& students) {
    if (students.empty()) return 0.0f;
    float total = 0.0f;
    for (const auto& student : students) {
        total += student.averageScore;
    }
    return total / students.size();
}

/*Главная функция*/
int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Вывести информацию о студентах\n";
        cout << "3. Подсчитать количество студентов с высоким средним баллом\n";
        cout << "4. Поиск студентов по возрасту\n";
        cout << "5. Изменить информацию о студенте\n";
        cout << "6. Вычислить средний балл\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
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
            cout << "Количество студентов со средним баллом выше 4.0: " << count << endl;
            break;
        }
        case 4: {
            int age;
            cout << "Введите возраст для поиска: ";
            cin >> age;
            vector<Student> found = findStudentsByAge(students, age);
            for (const auto& student : found) {
                displayStudent(student);
            }
            break;
        }
        case 5: {
            string name;
            cout << "Введите имя студента для изменения: ";
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
                cout << "Студент с именем " << name << " не найден.\n";
            }
            break;
        }
        case 6: {
            int subChoice;
            cout << "Вычислить средний балл для:\n";
            cout << "1. Всех студентов\n";
            cout << "2. Студентов по возрасту\n";
            cout << "Выберите вариант: ";
            cin >> subChoice;
            if (subChoice == 1) {
                float average = calculateAverageScore(students);
                cout << "Общий средний балл: " << average << endl;
            }
            else if (subChoice == 2) {
                int age;
                cout << "Введите возраст: ";
                cin >> age;
                vector<Student> found = findStudentsByAge(students, age);
                float average = calculateAverageScore(found);
                cout << "Средний балл студентов возрастом " << age << ": " << average << endl;
            }
            else {
                cout << "Некорректный выбор.\n";
            }
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}