#include <iostream>
#include <cmath>

using namespace std;

bool isPointInBigCircle(double x, double y) {
    // Проверяем, лежит ли точка в большом полукруге радиуса 2
    return (x * x + y * y <= 4 && y >= 0);
}

bool isPointInSmallCircle(double x, double y) {
    // Проверяем, лежит ли точка в малом круге радиуса 0.3 с центром в (0, 0.3)
    return ((x * x + (y - 0.3) * (y - 0.3)) <= 0.09); // 0.3^2 = 0.09
}

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Программа определяет, принадлежит ли точка с координатами (x, y) заштрихованной части плоскости (рис.3 по задачнику)" << endl << endl;

    double x, y;
    cout << "Введите координаты x и y: ";
    cin >> x >> y;

    // Проверяем, попадает ли точка в большой круг, но не в маленький
    string result = (isPointInBigCircle(x, y) && !isPointInSmallCircle(x, y)) ? "True(Точка принадлежит заштрихованной области)" : "False(Точка не принадлежит заштрихованной области)";

    cout << "Результат: " << result << endl;

    return 0;
}