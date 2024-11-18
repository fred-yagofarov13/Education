#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	string path = "C:\\Users\\fred\\Desktop\\lab3\\testFiles\\numsTF15_g.txt";
	string pathToG = "C:\\Users\\fred\\Desktop\\lab3\\testFiles\\g.txt";

	ofstream fout;
	ofstream gout;
	ifstream fin;

	try
	{
		//Запись файла
		fout.open(path, ios::out);

		if (!fout.is_open())
			throw "Ошибка открытия файла!";

		cout << "Начинается процесс записи чисел в файл numsTF15_g.txt" << endl << "Введите разряд:";

		int N, nums, countEvenNums = 0;

		cin >> N;

		if (N < 0) {
			throw invalid_argument("Некорректный ввод. Количество должно быть неотрицательным");
		}

		cout << endl;

		fout.close();

		cout << endl << "Числа записаны в файл." << endl << endl;
		cout << "Запускаю работу алгоритма" << endl << "Считывание файла..." << endl << endl;

		//Чтение файла
		fin.open(path, ios::in);
		gout.open(pathToG, ios::out);

		if (!fin.is_open())
			throw "Ошибка открытия файла!";

		if (!gout.is_open())
			throw "Ошибка открытия файла!";

		cout << "Результат" << endl;

		int countPalindromes = 0;

		if (N > 1 && N < 7)
		{
			for (int i = pow(10, N - 1); i < pow(10, N); i++) {

				int reversed = 0, temp = i;
				while (temp != 0) {
					int digit = temp % 10;
					reversed = reversed * 10 + digit;
					temp /= 10;
				}

				if (i == reversed)
					countPalindromes++;

			}
		}
		else
			throw invalid_argument("Некорректный разряд в файле. Разряд должен быть от 2 до 6 включительно.");

		cout << "Количество палиндромов: " << countPalindromes << endl;

		fin.close();
		gout.close();
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}