#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int N, lastCipher;
	bool numTwo = false;

	cout << "Введите целое число N > 0: ";
	cin >> N;

	while (N > 0) {
		if (numTwo) break;
		lastCipher = N % 10;
		if (lastCipher == 2) numTwo = true;
		N /= 10;
	}

	cout << "Есть ли цифра 2 в введенном числе: " << boolalpha << numTwo;
	return 0;
}