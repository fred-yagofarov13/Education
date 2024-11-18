import Module;

#include <iostream>
#include <ctime>

using namespace std;
using namespace Matrix30;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	cout << "Matrix30. Дана матрица размера M × N. В каждом ее столбце найти количество элементов, больших среднего арифметического всех элементов этого столбца." << endl << endl;

	int N, M, choose;
	int nums, ** matrixNums, kol = 0;
	double arifmSum = 0;

	initMatrix(matrixNums, N, M);

	cout << "\nВыберите, как вы хотите ввести числа: "
		<< "\n1 - Ввод из консоли"
		<< "\n2 - Ввод случайных чисел"
		<< "\n3 - Ввод чисел из файла" << endl;

	cin >> choose;

	switch (choose) {
	case 1:
		cinNums(N, M, &nums, matrixNums);
		break;
	case 2:
		cinNumsRand(N, M, matrixNums);
		break;
	case 3:
		cinNumsFile(N, M, matrixNums);
		break;
	default:
		cout << "Вводите только числа 1, 2 или 3";
	}

	coutResult(N, M, kol, arifmSum, matrixNums);

	delMatrix(matrixNums, N);

	return 0;
}