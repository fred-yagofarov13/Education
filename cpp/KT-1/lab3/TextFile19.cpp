#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	string path = "C:\\Users\\fred\\Desktop\\lab3\\testFiles\\d.txt";

	ofstream fout;
	fstream file;

	try
	{
		//Запись файла
		fout.open(path);

		if (!fout.is_open())
			throw runtime_error("Ошибка открытия файла!");

		cout << "Начинается процесс записи чисел в файл d.txt" << endl << "Введите количество чисел, которые хотите ввести:";

		int N, nums;

		cin >> N;

		if (N < 0) {
			throw invalid_argument("Некорректный ввод. Количество должно быть неотрицательным");
		}

		fout << N << endl;

		cout << "Вводите числа: ";

		for (int i = 0; i < N; i++) {
			cin >> nums;
			fout << nums << " ";
		}

		fout.close();

		//Чтение файла
		file.open(path);

		bool isNumsSameLength = true;
		string temp;

		if (!file.is_open())
			throw runtime_error("Ошибка открытия файла!");

		file >> N;

		if (N == 0) {
			cout << boolalpha << isNumsSameLength;
		}
		else {
			file >> nums;
			temp = to_string(nums);

			while ((file >> nums) && (isNumsSameLength = isNumsSameLength && (temp.length() == to_string(nums).length())));

			cout << boolalpha << isNumsSameLength;
		}

		file.close();
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}