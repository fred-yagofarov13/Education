/*Sort2. Дано натуральное N и массив целых чисел размерности N.
Отсортировать данный массив по возрастанию методом простых обменов.
В процессе сортировки отсортированную часть накапливать в конце массива.
Вывести содержимое массива после каждой итерации сортировки.
Одной итерацией сортировки считать такое действие, в результате которого
один элемент массива гарантированно встает на правильное место в отсортированном массиве.
При выводе массива отсортированную часть отделать от неотсортированной с помощью символа |.
Протокол сортировки выводить в текстовый файл*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int N;
	ofstream fout("output.txt");


	cout << "Введите размер массива: ";
	cin >> N;

	int* massNums = new int[N];

	cout << "Введите элементы массива: ";

	for (int i = 0; i < N; i++) {
		cin >> massNums[i];
	}

	if (fout.is_open()) {
		int temp;
		int count = 0;

		// Сортировка массива методом простых обменов (пузырьковая сортировка)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (massNums[j] > massNums[j + 1]) {
					temp = massNums[j];
					massNums[j] = massNums[j + 1];
					massNums[j + 1] = temp;
				}
			}

			fout << "Итерация " << i + 1 << ": ";
			for (int k = 0; k < N; k++) {
				fout << massNums[k] << " ";
				if (k == count) {
					fout << "| ";
				}
			}
			fout << endl;
			count++;
		}

		fout << "Отсортированный массив: ";
		for (int i = 0; i < N; i++) {
			fout << massNums[i] << " ";

			if (i == count) {
				fout << "| ";
			}
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	delete[] massNums;
	fout.close();

	cout << "Данные успешно записаны в файл output.txt" << endl;

	return 0;
}