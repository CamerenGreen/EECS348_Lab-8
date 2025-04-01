#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

void readMatrix(const string& filename, vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return;
    }

    int N;
    file >> N;
    matrix1.resize(N, vector<int>(N));
    matrix2.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> matrix1[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> matrix2[i][j];

    file.close();
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(4) << elem << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int N = matrix1.size();
    vector<vector<int>> result(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
    return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int N = matrix1.size();
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
    return result;
}

int sumDiagonal(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += matrix[i][i];
        sum += matrix[i][N-i-1];
    }
    return sum;
}

void swapRows(vector<vector<int>>& matrix, int row1, int row2) {
    int N = matrix.size();
    if (row1 >= 0 && row1 < N && row2 >= 0 && row2 < N) {
        swap(matrix[row1], matrix[row2]);
    }
}

void swapColumns(vector<vector<int>>& matrix, int col1, int col2) {
    int N = matrix.size();
    if (col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {
        for (int i = 0; i < N; ++i)
            swap(matrix[i][col1], matrix[i][col2]);
    }
}

void updateElement(vector<vector<int>>& matrix, int row, int col, int newVal) {
    int N = matrix.size();
    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = newVal;
    }
}
