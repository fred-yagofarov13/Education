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
		throw invalid_argument("Строка пуста или некорректна.");
	}

	for (size_t i = 0; buffer[i] != '\0'; i++) {
		if (int(buffer[i]) == 32 || int(buffer[i]) + 256 == 168 || (int(buffer[i]) + 256 >= 192 && int(buffer[i]) + 256 <= 223)) {
			text += buffer[i];
		}
		else {
			throw invalid_argument("Некорректный ввод текста.");
		}
	}
}

void correctInput(const char* buffer, string& text) {
	if (buffer == nullptr || strlen(buffer) == 0) {
		throw invalid_argument("Строка пуста или некорректна.");
	}

	for (size_t i = 0; buffer[i] != '\0'; i++) {
		if (int(buffer[i]) == 32 || int(buffer[i]) + 256 == 168 || (int(buffer[i]) + 256 >= 192 && int(buffer[i]) + 256 <= 223)) {
			text += buffer[i];
		}
		else {
			throw invalid_argument("Некорректный ввод текста.");
		}
	}
}

void consoleInput(string& text) {
	cout << "\nПри самостоятельном вводе текста, разрешено вводить исключительно заглавные буквы русского алфавита."
		<< "\nВведите текст: ";

	size_t bufferSize = 10;
	char* buffer = new char[bufferSize];

	cin.ignore(INT16_MAX, '\n');
	cin.getline(buffer, bufferSize);

	while (cin.fail()) {
		cin.clear();

		size_t length = strlen(buffer);

		bufferSize *= 2;
		char* newBuffer = new char[bufferSize];

		strcpy_s(newBuffer, bufferSize, buffer);
		delete[] buffer;
		buffer = newBuffer;

		cin.getline(buffer + length, bufferSize - length);
	}

	if (strlen(buffer) == 0) {
		delete[] buffer;
		throw invalid_argument("Ввод пуст.");
	}

	correctInput(buffer, text);

	delete[] buffer;
}

void randomInput(string& text) {
	cout << "\nПри случайном вводе создаётся текст из 1-9 слов,\n каждый из которых содержит 1-10 случайных заглавных русских букв.\n";
	
	char word[10];
	int charLength = rand() % 10;

	for (int i = 0; i <= charLength; i++)
	{
		int wordLength = rand() % 10 + 1;

		for (int j = 0; j < wordLength; j++)
		{
			int charRusAlphabet = ((rand() % (223 - 192)) + 192);
			word[j] = charRusAlphabet;
			text += word[j];
		}
		text += " ";
	}
}

void fileInput(string& text) {
	fstream file;
	file.open("text.txt");

	if (!file.is_open())
		throw runtime_error("Файл с таким названием не существует.");

	string strTemp;
	getline(file, strTemp);

	if (file.fail() || strTemp.empty()) {
		file.close();
		throw invalid_argument("Файл пуст или повреждён.");
	}

	if (file.peek() != EOF) {
		file.close();
		throw invalid_argument("В файле присутствует переход на следующую строку.");
	}

	correctInput(strTemp.c_str(), text);
	file.close();
}

void bubbleSort(vector<string>& sortText) {
	size_t n = sortText.size();

	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = 0; j < n - i - 1; ++j) {
			if (sortText[j].length() > sortText[j + 1].length() || (sortText[j].length() == sortText[j + 1].length() && sortText[j] > sortText[j + 1])) {
				swap(sortText[j], sortText[j + 1]);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));

	cout << "\nExamBase100°. На вход подается текстовая строка, содержащая набор слов,"
		<< "\nнабранных заглавными латинскими буквами и разделенных ровно одним пробелом."
		<< "\nСформировать и вывести строку, содержащую те же слова,"
		<< "\nразделенные одним пробелом и расположенные в порядке возрастания их длины,"
		<< "\nа для слов равной длины — в алфавитном порядке.\n";

	try
	{
		string text = "";

		int choose;
		cout << "\nВыберите, как вы хотите заполнить предложение: "
			<< "\n1 - Ввести самому"
			<< "\n2 - Заполнить случайными буквами"
			<< "\n3 - Получить из файла\n";
		cin >> choose;

		switch (choose)
		{
		case 1:
			consoleInput(text);
			break;
		case 2:
			randomInput(text);
			break;
		case 3:
			fileInput(text);
			break;
		default:
			throw invalid_argument("Некорректный выбор.");
		}

		cout << "\nИсходный текст: " << text << endl;

		string temp = "";
		vector<string> sortText = {};

		for (int i = 0; i < text.length(); )
		{
			while (text[i] != ' ' && i < text.length())
			{
				temp += text[i];
				i++;
			}
			sortText.push_back(temp);
			temp = "";
			i++;
		}

		sort(sortText.begin(), sortText.end(), [](const string& a, const string& b) {
			return a.length() < b.length() || (a.length() == b.length() && a < b);
		});

		//bubbleSort(sortText);

		cout << "Отсортированный текст: ";
		for (const string& str : sortText)
		{
			cout << str << " ";
		}

		cout << endl;

		return 0;
	}
	catch (exception& e)
	{
		cout << "Ошибка: " << e.what();
	}
}
