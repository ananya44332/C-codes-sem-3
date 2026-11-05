#include <iostream>
using namespace std;

const int MAX = 10;

void readMatrix(int mat[][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];
}

void displayMatrix(int mat[][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void add(int a[][MAX], int b[][MAX], int r, int c) {
    int res[MAX][MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
    cout << "Result of Addition:\n";
    displayMatrix(res, r, c);
}

void subtract(int a[][MAX], int b[][MAX], int r, int c) {
    int res[MAX][MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
    cout << "Result of Subtraction:\n";
    displayMatrix(res, r, c);
}

void multiply(int a[][MAX], int b[][MAX], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!\n";
        return;
    }
    int res[MAX][MAX] = {0};
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
    cout << "Result of Multiplication:\n";
    displayMatrix(res, r1, c2);
}

void transpose(int a[][MAX], int r, int c) {
    int res[MAX][MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[j][i] = a[i][j];
    cout << "Result of Transpose:\n";
    displayMatrix(res, c, r);
}

int main() {
    int choice, r1, c1, r2, c2;
    int a[MAX][MAX], b[MAX][MAX];

    cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\nEnter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 3) {
        cout << "Enter rows and cols for Matrix 1: ";
        cin >> r1 >> c1;
        cout << "Enter elements for Matrix 1:\n";
        readMatrix(a, r1, c1);

        cout << "Enter rows and cols for Matrix 2: ";
        cin >> r2 >> c2;
        cout << "Enter elements for Matrix 2:\n";
        readMatrix(b, r2, c2);
    } else if (choice == 4) {
        cout << "Enter rows and cols for Matrix: ";
        cin >> r1 >> c1;
        cout << "Enter elements:\n";
        readMatrix(a, r1, c1);
    }

    switch (choice) {
        case 1:
            if (r1 == r2 && c1 == c2) add(a, b, r1, c1);
            else cout << "Dimensions must match for addition!\n";
            break;
        case 2:
            if (r1 == r2 && c1 == c2) subtract(a, b, r1, c1);
            else cout << "Dimensions must match for subtraction!\n";
            break;
        case 3:
            multiply(a, b, r1, c1, r2, c2);
            break;
        case 4:
            transpose(a, r1, c1);
            break;
        default:
            cout << "Invalid choice!\n";
    }
    return 0;
}
