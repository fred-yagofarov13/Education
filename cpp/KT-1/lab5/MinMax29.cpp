#include <iostream>
#include <cmath>

using namespace std;

int MinNumsCount(int N, int min, int count) {
	int num, maxCount = 0;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (N != 1) {
			if (num < min) {
				min = num;
				count = 1;
				maxCount = 1;
			}
			else if (num == min) {
				++count;
				if (maxCount < count)
					maxCount = count;
			}
			else {
				count = 0;
			}
		}
	}
	return maxCount;
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Программа для подсчета максимального количества минимальных чисел, идущих подряд" << endl << endl;

	try
	{
		int N,
			min = INT16_MAX,
			count = 0;

		cout << "Введите количество чисел, которые собираетесь ввести: ";

		cin >> N;

		if (N > 0) {
			cout << "Введите числа: " << endl;
			cout << "Количество: " << MinNumsCount(N, min, count);
		}
		else {
			throw invalid_argument("Некорректный ввод. Количество чисел должно быть больше нуля");
		}

	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}
