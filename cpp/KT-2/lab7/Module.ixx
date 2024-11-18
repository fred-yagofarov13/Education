export module Module;

import <iostream>;
import <fstream>;
import <vector>;

using namespace std;

export namespace Array31 {
	void cinNums(int N, double* nums, double* massiveNums) {
		cout << "Введите числа: ";

		for (int i = 0; i < N; i++)
		{
			cin >> *nums;
			*(massiveNums + i) = *nums;
		}
	}

	void cinNumsRand(int N, double* massiveNums) {
		cout << "Числа вводятся случайно: ";

		for (int i = 0; i < N; i++)
		{
			static unsigned int seed = 4541;
			seed = (8253729 * seed + 2396403);

			*(massiveNums + i) = seed % 32768;
			cout << *(massiveNums + i) << " ";
		}
		cout << endl;
	}

	void cinNumsFile(int N, double* massiveNums) {
		int nums, i = 0;

		cout << "Числа вводятся из файла: ";

		ifstream file;
		file.open("nums.txt");

		if (!file.is_open())
		{
			throw invalid_argument("Ошибка открытия файла!");
		}

		while (i < N)
		{
			file >> nums;
			*(massiveNums + i) = nums;
			cout << *(massiveNums + i) << " ";
			++i;
		}
		cout << endl;

		file.close();
	}

	void coutResult(int N, int count, double* massiveNums) {
		for (int i = N - 1; i > 0; i--)
		{
			if (*(massiveNums + i) > *(massiveNums + i - 1))
			{
				count++;
				cout << i + 1 << " ";
			}
		}

		cout << endl << "Количество элементов, которые больше своего левого соседа: " << count;
	}
}

export namespace Array110 {
	void cinNums(int N, int* nums, int* massiveNums) {
		cout << "Введите числа: ";
		for (int i = 0; i < N; i++)
		{
			cin >> *nums;

			*(massiveNums + i) = *nums;
		}
	}

	void cinNumsRand(int N, int* massiveNums) {
		cout << "Числа вводятся случайно: ";

		for (int i = 0; i < N; i++)
		{
			static unsigned int seed = 4541;
			seed = (8253729 * seed + 2396403);

			*(massiveNums + i) = seed % 32768;
			cout << *(massiveNums + i) << " ";
		}
		cout << endl;
	}

	void cinNumsFile(int N, int* massiveNums) {
		int nums, i = 0;

		cout << "Числа вводятся из файла: ";

		ifstream file;
		file.open("nums.txt");

		if (!file.is_open())
		{
			throw invalid_argument("Ошибка открытия файла!");
		}

		while (i < N)
		{
			file >> nums;
			*(massiveNums + i) = nums;
			cout << *(massiveNums + i) << " ";
			++i;
		}
		cout << endl;

		file.close();
	}

	void doubleEvenNums(int& N, int* massiveNums, int* massiveResult) {
		int countEvens = 0;

		for (int i = 0; i < N; i++)
		{
			if (*(massiveNums + i) % 2 == 0)
			{
				*(massiveResult + i + countEvens) = *(massiveNums + i);
				countEvens++;
			}
			*(massiveResult + i + countEvens) = *(massiveNums + i);
		}
		N += countEvens;
	}

	void coutResult(int N, int* massiveResult) {
		cout << "\nРезультат: ";

		for (int i = 0; i < N; i++)
		{
			cout << *(massiveResult + i) << " ";
		}
	}
}

export namespace TheMassiv16 {
	void cinNums(int N, int* nums, int* massiveNums) {
		cout << "Введите числа: ";
		for (int i = 0; i < N; i++)
		{
			cin >> *nums;

			*(massiveNums + i) = *nums;
		}
	}

	void cinNumsRand(int N, int* massiveNums) {
		cout << "Числа вводятся случайно: ";

		for (int i = 0; i < N; i++)
		{
			static unsigned int seed = 4541;
			seed = (8253729 * seed + 2396403);

			*(massiveNums + i) = seed % 32768;
			cout << *(massiveNums + i) << " ";
		}
		cout << endl;
	}

	void cinNumsFile(int N, int* massiveNums) {
		int nums, i = 0;

		cout << "Числа вводятся из файла: ";

		ifstream file;
		file.open("nums.txt");

		if (!file.is_open())
		{
			throw invalid_argument("Ошибка открытия файла!");
		}

		while (i < N)
		{
			file >> nums;
			*(massiveNums + i) = nums;
			cout << *(massiveNums + i) << " ";
			++i;
		}
		cout << endl;

		file.close();
	}

	void mainFunc(int N, int* massiveNums, int& max, int& kol) {
		max = *massiveNums;

		for (int i = 1; i < N; i++) {
			if (*(massiveNums + i) > max) {
				max = *(massiveNums + i);
				kol = 1;
			}
			else if (*(massiveNums + i) == max)
			{
				kol++;
			}
		}
	}

	void coutResult(int max, int kol) {
		cout << "\nРезультат: ";

		cout << "Максимальное значение: " << max << endl;

		cout << "Количество максимальных значений: " << kol << endl;
	}
}

//export namespace Task2 {
//	void cinNumsFile(int N, vector<int>& vectorNums, int k) {
//
//		vector<int> vectorResult;
//
//		int nums;
//
//		cout << "Числа вводятся из файла: ";
//
//		ifstream file;
//		file.open("nums.txt");
//
//		if (!file.is_open())
//		{
//			throw invalid_argument("Ошибка открытия файла!");
//		}
//
//		while (i < N)
//		{
//			file >> nums;
//			*(massiveNums + i) = vectorNums.push_back(nums);
//			cout << *(massiveNums + i) << " ";
//
//			if (nums <= k)
//			{
//				vectorResult.push_back(nums);
//			}
//
//			++i;
//		}
//		cout << endl;
//
//		cout << "Результат: ";
//
//		for (int n : vectorResult)
//			cout << nums;
//
//		file.close();
//	}
//}