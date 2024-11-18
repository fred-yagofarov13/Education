#include <iostream>

using namespace std;

int DigitCount(int K) {
	int countCiphers = 0;

	while (K != 0)
	{
		K /= 10;
		countCiphers++;
	}

	return countCiphers;
}

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Программа вычисляет количество цифр в введённом числе" << endl << endl;

	try 
	{
		int K;

		cout << "Введите 5 целых положительных чисел, чтобы узнать количество цифр в нём " << endl;

		for (int i = 1; i <= 5; i++) 
		{
			cout << "Введите " << i <<" число" << endl;
			cin >> K;

			if (K <= 0) 
			{
				throw invalid_argument("Некорректно введено число");
			}

			int result = DigitCount(K);

			cout << "Количество цифр: " << result << endl;
		}
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}