#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkOperand(int operand) {
	for (int i = 0; i < 3; i++)
		operand /= 10;

	if (operand == 0)
		return true;
	else
		return false;
}

void checkMathTasks(const string& inputFile, const string& outputFile) {
	ifstream fileIn(inputFile);
	ofstream fileOut(outputFile);

	if (!fileIn.is_open())
		throw runtime_error("Не удалось открыть входной файл.");
	if (!fileOut.is_open())
		throw runtime_error("Не удалось открыть выходной файл.");

	string line;
	while (getline(fileIn, line)) {
		size_t pos1 = line.find('*');
		size_t pos2 = line.find(':');
		size_t pos3 = line.find('=');

		if (pos3 == -1) {
			fileOut << line << " !" << endl;
			continue;
		}

		char operation = (pos1 != -1) ? '*' : (pos2 != -1 ? ':' : '?');
		size_t opPos = (operation == '*') ? pos1 : pos2;

		if (opPos == -1) {
			fileOut << line << " Неверно введено выражение" << endl;
			continue;
		}

		int operand1 = stoi(line.substr(0, opPos));
		int operand2 = stoi(line.substr(opPos + 1, pos3 - opPos - 1));
		int result = stoi(line.substr(pos3 + 1));

		if (!checkOperand(operand1) || !checkOperand(operand2) || !checkOperand(result))
			throw invalid_argument("Неверно введено выражение");

		bool isCorrect = false;

		if (operation == '*') {
			isCorrect = (operand1 * operand2 == result);
		}
		else if (operation == ':') {
			isCorrect = (operand2 != 0 && operand1 / operand2 == result);
		}

		if (isCorrect) {
			fileOut << line << endl;
		}
		else {
			fileOut << line << " Неверно" << endl;
		}

	}

	fileIn.close();
	fileOut.close();
}

int main() {
	setlocale(LC_ALL, "Russian");

	try
	{
		checkMathTasks("FN1.txt", "FN2.txt");
		return 0;
	}
	catch (exception& e)
	{
		cout << "Ошибка: " << e.what();
	}
}
