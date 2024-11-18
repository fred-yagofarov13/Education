#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Программа вычисляет выражение (a/b+c/d+k/m)*e/f: " << endl << endl;

	try
	{
		double a, b, c, d, e, f, k, m;

		cout << "Введите переменную a: ";
		cin >> a;
		cout << endl;

		cout << "Введите переменную b: ";
		cin >> b;
		cout << endl;

		cout << "Введите переменную c: ";
		cin >> c;
		cout << endl;

		cout << "Введите переменную d: ";
		cin >> d;
		cout << endl;

		cout << "Введите переменную e: ";
		cin >> e;
		cout << endl;

		cout << "Введите переменную f: ";
		cin >> f;
		cout << endl;

		cout << "Введите переменную k: ";
		cin >> k;
		cout << endl;

		cout << "Введите переменную m: ";
		cin >> m;
		cout << endl;

		if (b == 0 || d == 0 || m == 0 || f == 0) {
			throw invalid_argument("Знаменатель не может быть равен нулю");
		}

		cout << "Результат выражения: " << Mult(Summ(Summ(Sokr(a, b), Sokr(c, d)), Sokr(k, m)), Sokr(e, f));
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}
