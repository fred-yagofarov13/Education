#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	string path = "C:\\Users\\fred\\Desktop\\lab3\\testFiles\\numsTF15_g.txt";

	ofstream file;

	try
	{
		//Запись файла
		file.open(path, ios::out);

		if (!file.is_open())
			throw runtime_error("Ошибка открытия файла!");

		cout << "Начинается процесс записи чисел в файл numsTF2_g.txt" << endl << "Введите номера фибоначчи N1, N2, чтобы вывести числа в этом диапазоне:";

		int N1, N2;

		cin >> N1 >> N2;

		if (N1 < 0 && N2 < 0) {
			throw invalid_argument("Некорректный ввод. Номер должнен быть неотрицательным");
		}

		int F0 = 0, F1 = 1;

		if (N1 == 0) {
			file << F0 << endl;
			cout << F0 << endl;
			N1++;
		}

		if (N1 <= 1) {
			file << F1 << endl;
			cout << F1 << endl;
			N1++;
		}

		int currentFib = F1, previousFib = F0;

		for (int i = 2; i <= N2; i++) {
			int newFib = previousFib + currentFib;
			previousFib = currentFib;
			currentFib = newFib;

			if (i >= N1) {
				cout << currentFib << endl;
				file << currentFib << endl;
			}
		}

		file.close();
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}