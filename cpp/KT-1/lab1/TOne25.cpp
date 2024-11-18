#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Программа по заданному номеру выполняет определенные действия над целыми величинами X и Y(необходимо выбрать действие)" << endl << endl;

	try {
		int X, Y, operationNumber, result;

		cout << "Введите целые величины X и Y: ";

		cin >> X >> Y;

		cout << endl << "\n1 - Побитовое И(&)" << "\n2 - Побитовое ИЛИ(|)" << "\n3 - Побитовое исключающее ИЛИ(^)"
			<< "\n4 - сдвиг влево(<<)" << "\n5 - сдвиг вправо(>>)" << endl << endl;

		cin >> operationNumber;

		switch (operationNumber) {
		case 1:
			result = X & Y;  // Побитовое И
			cout << "Результат побитового И: " << result << endl;
			break;
		case 2:
			result = X | Y;  // Побитовое ИЛИ
			cout << "Результат побитового ИЛИ: " << result << endl;
			break;
		case 3:
			result = X ^ Y;  // Побитовое исключающее ИЛИ
			cout << "Результат исключающего ИЛИ: " << result << endl;
			break;
		case 4:
			result = X << Y;  // Сдвиг влево
			cout << "Результат сдвига влево X на Y бит: " << result << endl;
			break;
		case 5:
			result = X >> Y;  // Сдвиг вправо
			cout << "Результат сдвига вправо X на Y бит: " << result << endl;
			break;
		default:
			throw invalid_argument("ОШИБКА: Некорректно введенные данные!!");
			break;
		}

		cout << "Результат: " << result;
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}