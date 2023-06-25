#include "../include/Stack.hpp"

template <typename T>
Stack<T>::Stack(const std::initializer_list<T>& list) {
    for (T elem: list) {
        stack.push_back(elem);
    }
}

template <typename T>
size_t Stack<T>::size() const {
    return stack.get_size();
}

template <typename T>
bool Stack<T>::empty() const {
    return stack.get_size() == 0;
}

template <typename T>
void Stack<T>::push(const T& value) {
    stack.push_back(value);
}

template <typename T>
void Stack<T>::pop() {
    stack.pop_back();
}

template <typename T>
T& Stack<T>::top() {
    return stack.back();
}

template <typename T>
const T& Stack<T>::top() const {
    return stack.back();
}