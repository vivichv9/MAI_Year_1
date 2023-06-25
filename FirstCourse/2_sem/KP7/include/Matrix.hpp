#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include "Vector.hpp"

class Matrix{
private:
    Vector<int> line_matrix;
    size_t matrix_lines;
    size_t matrix_columns;

public:
    Matrix();
    Matrix(size_t, size_t);

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);

    void multiplication(const Vector<int>&);
    Vector<int> read_vector_from_string();
};

#include "../src/Matrix.cpp"

#endif

