/*
 * matrix_multiply.cpp
 * Multiplies two 2D matrices A (m x n) and B (n x p) using nested vectors.
 *
 * Author: Luke Miller
 * Date: 2025-07-03
 * Compile with:
 *     g++ matrix_multiply.cpp -o matrix_multiply -std=c++17
 */

#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    size_t m = A.size();
    size_t n = A[0].size();
    size_t p = B[0].size();

    Matrix result(m, std::vector<double>(p, 0.0));

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < p; ++j) {
            for (size_t k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (double val : row) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }
}

int main() {
    Matrix A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    Matrix B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    Matrix C = multiply(A, B);

    std::cout << "Result of A * B:\n";
    printMatrix(C);

    return 0;
}