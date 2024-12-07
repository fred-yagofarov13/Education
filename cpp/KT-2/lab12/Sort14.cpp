/*Sort14. Дано целое число X и текстовый файл.
В файле записан набор целых чисел, расположенных в неубывающем порядке.
С помощью метода бинарного поиска определить индекс самого левого вхождения числа X в исходный набор.
Нумерация элементов начинается с нуля. Если элемент не найден, вывести -1. Чисел в исходном наборе не более 200*/
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int X;

	ifstream fin("input.txt");
	ofstream fout1("input.txt");
	ofstream fout2("output.txt");

	cout << "Введите число X: ";
	cin >> X;

	int* massNums = new int[200];
	int count = 0;

	if (fout1.is_open()) {

		fout1 << X << endl;

		while (!fin.eof()) {
			if (count == 200) {
				break;
			}

			if (count == 0) {
				massNums[count] = rand() % 5;
				fout1 << massNums[count] << " ";
			}
			else {
				massNums[count] = massNums[count - 1] + rand() % 5;
				fout1 << massNums[count] << " ";
			}
			count++;
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	if (fin.is_open()) {
		// Бинарный поиск самого левого вхождения числа X в исходный набор чисел
		int left = 0;
		int right = count - 1;
		int middle;
		int index = -1;
		while (left <= right) {
			middle = (left + right) / 2;
			if (massNums[middle] == X) {
				index = middle;
				right = middle - 1;
			}
			else if (massNums[middle] < X) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		fout2 << index;
		delete[] massNums;
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	fin.close();
	fout1.close();
	fout2.close();

	cout << "Данные успешно записаны в файлы input.txt и output.txt" << endl;

	return 0;
}