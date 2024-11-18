#include <iostream>

using namespace std;

int cinMass() {
	double objectMass;

	cout << "Введите вещественное число: ";
	cin >> objectMass;
	cout << endl << "Результат: ";

	return objectMass;
}

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Программа находит массу тела, переведя в килограммы из другой единицы измерения" << endl << endl;
	
	double objectMassResult;
	int massNum;
	cout << "Для начала, выберите в какой единице измерения хотите ввести массу тела" << endl;
	cout << "Для выбора единицы измерения, введите цифру [1, 5]" << endl;
	cout << "\n1 - Килограмм" << "\n2 - Милиграмм" << "\n3 - Грамм" << "\n4 - Тонна" << "\n5 - Центнер" << endl << endl;

	try {
		cin >> massNum;

		if (massNum < 1 || massNum > 5) {
			throw invalid_argument("Неверный выбор единицы измерения");
		}

		switch (massNum) {
		case 1:
			objectMassResult = cinMass();
			cout << objectMassResult << "кг";
			break;
		case 2:
			objectMassResult = cinMass();
			objectMassResult /= 1000000;
			cout << objectMassResult << "кг";
			break;
		case 3:
			objectMassResult = cinMass();
			objectMassResult /= 1000;
			cout << objectMassResult << "кг";
			break;
		case 4:
			objectMassResult = cinMass();
			objectMassResult *= 1000;
			cout << objectMassResult << "кг";
			break;
		case 5:
			objectMassResult = cinMass();
			objectMassResult *= 100;
			cout << objectMassResult << "кг";
			break;
		}
	}
	catch (exception& e) {
		cout << "Ошибка: " << e.what() << endl;
		cout << "Вацок, выбирай цифры [1, 5]" << endl;
	}

	return 0;
}