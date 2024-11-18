#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int N;
	bool numLower = true;

	cout << "Введите целое число N >= 0 и N <= 99999999: ";
	cin >> N;

	if (N < 0 || N > 99999999) {
		cout << "Введены некорректные данные!";
	}
	else {
		while (N >= 10) {
			if (!numLower) break;
			if ((N % 10) <= (N / 10 % 10)) numLower = false;
			N /= 10;
		}
	}
	
	cout << "Есть убывающие ли цифры справа налево: " << boolalpha << numLower;
	return 0;
}