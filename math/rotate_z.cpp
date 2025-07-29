#include <iostream>
#include <vector>
#include <cmath>

/*
 * rotate_vector_z.cpp
 * Rotates a 3D vector by a given angle (in degrees) around the Z-axis.
 *
 * Author: Luke Miller
 * Date: 2025-07-03
 *
 * Compile with:
 *     g++ rotate_vector_z.cpp -o rotate_vector_z -std=c++17
 */

const double PI = 3.14159265358979323846;

// Perform matrix-vector multiplication
std::vector<double> rotateVector(const std::vector<std::vector<double>>& R,
                                 const std::vector<double>& vec_in) {
    std::vector<double> vec_rot(vec_in.size(), 0.0);

    for (size_t i = 0; i < R.size(); ++i) {
        for (size_t j = 0; j < R[0].size(); ++j) {
            vec_rot[i] += R[i][j] * vec_in[j];
        }
    }

    return vec_rot;
}

// Pretty print a vector to stdout
void printVector(const std::vector<double>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Input vector
    std::vector<double> vec = {1, 2, 3};

    // Rotation angle in degrees
    double angle_deg = 90.0;
    double angle_rad = angle_deg * PI / 180.0;

    // Define Z-axis rotation matrix (right-handed coordinate system)
    std::vector<std::vector<double>> R = {
        {std::cos(angle_rad), -std::sin(angle_rad), 0},
        {std::sin(angle_rad),  std::cos(angle_rad), 0},
        {0,                    0,                   1}
    };

    std::vector<double> rotated = rotateVector(R, vec);

    std::cout << "Original vector: ";
    printVector(vec);
    std::cout << "Rotated vector (Z-axis, " << angle_deg << " deg): ";
    printVector(rotated);

    return 0;
}