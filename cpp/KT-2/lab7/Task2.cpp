#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "2. Считать из текстового файла целые числа и занести их в вектор. Вывести вектор на экран.Удалить из вектора все элементы, превышающие значение k и вывести вектор на экран.  " << endl << endl;

	try
	{
		int N, k, i = 0;

		cout << "Введите размер массива N: ";
		cin >> N;
		cout << endl;

		cout << "Введите k: ";
		cin >> k;
		cout << endl;

		if (N <= 0) {
			throw invalid_argument("Размер массива должен быть положительным числом.");
		}

		vector<int> vectorNums;

		int nums;

		cout << "Числа вводятся из файла: ";

		ifstream file;
		file.open("nums.txt");

		if (!file.is_open())
		{
			throw invalid_argument("Ошибка открытия файла!");
		}

		while (file >> nums && i < N)
		{
			vectorNums.push_back(nums);
			cout << vectorNums[i] << " ";
			++i;
		}

		for (i = 0; i < N; ) {
			if (vectorNums[i] > k) {
				vectorNums.at(i);
				N--;
			}
			else
				i++;
		}
		cout << endl;

		cout << "Результат: ";

		for (i = 0; i < N; i++) {
			cout << vectorNums[i] << " ";
		}

		file.close();

	}
	catch (exception& e)
	{
		cout << e.what();
	}

	return 0;
}
