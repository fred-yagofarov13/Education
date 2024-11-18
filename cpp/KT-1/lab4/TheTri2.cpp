#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double Pifagor(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream fin;

	cout << "Программа определяет отрезок наибольшей длины" << endl << endl;

	try 
	{
		string path = "C:\\Users\\fred\\Desktop\\lab4\\textFiles\\b.otr";

		fin.open(path, ios::in);

		if (!fin.is_open()) 
		{
			throw invalid_argument("Ошибка открытия файла!");
			return 1;
		}

		int N;
		fin >> N;

		double x1, y1, x2, y2;
		double minLength = -1;

		for (int i = 0; i < N; ++i) 
		{
			fin >> x1 >> y1 >> x2 >> y2;

			cout << "Получен отрезок A(" << x1 << ", " << y1 << ") и (" << "B(" << x2 << ", " << y2 << ")" << endl;

			double length = Pifagor(x1, y1, x2, y2);

			cout << "Длина этого отрезка: " << length << endl << endl;

			if (minLength == -1 || length < minLength) 
			{
				minLength = length;
			}
		}

		fin.close();

		cout << "Наименьшая длина отрезка: " << minLength << endl;
	}
	catch (exception& e) 
	{
		cout << e.what();
	}

	return 0;
}
