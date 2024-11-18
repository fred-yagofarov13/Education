#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Str13. Дана строка символов. Заменить все вхождения символа '<' на 'begin', а каждое вхождение символа '>' на 'end'" << endl << endl;

    string text;
    cout << "Введите предложение: " << endl;
    getline(cin, text);

    size_t position = 0;
    while ((position = text.find('<', position)) != -1) {
        text.replace(position, 1, "begin");
        position += 5;
    }

    position = 0;
    while ((position = text.find('>', position)) != -1) {
        text.replace(position, 1, "end");
        position += 3;
    }

    cout << "Результат: " << text << endl;

    return 0;
}
