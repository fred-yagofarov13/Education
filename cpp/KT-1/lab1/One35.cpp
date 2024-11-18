#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Программа определяет, отличаются ли все цифры у натурального числа (10000 ≤ х ≤ 99999)" << endl << endl;

	try {
        int x;
        cout << "Введите натуральное число: ";
        cin >> x;

        // Извлекаем цифры числа
        int d1 = x / 10000;         // Первая цифра
        int d2 = (x / 1000) % 10;   // Вторая цифра
        int d3 = (x / 100) % 10;    // Третья цифра
        int d4 = (x / 10) % 10;     // Четвертая цифра
        int d5 = x % 10;            // Пятая цифра

        // Логическая переменная: все цифры различны
        bool allUnique = (d1 != d2 && d1 != d3 && d1 != d4 && d1 != d5 &&
            d2 != d3 && d2 != d4 && d2 != d5 &&
            d3 != d4 && d3 != d5 &&
            d4 != d5);

        // Выводим результат
        cout << boolalpha << allUnique << endl;
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}