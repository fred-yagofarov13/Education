#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "String54. Дана строка-предложение на русском языке. Подсчитать количество содержащихся в строке гласных букв." << endl << endl;
	const char vowels[] = { 'а', 'о', 'у', 'э', 'и', 'ы', 'е', 'ё', 'ю', 'я', 'А', 'О', 'У', 'Э', 'И', 'Ы', 'Е', 'Ё', 'Ю', 'Я', '\0'};
	char text[100];
	int countVowels = 0;

	cout << "Введите предложение: " << endl;
	cin.getline(text, 100);

	for (int i = 0; text[i] != '\0'; i++)
	{
		for (int j = 0; vowels[j] != '\0'; j++)
		{
			if (text[i] == vowels[j])
				countVowels++;
		}
	}

	cout << endl << "Результат: " << countVowels;

	return 0;
}