export module Module;

import <iostream>;
import <fstream>;
import <iomanip>;

using namespace std;

export namespace Matrix30 {
	void initMatrix(int**& a, int& n, int& m)
	{
		int i;

		cout << "Введите размер строк N: ";
		cin >> n;
		cout << endl;

		if (n <= 0) {
			cout << "Размер массива должен быть положительным числом.";
		}

		cout << "Введите размер столбцов M: ";
		cin >> m;
		cout << endl;

		if (m <= 0) {
			cout << "Размер массива должен быть положительным числом.";
		}

		a = new int* [n];//задаем массив из n элементов, каждый из которых является адресом строки
		for (i = 0;i < n;i++)
			a[i] = new int[m]; //выделяем память под каждую строку массива
	}

	void printMatrix(int** a, int n, int m)
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				cout << setw(4) << a[i][j];
			cout << endl;
		}
	}

	void delMatrix(int** a, int n)
	{
		for (int i = 0;i < n;i++)//освобождаем память для каждой строки
			delete[] a[i];
		delete[]a;//освобождаем память для массива указателей на строки
	}

	void cinNums(int N, int M, int* nums, int** matrixNums) {
		cout << "Введите числа: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> *nums;
				matrixNums[i][j] = *nums;
			}
		}
		printMatrix(matrixNums, N, M);
	}

	void cinNumsRand(int N, int M, int** matrixNums) {
		cout << "Числа вводятся случайно: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				matrixNums[i][j] = rand() % 10;
			}
		}
		printMatrix(matrixNums, N, M);
	}

	void cinNumsFile(int N, int M, int** matrixNums) {
		int num;
		int i = 0, j = 0;

		cout << "Числа вводятся из файла: " << endl;

		ifstream file("nums.txt");

		if (!file.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		while (i < N && file >> num)
		{
			matrixNums[i][j] = num;
			j++;
			if (j == M)
			{
				j = 0;
				i++;
			}
		}

		if (i < N) {
			cout << "Предупреждение: В файле меньше данных, чем требуется для заполнения матрицы." << endl;
		}

		printMatrix(matrixNums, N, M);

		file.close();
	}

	void coutResult(int N, int M, int kol, double arifmSum, int** matrixNums) {
		cout << endl << "Результат: " << endl;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arifmSum += matrixNums[j][i];
			}
			for (int j = 0; j < N; j++)
			{
				if (arifmSum / N < matrixNums[j][i])
				{
					kol++;
				}
			}

			cout << "В столбце " << i + 1 << " количество чисел, больших среднего арифметического всех элементов этого столбца(" << arifmSum / N << "): " << kol << endl;

			arifmSum = kol = 0;
		}
	}
}

export namespace Matrix60 {
	void initMatrix(int**& a, int& n, int& m)
	{
		int i;

		cout << "Введите размер массива N: ";
		cin >> n;
		cout << endl;

		if (n <= 0) {
			cout << "Размер массива должен быть положительным числом.";
		}

		cout << "Введите размер массива M: ";
		cin >> m;
		cout << endl;

		if (m <= 0) {
			cout << "Размер массива должен быть положительным числом.";
		}

		a = new int* [n];//задаем массив из n элементов, каждый из которых является адресом строки
		for (i = 0;i < n;i++)
			a[i] = new int[m]; //выделяем память под каждую строку массива
	}

	void printMatrix(int** a, int n, int m)
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				cout << setw(4) << a[i][j];
			cout << endl;
		}
	}

	void delMatrix(int** a, int n)
	{
		for (int i = 0;i < n;i++)//освобождаем память для каждой строки
			delete[] a[i];
		delete[]a;//освобождаем память для массива указателей на строки
	}

	void cinNums(int N, int M, int* nums, int** matrixNums) {
		cout << "Введите числа: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> *nums;
				matrixNums[i][j] = *nums;
			}
		}
		printMatrix(matrixNums, N, M);
	}

	void cinNumsRand(int N, int M, int** matrixNums) {
		cout << "Числа вводятся случайно: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				matrixNums[i][j] = rand() % 10;
			}
		}
		printMatrix(matrixNums, N, M);
	}

	void cinNumsFile(int N, int M, int** matrixNums) {
		int num;
		int i = 0, j = 0;

		cout << "Числа вводятся из файла: " << endl;

		ifstream file("nums.txt");

		if (!file.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		while (i < N && file >> num)
		{
			matrixNums[i][j] = num;
			j++;
			if (j == M)
			{
				j = 0;
				i++;
			}
		}

		if (i < N) {
			cout << "Предупреждение: В файле меньше данных, чем требуется для заполнения матрицы." << endl;
		}

		printMatrix(matrixNums, N, M);

		file.close();
	}

	void coutResult(int N, int M, int** matrixNums) {
		cout << endl << "Результат: " << endl;

		for (int i = 0; i < N; i++)
		{
			int start = 0;
			int end = M - 1;

			while (start < end)
			{
				int temp = matrixNums[i][start];
				matrixNums[i][start] = matrixNums[i][end];
				matrixNums[i][end] = temp;

				start++;
				end--;
			}
		}

		printMatrix(matrixNums, N, M);
	}
}

export namespace DArray4 {
	void initMatrix(int**& a, int& n)
	{
		int i;

		cout << "Введите размер массива N x N: ";
		cin >> n;
		cout << endl;

		if (n <= 0) {
			cout << "Размер массива должен быть положительным числом.";
		}

		a = new int* [n];//задаем массив из n элементов, каждый из которых является адресом строки
		for (i = 0;i < n;i++)
			a[i] = new int[n]; //выделяем память под каждую строку массива
	}

	void printMatrix(int** a, int n)
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				cout << setw(4) << a[i][j];
			cout << endl;
		}

	}

	void delMatrix(int** a, int n)
	{
		for (int i = 0;i < n;i++)//освобождаем память для каждой строки
			delete[] a[i];
		delete[]a;//освобождаем память для массива указателей на строки
	}

	void cinNums(int N, int* nums, int** matrixNums) {
		cout << "Введите числа: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> *nums;
				matrixNums[i][j] = *nums;
			}
		}
		printMatrix(matrixNums, N);
	}

	void cinNumsRand(int N, int** matrixNums) {
		cout << "Числа вводятся случайно: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrixNums[i][j] = rand() % 10;
			}
		}
		printMatrix(matrixNums, N);
	}

	void cinNumsFile(int N, int** matrixNums) {
		int num;
		int i = 0, j = 0;

		cout << "Числа вводятся из файла: " << endl;

		ifstream file("nums.txt");

		if (!file.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		while (i < N && file >> num)
		{
			matrixNums[i][j] = num;
			j++;
			if (j == N)
			{
				j = 0;
				i++;
			}
		}

		if (i < N) {
			cout << "Предупреждение: В файле меньше данных, чем требуется для заполнения матрицы." << endl;
		}

		printMatrix(matrixNums, N);

		file.close();
	}

	void coutResult(int N, int** matrixNums) {
		cout << endl << "Результат: ";

		int temp;
		bool flag = true;

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				temp = matrixNums[i][j];
				matrixNums[i][j] = matrixNums[j][i];
				matrixNums[j][i] = temp;

				if (matrixNums[i][j] != matrixNums[j][i] && flag)
					flag = false;
			}
		}

		if (flag)
			cout << "Исходная и транспонированная матрицы симметричны." << endl;
		else
			cout << "Исходная и транспонированная матрицы не симметричны." << endl;
		printMatrix(matrixNums, N);
	}
}

export namespace DArray17 {
	void initMatrix(int**& a, int& n)
	{
		int i;

		cout << "Введите размер массива N x N: ";
		cin >> n;
		cout << endl;

		if (n <= 0) {
			cout << "Размер массива должен быть положительным числом.";
		}

		a = new int* [n];//задаем массив из n элементов, каждый из которых является адресом строки
		for (i = 0;i < n;i++)
			a[i] = new int[n]; //выделяем память под каждую строку массива
	}

	void printMatrix(int** a, int n)
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				cout << setw(4) << a[i][j];
			cout << endl;
		}

	}

	void delMatrix(int** a, int n)
	{
		for (int i = 0;i < n;i++)//освобождаем память для каждой строки
			delete[] a[i];
		delete[]a;//освобождаем память для массива указателей на строки
	}

	void cinNums(int N, int* nums, int** matrixNums) {
		cout << "Введите числа: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> *nums;
				matrixNums[i][j] = *nums;
			}
		}
		printMatrix(matrixNums, N);
	}

	void cinNumsRand(int N, int** matrixNums) {
		cout << "Числа вводятся случайно: " << endl;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrixNums[i][j] = rand() % 2;
			}
		}
		printMatrix(matrixNums, N);
	}

	void cinNumsFile(int N, int** matrixNums) {
		int num;
		int i = 0, j = 0;

		cout << "Числа вводятся из файла: " << endl;

		ifstream file("nums.txt");

		if (!file.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		while (i < N && file >> num)
		{
			matrixNums[i][j] = num;
			j++;
			if (j == N)
			{
				j = 0;
				i++;
			}
		}

		if (i < N) {
			cout << "Предупреждение: В файле меньше данных, чем требуется для заполнения матрицы." << endl;
		}

		printMatrix(matrixNums, N);

		file.close();
	}

	void coutResult(int N, int** matrixNums) {
		cout << endl << "Результат: ";

		int temp;
		bool flagForDiag = true;
		bool flagForUnit = true;
		bool flagForZero = true;

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				temp = matrixNums[i][j];
				matrixNums[i][j] = matrixNums[j][i];
				matrixNums[j][i] = temp;

				if (matrixNums[i][j] == 0 && matrixNums[i][j] == matrixNums[j][i] && flagForDiag)
					flagForDiag = true;
				else 
					flagForDiag = false;
				if (matrixNums[i][j] == 0 && matrixNums[i][j] == matrixNums[j][i] && matrixNums[i][i] == 1 && flagForUnit)
					flagForUnit = true;
				else
					flagForUnit = false;
				if (matrixNums[i][j] == 0 && matrixNums[i][j] == matrixNums[j][i] && matrixNums[i][i] == 0 && flagForZero)
					flagForZero = true;
				else
					flagForZero = false;
			}
		}
		
		if (flagForZero)
			cout << '3';
		else if (flagForUnit)
			cout << '2';
		else if (flagForDiag)
			cout << '1';
		
		else
		{
			cout << "Матрица не соответствует ни одному условию";
		}
	}
}