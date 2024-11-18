#include <iostream>
#include <iomanip>

using namespace std;

string multipleStars(string lineStars, int count) {
	string output = "";
	while (count--) {
		output += lineStars;
	}
	return output;
}

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Введите набор из 20 целых чисел и мы выведем набор строк из звёздочек, длиною в введенные числа: ";

	int massiveNums[INT16_MAX];
	string lineStars = "*";

	cout << endl << "Введите все числа по порядку: ";

	for (int i = 0; i < 20; i++) {
		massiveNums[i] = rand() % 20 + 1;
		if (massiveNums[i] < 0) {
			cout << "Некорректные введенные данные!";
			break;
		}
		cout << "Строка с длиною " << massiveNums[i] << ": "
			<< multipleStars(lineStars, massiveNums[i]) << endl;
		lineStars = "*";
	}

	return 0;
}