#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include "../../KP7/include/Vector.hpp"
#include <iostream>

template <typename T>
class Stack {
private:
    Vector<T> stack;

public:
    Stack() = default;
    Stack(const std::initializer_list<T>& list);
    ~Stack() = default;

    size_t size() const;
    bool empty() const;
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
};

#include "../src/Stack.cpp"

#endif