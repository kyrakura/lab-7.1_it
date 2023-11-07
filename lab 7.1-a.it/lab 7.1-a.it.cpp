#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

const int ROWS = 8;//������� �����
const int COLS = 5;// ������� ��������

// ��������� ��������� �������
void Generate(int matrix[ROWS][COLS], int min, int max) {
    srand(time(nullptr));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

// ��������� �������
void Print(const int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

// ���������� ������� �� ���� ��������, �� ������������� �������
void Apply(int matrix[ROWS][COLS], int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] < 0 && matrix[i][j] % 4 != 0) {
                count++;
                sum += matrix[i][j];
                matrix[i][j] = 0;
            }
        }
    }
}

// ���������� �������
void Sort(int matrix[ROWS][COLS], const int sorting[3]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = i + 1; j < ROWS; ++j) {
            bool Swap = false;
            int k = 0;
            while (k < 3 && matrix[i][sorting[k]] == matrix[j][sorting[k]]) {
                k++;
            }
            if (k < 3) {
                Swap = matrix[i][sorting[k]] > matrix[j][sorting[k]];
            }
            if (Swap) {
                for (int k = 0; k < COLS; ++k) {
                    swap(matrix[i][k], matrix[j][k]);
                }
            }
        }
    }
}

// ������� ��� ���������� ������� �� ��������� �������
void Sort2(int matrix[ROWS][COLS]) {
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS - 1; ++j) {
            for (int k = 0; k < ROWS - j - 1; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    for (int l = 0; l < COLS; ++l) {
                        swap(matrix[k][l], matrix[k + 1][l]);
                    }
                }
                else if (matrix[k][i] == matrix[k + 1][i]) {
                    int l = i + 1;
                    while (l < COLS && matrix[k][l] == matrix[k + 1][l]) {
                        l++;
                    }
                    if (l < COLS && matrix[k][l] > matrix[k + 1][l]) {
                        for (l = 0; l < COLS; ++l) {
                            swap(matrix[k][l], matrix[k + 1][l]);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int matrix[ROWS][COLS];
    int min = -17;
    int max = 14;

    Generate(matrix, min, max);

    cout << "��������� �������: " << endl;
    Print(matrix);

    int count, sum;
    Apply(matrix, count, sum);
    cout << "ʳ������ ��������, �� ���������� �������: " << count << endl;
    cout << "�������� ���� ��������, �� ���������� �������: " << sum << endl;

    int sorting[3] = { 0, 1, 2 };
    Sort(matrix, sorting);

    cout << "³���������� �������:" << endl;
    Print(matrix);

    Sort2(matrix);

    cout << "������� ���� ����������:" << endl;
    Print(matrix);

    return 0;
}
