#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Программа определяет, является ли заданный треугольник со сторонами a, b, c, прямоугольным" << endl << endl;

    cout << "Приведём 3 примера работы программы:" << endl;

    cout << "Пример 1:" << "\ta = 3 b = 4 c = 5" << endl;
    cout << "Результат: Треугольник прямоугольный." << endl << endl;

    cout << "Пример 2:" << "\ta = a b = b c = c" << endl;
    cout << "Результат: Треугольник не является прямоугольным." << endl << endl;

    cout << "Пример 3:" << "\ta = 1 b = 2 c = 3" << endl;
    cout << "Результат: Треугольник не является прямоугольным." << endl << endl;

    cout << "Итак, начнём работу. Для начала ";

	try {
        // Ввод сторон треугольника
        double a, b, c;
        cout << "введите длины сторон треугольника: ";
        cin >> a >> b >> c;

        if (typeid(a).name() != typeid(double).name() || typeid(b).name() != typeid(double).name() || typeid(c).name() != typeid(double).name())
            throw invalid_argument("Некорректный ввод данных");

        // Определяем, какая сторона самая длинная (гипотенуза)
        double max_side = max(a, max(b, c));
        double other1, other2;

        if (max_side == a) {
            other1 = b;
            other2 = c;
        }
        else if (max_side == b) {
            other1 = a;
            other2 = c;
        }
        else {
            other1 = a;
            other2 = b;
        }

        // Проверяем теорему Пифагора
        bool isRightTriangle = (max_side * max_side == other1 * other1 + other2 * other2);

        // Вывод результата
        if (isRightTriangle) {
            cout << "Результат: " << "Треугольник прямоугольный." << endl;
        }
        else {
            cout << "Результат: " << "Треугольник не является прямоугольным." << endl;
        }
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}