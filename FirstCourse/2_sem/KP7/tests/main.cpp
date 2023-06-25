#include "../include/Vector.hpp"
#include "../include/Matrix.hpp"
#include "benchmark.cpp"
#include <iostream>

int main() {
    benchmark();

    Matrix matrix;

    std::cin >> matrix;
    matrix.multiplication(matrix.read_vector_from_string());
    return 0;
}