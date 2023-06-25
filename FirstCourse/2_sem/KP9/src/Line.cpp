#include "../include/Line.hpp"

template <typename T>
Line<T>::Line(const T& key, const std::string& value): key(key), value(value) {}

template <typename T>
Line<T>::Line(const Line<T>& line) {
    this->key = line.key;
    this->value = line.value;
}

template<typename T>
T& Line<T>::get_key() {
    return key;
}

template<typename T>
std::string& Line<T>::get_value() {
    return value;
}

template <typename T>
bool Line<T>::operator>(const Line<T>& line) const {
    return key > line.key;
}