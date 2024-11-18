import Module;

#include <iostream>

using namespace std;
using namespace TheMassiv16;

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "TheMassiv16. В массиве Х(N) найти значение максимального элемента массива (Max) и " << endl << "количество таких элементов(kol).Запрещается проходить по массиву более одного раза. " << endl << endl;

	try
	{
		int N, choose;
		int nums, max = INT16_MIN, kol = 1;

		cout << "Введите размер массива N: ";
		cin >> N;
		cout << endl;

		if (N <= 0) {
			throw invalid_argument("Размер массива должен быть положительным числом.");
		}

		int* massiveNums = new int[N];

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

		mainFunc(N, massiveNums, max, kol);

		coutResult(max, kol);

		delete[] massiveNums;
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}
