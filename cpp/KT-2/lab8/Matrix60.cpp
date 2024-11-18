import Module;

#include <iostream>
#include <ctime>

using namespace std;
using namespace Matrix60;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	cout << "\nMatrix60. Дана матрица размера M × N. Зеркально отразить ее элементы относительно" << "вертикальной оси симметрии матрицы(при этом поменяются местами столбцы с номерами 1 и N, 2 и N − 1 и т.д.)." << endl << endl;

	int N, M, choose;
	int nums, ** matrixNums;

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

	coutResult(N, M, matrixNums);

	delMatrix(matrixNums, N);

	return 0;
}