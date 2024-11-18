#include <iostream>
using namespace std;

// Функция для проверки, является ли число палиндромом
bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

// Функция для вычисления произведения цифр числа
int productOfDigits(int num) {
    int product = 1;
    while (num != 0) {
        int digit = num % 10;
        product *= digit;
        num /= 10;
    }
    return product;
}

int main() {
    setlocale(LC_ALL, "Russian");

    
    cout << "Программа выводит числа в отрезке [A, B], у которых произведение всех цифр не является палиндромом" << endl << endl;

    int A, B;
    cout << "Введите значения A и B (границы диапазона): ";
    cin >> A >> B;

    if (A > B) {
        cout << "Некорректный ввод. A должно быть меньше или равно B." << endl;
        return 1;
    }

    bool found = false;

    // Проверяем все числа в диапазоне [A, B]
    for (int i = A; i <= B; i++) {
        if (isPalindrome(i)) {
            int product = productOfDigits(i);

            if (!isPalindrome(product)) {
                cout << i << " ";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No solution" << endl;
    }

    return 0;
}
