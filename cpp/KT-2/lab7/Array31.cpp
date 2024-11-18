import Module;

#include <iostream>

using namespace std;
using namespace Array31;

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Array31.Дан массив размера N.Найти номера тех элементов массива, которые больше" << endl << "своего левого соседа, и количество таких элементов.Найденные номера выводить в порядке их убывания. " << endl << endl;

	try
	{
		int N, count = 0, choose;
		double nums;

		cout << "Введите размер массива N: ";
		cin >> N;
		cout << endl;

		if (N <= 0) {
			throw invalid_argument("Размер массива должен быть положительным числом.");
		}

		double* massiveNums = new double[N];

		cout << "\nВыберите, как вы хотите ввести числа: "
			<< "\n1 - Ввод из консоли"
			<< "\n2 - Ввод случайных чисел"
			<< "\n3 - Ввод чисел из файла" << endl;

		cin >> choose;

		switch (choose) {
		case 1: 
			cinNums(N, &nums, massiveNums);
			break;
		case 2:
			cinNumsRand(N, massiveNums);
			break;
		case 3:
			cinNumsFile(N, massiveNums);
			break;
		default:
			throw invalid_argument("Вводите только числа 1, 2 или 3");
		}

		coutResult(N, count, massiveNums);

		delete[] massiveNums;
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}
