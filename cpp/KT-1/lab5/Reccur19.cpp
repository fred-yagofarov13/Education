#include <iostream>
#include <cmath>

using namespace std;

int ReccurSum(int N, double& sum) {
	return (N != 0 ? ReccurSum(N - 1, sum += 1 / pow(2, N)) : 0);
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Программа вычисляет сумму ряда с N первых членов(N < 20)" << endl << endl;

	try
	{
		int N;
		double sum = 0;

		cout << "Введите количество первых членов ряда: ";

		cin >> N;

		cout << endl;

		if (N >= 0 || N  < 20) {
			ReccurSum(N, sum);
			cout << "Сумма ряда: " << sum;
		}
		else {
			throw invalid_argument("Некорректный ввод");
		}
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}
