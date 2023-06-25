#include <iostream>
#include "benchmark.cpp"
#include "../include/List.hpp"

int main() {
    benchmark();

    List<int> list;
    int left_border = 0;
    int right_border = 0;
    size_t list_size = 0;

    std::cout << "Enter list size: ";
    std::cin >> list_size;

    int array[list_size];

    std::cout << "\nEnter values of list: ";
    for (int i = list_size - 1; i >= 0; --i) {
        std::cin >> array[i];
    }
    std::cout << "\nList sucessfully created!\n";

    std::cout << "\nPlease enter left border: ";
    std::cin >> left_border;

    std::cout << "\nRight border: ";
    std::cin >> right_border;

    for (size_t i = 0; i < list_size; ++i) {
        list.push_front(array[i]);
    }

    List<int>::Iterator begin = list.begin();
    List<int>::Iterator end = list.end();

    std::cout << "\nResult: ";
    for (; begin != end; ++begin) {
        if (*begin >= left_border && *begin <= right_border) {
            std::cout << *begin << ' ';
        }
    }
    std::cout << '\n';
}