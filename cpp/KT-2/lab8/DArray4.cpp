import Module;

#include <iostream>
#include <ctime>

using namespace std;
using namespace DArray4;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	cout << "DArray4. Задана квадратная матрица. Получить транспонированную матрицу и проверить, является ли исходная матрица симметричной относительно главной диагонали" << endl << endl;

	int N, choose;
	int nums, ** matrixNums;

	initMatrix(matrixNums, N);

	cout << "\nВыберите, как вы хотите ввести числа: "
		<< "\n1 - Ввод из консоли"
		<< "\n2 - Ввод случайных чисел"
		<< "\n3 - Ввод чисел из файла" << endl;

	cin >> choose;

	switch (choose) {
	case 1:
		cinNums(N, &nums, matrixNums);
		break;
	case 2:
		cinNumsRand(N, matrixNums);
		break;
	case 3:
		cinNumsFile(N, matrixNums);
		break;
	default:
		cout << "Вводите только числа 1, 2 или 3";
	}

	coutResult(N, matrixNums);

	delMatrix(matrixNums, N);

	return 0;
}