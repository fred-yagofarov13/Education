#include <iostream>
#include <cmath>

using namespace std;

double abs_value(double x) {
	return (x < 0) ? -x : x;
}

double Sin1(double x, double epsilon) {
	double sum = 0;
	double term = x;
	int sign = 1;
	long long i = 1;

	while (abs_value(term) > epsilon) {
		sum += sign * term;
		sign = -sign;

		term *= x * x / ((2 * i) * (2 * i + 1));
		
		i++;
	}

	return sum;
}

int main() {

	setlocale(LC_ALL, "Russian");

	double x, epsilon;

	cout << "Программа вычисляет приближенное значение функции sin(x)" << endl << endl;

	cout << "Введите значение x: ";
	cin >> x;

	for (int i = 0; i < 6; ++i) {
		cout << "Введите значение eps (точность): ";
		cin >> epsilon;

		double result = Sin1(x, epsilon);

		cout << "Точное значение sin(" << x << ") = " << sin(x) << endl;
		cout << "Приближённое значение sin(" << x << ") при eps = " << epsilon << ": " << result << endl << endl;
	}


	return 0;
}