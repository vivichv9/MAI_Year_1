#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(const T& value): value(value) {}

template <typename T>
Node<T>::Node(const T& value, Node<T>* prev, Node<T>* current_node): value(value), next(current_node), prev(prev) {}

template <typename T>
void Node<T>::set_value(const T& value) {
    this->value = value;
}