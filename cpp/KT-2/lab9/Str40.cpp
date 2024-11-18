#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Str40. Из заданной символьной строки, выбрать те символы, которые встречаются в ней только один раз, в том порядке, "
		<< "в котором они встречаются в тексте, считая знаки препинания." << endl << endl;

	string text, result;
	cout << "Введите предложение: " << endl;
	getline(cin, text);

	for (size_t i = 0; i < text.length(); i++) {
		if (text.find(text[i]) == text.rfind(text[i])) {
			result += text[i];
		}
	}

	cout << "Результат: " << result << endl;

	return 0;
}
