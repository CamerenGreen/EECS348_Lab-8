#include "matrix_operations.cpp"

int main() {
    vector<vector<int>> matrix1, matrix2;

    // Read matrices from file
    readMatrix("matrix.txt", matrix1, matrix2);

    cout << "Matrix 1:" << endl;
    printMatrix(matrix1);
    cout << "Matrix 2:" << endl;
    printMatrix(matrix2);

    // Add matrices
    vector<vector<int>> sumMatrix = addMatrices(matrix1, matrix2);
    cout << "Sum of matrices:" << endl;
    printMatrix(sumMatrix);

    // Multiply matrices
    vector<vector<int>> productMatrix = multiplyMatrices(matrix1, matrix2);
    cout << "Product of matrices:" << endl;
    printMatrix(productMatrix);

    // Sum of diagonals
    int sumDiagonals = sumDiagonal(matrix1);
    cout << "Sum of diagonals in Matrix 1: " << sumDiagonals << endl;

    // Swap rows
    swapRows(matrix1, 0, 1);
    cout << "Matrix 1 after swapping rows 0 and 1:" << endl;
    printMatrix(matrix1);

    // Swap columns
    swapColumns(matrix1, 0, 1);
    cout << "Matrix 1 after swapping columns 0 and 1:" << endl;
    printMatrix(matrix1);

    // Update element
    updateElement(matrix1, 0, 0, 99);
    cout << "Matrix 1 after updating element (0, 0) to 99:" << endl;
    printMatrix(matrix1);

    return 0;
}
