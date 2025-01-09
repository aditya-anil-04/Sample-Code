#include <stdio.h>

#define MAX_SIZE 10 // Maximum size of the matrix

void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name) {
    printf("Enter elements for Matrix %c (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int rows, int cols, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name) {
    printf("Matrix %c (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Input dimensions of matrices
    printf("Enter the number of rows and columns for the matrices (max %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE || rows <= 0 || cols <= 0) {
        printf("Invalid dimensions! Please use values between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Input matrices
    inputMatrix(rows, cols, matrixA, 'A');
    inputMatrix(rows, cols, matrixB, 'B');

    // Add matrices
    addMatrices(rows, cols, matrixA, matrixB, result);

    // Print matrices and the result
    printMatrix(rows, cols, matrixA, 'A');
    printMatrix(rows, cols, matrixB, 'B');
    printMatrix(rows, cols, result, 'R');

    return 0;
}
