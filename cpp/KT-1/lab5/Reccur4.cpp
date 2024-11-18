#include <iostream>
#include <cmath>

using namespace std;

int MaxCipher(int N, int maxCipher) {
	return (N != 0 ? MaxCipher(N / 10, maxCipher < N % 10 ? N % 10 : maxCipher) : maxCipher);
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Программа определяет максимальную цифру в числе N" << endl << endl;

	try 
	{
		int N, maxCipher = -1;

		cin >> N;

		if (N >= 0) {
			cout << MaxCipher(N, maxCipher);
		}
		else {
			throw invalid_argument("Некорректный ввод");
		}
	}
	catch (exception& e) 
	{
		cout << e.what();
	}

	return 0;
}
