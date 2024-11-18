#include <iostream>
#include <cmath>

using namespace std;

// Функция для преобразования числа из системы счисления с основанием P в десятичную систему
int toDecimal(int num, int base) {
    int decimalValue = 0;
    int power = 0;

    while (num > 0) {
        int digit = num % 10;
        decimalValue += digit * pow(base, power);
        num /= 10;
        power++;
    }

    return decimalValue;
}

// Функция для преобразования числа из десятичной системы обратно в систему с основанием P
int fromDecimal(int decimalValue, int base) {
    int result = 0;
    int power = 1;
    bool isNegative = decimalValue < 0;

    decimalValue = abs(decimalValue);

    while (decimalValue > 0) {
        int remainder = decimalValue % base;
        result += remainder * power;
        decimalValue /= base;
        power *= 10;
    }

    return isNegative ? -result : result;
}

// Функция для выполнения вычитания чисел X и Y в системе счисления с основанием P
int subtractInBaseP(int X, int Y, int base) {
    int decimalX = toDecimal(X, base);
    int decimalY = toDecimal(Y, base);

    int resultDecimal = decimalX - decimalY;

    return fromDecimal(resultDecimal, base);
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Программа выполняет вычитание чисел, заданных в одной и той же системе счисления(можно переводить в 10 систему счисления для вычитания)" << endl << endl;

    int X, Y;
    int P;

    cout << "Введите основание системы счисления (P): ";
    cin >> P;

    if (P < 2 || P > 9) {
        cout << "Основание системы счисления должно быть в диапазоне от 2 до 9." << endl;
        return 1;
    }

    cout << "Введите число X в системе счисления с основанием " << P << ": ";
    cin >> X;

    int temp = X;

    while (temp != 0) {
        if (temp % 10 >= P || temp % 10 < 0)
        {
            cout << "Присутствует цифра, не подходящая под систему счисления " << P;
            return 1;
        }
        temp /= 10;
    }

    cout << "Введите число Y в системе счисления с основанием " << P << ": ";
    cin >> Y;

    temp = Y;

    while (temp != 0) {
        if (temp % 10 >= P || temp % 10 < 0)
        {
            cout << "Присутствует цифра, не подходящая под систему счисления " << P;
            return 1;
        }
        temp /= 10;
    }

    int result = subtractInBaseP(X, Y, P);

    cout << "Результат вычитания: " << result << endl;

    return 0;
}