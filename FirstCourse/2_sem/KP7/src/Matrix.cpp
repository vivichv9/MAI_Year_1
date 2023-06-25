#include <iostream>
#include "../include/Matrix.hpp"

Matrix::Matrix(): matrix_lines(0), matrix_columns(0) {
    line_matrix.push_back(0);
    line_matrix.push_back(0);
}

Matrix::Matrix(size_t lines, size_t columns): matrix_lines(lines), matrix_columns(columns) {
    line_matrix.push_back(0);
    line_matrix.push_back(0);
}

Vector<int> Matrix::read_vector_from_string() {
    Vector<int> v;
    size_t size = 0;
    int value = 0;
    std::cout << "Enter size of vector-string: ";
    std::cin >> size;

    std::cout << "Enter " << size << " elements: ";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> value;
        v.push_back(value);
    }

    return v;
}

void Matrix::multiplication(const Vector<int>& vector_string) {

    if (vector_string.get_size() != matrix_lines) {
        throw std::range_error("columns != lines");
    }

    Vector<int> result;

    for (size_t i = 0; i < matrix_columns; ++i) {
        result.push_back(0);
    }

    size_t cur_line = 0;
    while (cur_line < line_matrix.get_size()) {
        size_t j = line_matrix[cur_line];

        if (j == 0) {
            ++cur_line;

            if (cur_line >= line_matrix.get_size() || line_matrix[cur_line] == 0) {
                break;
            }    

            j = line_matrix[cur_line];
        }

        size_t cur_column = cur_line + 1;
        size_t column_of_result_vector = line_matrix[cur_line] - 1;

        for (size_t column = cur_column; line_matrix[column] != 0; column += 2) {
            int value = line_matrix[column + 1];
            result[line_matrix[column] - 1] += (vector_string[column_of_result_vector] * value);
            cur_line = column;
        }

        ++cur_line;
    }

    size_t non_zero_el = 0;
    std::cout << "Result: ";
    for (size_t i = 0; i != result.get_size(); ++i) {
        if (result[i] != 0) ++non_zero_el;
        std::cout << result[i] << " ";
    }
    std::cout << "\nCount of non-zeros elements of the result: " << non_zero_el << "\n";
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    matrix.line_matrix.pop_back();
    size_t line;
    size_t columns;
    int input_value;

    std::cout << "Enter count of lines, columns: ";

    is >> line >> columns;

    std::cout << '\n' << "Enter " << line * columns << " elements: ";

    matrix.matrix_lines = line;
    matrix.matrix_columns = columns;

    for (size_t i = 0; i < line; ++i){
        for (size_t j = 0; j < columns; ++j){
            is >> input_value;
            if (input_value != 0){
                if (matrix.line_matrix.back() == 0){
                    matrix.line_matrix.push_back(i + 1);
                }
                matrix.line_matrix.push_back(j + 1);
                matrix.line_matrix.push_back(input_value);
            }
        }

        if (matrix.line_matrix.back() != 0){
            matrix.line_matrix.push_back(0);
        }
    }

    matrix.line_matrix.push_back(0);

    return is;
}
