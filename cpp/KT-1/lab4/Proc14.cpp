#include <iostream>

using namespace std;

int ShiftRight3(int& A, int& B, int& C) {
	int temp = A;

	A = B;
	B = C;
	C = temp;

	return 0;
}

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Программа выполняет правый циклический сдвиг набора чисел A, B, C (A переходит в B, значение B — в C, значение C — в A )" << endl << endl;

	try 
	{
		int A, B, C;

		cout << "Введите набор: " << endl;

		for (int i = 1; i <= 2; i++) 
		{
			cout << "Введите " << i <<"-ый набор из трёх чисел" << endl;
			cin >> A >> B >> C;

			if (A <= 0 || B <= 0 || C <= 0) 
			{
				throw invalid_argument("Некорректно введено число");
			}

			ShiftRight3(A, B, C);

			cout << "Результат сдвига: " << A << " " << B << " " << C << endl;
		}
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}