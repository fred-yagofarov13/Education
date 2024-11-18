#include <iostream>
#include <cmath>

using namespace std;

double calculate(double x, int n) {
	double sum = 0;
	double term = x;
	int sign = 1;
	
	for (int i = 1; i <= n; ++i) {
		sum += sign * term;
		sign = -sign;

		term *= x * x / ((2 * i) * (2 * i + 1));
	}

	return sum;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int n;
	double x;

	cout << "Введите значение x: ";
	cin >> x;
	cout << "Введите количество членов ряда n: ";
	cin >> n;

	double result = calculate(x, n);
	cout << "Точное значение sin(" << x << ") = " << sin(x) << endl;
	cout << "Приближённое значение суммы числового ряда: " << result << endl;


	return 0;
}