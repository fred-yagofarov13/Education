#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Str29. Дано шестнадцатеричное число, в котором буквенные обозначения цифр могут быть записаны как заглавными, так и строчными символами."
        << "\nНеобходимо перевести это число в двоичную систему счисления." << endl << endl;

    string hexNumber;
    cout << "Введите шестнадцатеричное число: ";
    cin >> hexNumber;

    transform(hexNumber.begin(), hexNumber.end(), hexNumber.begin(), ::toupper);

    int decimalNumber = 0;
    for (char ch : hexNumber) {
        decimalNumber *= 16;
        if (ch >= '0' && ch <= '9') {
            decimalNumber += ch - '0';
        }
        else if (ch >= 'A' && ch <= 'F') {
            decimalNumber += ch - 'A' + 10;
        }
    }

    string binaryNumber;
    if (decimalNumber == 0) {
        binaryNumber = "0";
    }
    else {
        while (decimalNumber > 0) {
            binaryNumber = (decimalNumber % 2 == 0 ? "0" : "1") + binaryNumber;
            decimalNumber /= 2;
        }
    }

    cout << "Число в двоичной системе: " << binaryNumber << endl;

    return 0;
}
