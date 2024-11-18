#include <iostream>
#include <fstream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	string path = "C:\\Users\\fred\\Desktop\\lab3\\testFiles\\numsTF6_b.txt";

	ofstream fout;
	ifstream fin;

	try
	{
		//Запись файла
		fout.open(path, ios::out);

		if (!fout.is_open())
			throw "Ошибка открытия файла!";

		cout << "Начинается процесс записи чисел в файл numsTF6_b.txt" << endl << "Введите сколько чисел вы желаете ввести:";

		int N, nums, countEvenNums = 0;

		cin >> N;

		cout << endl;

		for (int i = 0; i < N; i++) {
			cin >> nums;
			fout << nums << "\n";
		}

		fout.close();

		cout << endl << "Числа записаны в файл." << endl << endl;
		cout << "Запускаю работу алгоритма" << endl << "Считывание файла..." << endl << endl;

		//Чтение файла
		fin.open(path, ios::in);

		if (!fin.is_open())
			throw "Ошибка открытия файла!";

		cout << "Результат" << endl;

		while (fin >> nums)
		{
			if (nums >= 100 && nums <= 999 && nums % 2 == 0)
				countEvenNums++;
		}

		cout << "Количество четных чисел в диапазоне [100; 999]: " << countEvenNums << endl;

		fin.close();
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}