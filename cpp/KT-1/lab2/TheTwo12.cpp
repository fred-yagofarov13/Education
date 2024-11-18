#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Введите n и k для нахождения суммы порядка выражения n^k: ";

	int n, k, m;
	double result = 0;

	cin >> n >> k;

	if (n <= 0 || k <= 0) return result = 0;

	m = n;

	for (int i = n; i > 0; i--)
	{
		for (int j = k - 1; j > 0; j--)
		{
			m *= n;
		}
		result += m;
		n--;
		m = n;
	}

	cout << endl << "Сумма порядка: " << setprecision(15) << result;


	return 0;
}