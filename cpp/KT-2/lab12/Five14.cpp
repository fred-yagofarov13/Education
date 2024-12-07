/*Five14. В текстовом файле находится список учеников.
Для каждого ученика указан его балл ЕГЭ по информатике.
Отсортировать эти данные по ключу: балл(убыв.)+фамилия(возр.).
Для сортировки использовать Шейкер-сортировку.
Отсортированные данные вывести в другой текстовый файл, выровняв по столбцам.
Под фамилию отведено 15 позиций, под баллы ЕГЭ 3 позиции.
Фамилию выровнять по левому краю, а баллы ЕГЭ по правому*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

// Функция для генерации случайных фамилий
string generateRandomLastName() {
    vector<string> lastNames = { "Иванов", "Петров", "Сидоров", "Кузнецов", "Морозов", "Васильев", "Новиков",
                                "Федоров", "Козлов", "Смирнов", "Зайцев", "Попов", "Лебедев", "Григорьев", "Шевченко" };
    return lastNames[rand() % lastNames.size()];
}

// Шейкер-сортировка с учётом баллов (по убыванию) и фамилий (по возрастанию)
void shakerSort(string* students, int* scores, int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо (сортировка по баллам) и сравнение фамилий при равных баллах
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

        // Проход справа налево (сортировка по фамилиям) и сравнение баллов при равных фамилиях
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

// Генерация тестовых данных для сортировки
void generateTestData(const string& filename, int n) {
    ofstream fout(filename);
    fout << n << endl;
    for (int i = 0; i < n; ++i) {
        fout << generateRandomLastName() << " " << rand() % 101 << endl; // Заполняем случайными фамилиями и баллами
    }
    fout.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    string inputFileName = "students.txt";
    string outputFileName = "sorted_students.txt";

    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    generateTestData(inputFileName, n); // Генерация случайных данных

    ifstream fin(inputFileName);
    ofstream fout(outputFileName);

    if (!fin.is_open()) {
        cout << "Ошибка открытия входного файла!" << endl;
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

    // Сортировка студентов
    shakerSort(students, scores, studentCount);

    if (!fout.is_open()) {
        cout << "Ошибка открытия выходного файла!" << endl;
        return 1;
    }

    fout << studentCount << endl;

    // Вывод отсортированных данных в файл
    for (int i = 0; i < studentCount; i++) {
        fout << left << setw(15) << students[i] << right << setw(3) << scores[i] << endl;
    }

    fout.close();

    delete[] students;
    delete[] scores;

    cout << "Сортировка завершена. Результаты записаны в файл " << outputFileName << endl;

    return 0;
}
