#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T& data){
    this->data = data;
}

template <typename T>
T& Node<T>::getData() {
    return data;
}