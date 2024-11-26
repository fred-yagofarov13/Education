#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <conio.h>

using namespace std;

void clearScreen() {
    system("cls");
}

void printMatrix(int matrix[4][4]) {
    cout << "+----+----+----+----+" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "|";
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == 0)
                cout << "    |";
            else
                cout << setw(3) << matrix[i][j] << " |";
        }
        cout << endl << "+----+----+----+----+" << endl;
    }
}

bool isSolvable(int matrix[4][4]) {
    int inversions = 0;
    int tiles[16];
    int index = 0;
    int zeroRow = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tiles[index] = matrix[i][j];
            index++;
        }
    }

    for (int i = 0; i < 16; ++i) {
        if (tiles[i] == 0) continue;
        for (int j = i + 1; j < 16; ++j) {
            if (tiles[j] == 0) continue;
            if (tiles[i] > tiles[j]) inversions++;
        }
    }

    for (int i = 3; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] == 0) {
                zeroRow = 4 - i;
                break;
            }
        }
        if (zeroRow != 0) break;
    }

    return ((inversions + zeroRow) % 2 == 0);
}

void fillRandomNumbers(int matrix[4][4]) {
    srand(time(0));
    int numbers[16];
    for (int i = 0; i < 15; ++i) {
        numbers[i] = i + 1;
    }
    numbers[15] = 0;

    do {
        random_shuffle(numbers, numbers + 15);

        int index = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = numbers[index];
                index++;
            }
        }
    } while (!isSolvable(matrix));
}

void findZero(int matrix[4][4], int& iZero, int& jZero) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] == 0) {
                iZero = i;
                jZero = j;
                return;
            }
        }
    }
}

void moveLeft(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (jZero > 0) {
        swap(matrix[iZero][jZero], matrix[iZero][jZero - 1]);
        moveCount++;
    }
}

void moveUp(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (iZero > 0) {
        swap(matrix[iZero][jZero], matrix[iZero - 1][jZero]);
        moveCount++;
    }
}

void moveRight(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (jZero < 3) {
        swap(matrix[iZero][jZero], matrix[iZero][jZero + 1]);
        moveCount++;
    }
}

void moveDown(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (iZero < 3) {
        swap(matrix[iZero][jZero], matrix[iZero + 1][jZero]);
        moveCount++;
    }
}

bool isSorted(int matrix[4][4]) {
    int count = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == 3 && j == 3) {
                if (matrix[i][j] != 0)
                    return false;
            }
            else {
                if (matrix[i][j] != count)
                    return false;
                count++;
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int restart;
    do {
        int matrix[4][4];
        fillRandomNumbers(matrix);

        int moveCount = 0;

        while (true) {
            clearScreen();
            printMatrix(matrix);

            if (isSorted(matrix)) {
                cout << "Поздравляем! Вы собрали пятнашки!" << endl;
                cout << "Количество ходов: " << moveCount << endl;
                break;
            }

            cout << "Используйте стрелки для перемещения плиток. Esc - выход." << endl;

            int key = _getch();

            if (key == 224) {
                key = _getch();
                switch (key) {
                case 72:
                    moveUp(matrix, moveCount);
                    break;
                case 80:
                    moveDown(matrix, moveCount);
                    break;
                case 75:
                    moveLeft(matrix, moveCount);
                    break;
                case 77:
                    moveRight(matrix, moveCount);
                    break;
                default:
                    break;
                }
            }
            else if (key == 27) {
                break;
            }
        }

        cout << "Хотите сыграть ещё раз? (1 - да, 0 - нет): ";
        cin >> restart;

    } while (restart != 0);

    return 0;
}