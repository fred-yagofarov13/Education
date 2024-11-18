#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Программа определяет площадь круга, если известна длина окружности, ограничивающей этот круг. В качестве PI = 3.1415" << endl << endl;

	try {
		const double PI = 3.1415;  // Константа для числа π
		double circumference;      // Длина окружности
		double radius, area;       // Радиус и площадь круга

		// Выводим приглашение для ввода
		cout << "Вычисление площади круга по длине окружности:" << endl;
		cout << "Введите длину окружности (см) -> ";
		cin >> circumference;

		// Вычисляем радиус
		radius = circumference / (2 * PI);

		// Вычисляем площадь круга
		area = PI * radius * radius;

		// Выводим результат
		cout << "Площадь круга " << area << " кв.см." << endl;
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}