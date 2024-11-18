import Module;

#include <iostream>

using namespace std;
using namespace Array110;

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Array110. Дан целочисленный массив размера N. Продублировать в нем все четные числа." << endl << endl;

	try
	{
		int N, count = 0, nums, choose;

		cout << "Введите размер массива N: ";
		cin >> N;
		cout << endl;

		if (N <= 0) {
			throw invalid_argument("Размер массива должен быть положительным числом.");
		}

		int* massiveNums = new int[N];
		int* massiveResult = new int[N + N];

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

		doubleEvenNums(N, massiveNums, massiveResult);

		coutResult(N, massiveResult);

		delete[] massiveNums, massiveResult;
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}
