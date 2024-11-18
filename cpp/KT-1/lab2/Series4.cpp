#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int N;
	double sumNums = 0, multipleNums = 1;

	cout << "Введите количество чисел, которые хотите ввести: ";
	cin >> N;

	double massiveNums[INT16_MAX];

	cout << endl << "Введите все числа по порядку: ";

	for (int i = 0; i < N; i++) {
		cin >> massiveNums[i];
		sumNums += massiveNums[i];
		multipleNums *= massiveNums[i];
	}

	cout << "Сумма введенных чисел: " << sumNums << endl;
	cout << "Произведение введенных чисел: " << multipleNums << endl;

	return 0;
}