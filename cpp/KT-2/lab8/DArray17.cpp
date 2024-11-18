import Module;

#include <iostream>
#include <ctime>

using namespace std;
using namespace DArray17;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	cout << "DArray17. Проверить, является ли матрица A размером nxn"
		<< "\nдиагональной(все элементы, кроме главной диагонали, нули и матрица при этом не единичная);"
		<< "\nединичной(все элементы нули, на главной диагонали только единицы);"
		<< "\nили нулевой(все элементы нули). "
		<< "\nФормат ответа: 1 - диагональная, 2 - единичная, 3 - нулевая" << endl << endl;

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