#include <iostream>
#include "../include/Deque.hpp"

int main() {
    Deque<int> deque = {123, 23, 454, 654, 32, 42, 1, 5, 8};

    deque.insert_sort();

    auto ite = deque.begin();
    while (ite != deque.end()) {
        std::cout << *ite << ' '; 
        ++ite;
    }
}