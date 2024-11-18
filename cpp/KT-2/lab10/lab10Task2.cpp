#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void correctInput(char* buffer, string& text) {
	if (buffer == nullptr || strlen(buffer) == 0) {
		throw invalid_argument("������ ����� ��� �����������.");
	}

	for (size_t i = 0; buffer[i] != '\0'; i++) {
		if (int(buffer[i]) + 256 == 168 || int(buffer[i]) + 256 == 184 || (int(buffer[i]) + 256 >= 192 && int(buffer[i]) + 256 <= 256)) {
			text += buffer[i];
		}
		else {
			throw invalid_argument("������������ ���� �����.");
		}
	}
}

void consoleInput(string& text) {
	cout << "\n��� ��������������� ����� �����, ��������� ������� ������������� ����� �������� ��������."
		<< "\n������� �����: ";

	size_t bufferSize = 20;
	char* buffer = new char[bufferSize];

	//cin.ignore(INT16_MAX, '\n');
	cin.getline(buffer, bufferSize);

	if (strlen(buffer) == 0) {
		delete[] buffer;
		throw invalid_argument("���� ����.");
	}

	correctInput(buffer, text);

	delete[] buffer;
}

void randomGeneration(string firstWord, int& countGen) {
	const int length = firstWord.length();
	string generatedWord = "",
		usedIndex = "";
	int curIndex;
	cout << "\n��������������� �����: \n";

	while (firstWord != generatedWord)
	{
		generatedWord = "";

		for (size_t i = 0; i < length; i++)
		{
			curIndex = rand() % length;
			usedIndex += to_string(curIndex);

			while (usedIndex.find(curIndex) != -1)
				curIndex = rand() % length;

			generatedWord += firstWord[curIndex];
		}

		countGen++;

		cout << "��������� ����� " << countGen << ": " << generatedWord << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));

	cout << "\nlab10Task2. ������ � ���������� ����� �����. ��������� ��������� ��������� �����,"
		<< "\n����������� ����� ����� ����� � ��������� �������. ������ ��� �� ��� ���,"
		<< "\n���� ���������� ����� �� ������� � ��������� ������. �������� ����� ����� ������"
		<< "\n������������ � ��������� ����� ���������� ���������� ����(�� ������ ���������).";

	try
	{
		string text = "";
		int countGen = 0;

		consoleInput(text);

		cout << "\n�������� �����: " << text << endl;

		randomGeneration(text, countGen);

		cout << "\n���������� ���������: ";
		cout << countGen << endl;
		cout << endl;

		return 0;
	}
	catch (exception& e)
	{
		cout << "������: " << e.what();
	}
}
