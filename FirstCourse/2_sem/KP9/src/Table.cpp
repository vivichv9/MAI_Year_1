#include "../include/Table.hpp"

template <typename T>
void Table<T>::push_back(const T& key, const std::string& data) {
    lines.push_back(Line<T>(key, data));
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Table<T>& table) {
    for (size_t i = 0; i < table.lines.get_size(); ++i) {
        out << table.lines[i].get_key() << '\t' << table.lines[i].get_value() << std::endl;
    }

    return out;
}

template <typename T>
void Table<T>::swap(size_t index1, size_t index2) {
    Line<T> temp;
    temp = lines[index2];
    lines[index2] = lines[index1];
    lines[index1] = temp;
}

template<typename T>
void Table<T>::sort() {
    const double factor = 1.247;
    double step = lines.get_size() - 1;

    while (step >= 1) {
        for (size_t i = 0; i + step < lines.get_size(); ++i) {
            if (lines[i].get_key() > lines[i + step].get_key()) {
                swap(i, i + step);
            }
        }
        step /= factor;
    }
}

template<typename T>
Line<T> Table<T>::search(const T& key) {
    size_t left = 0;
    size_t right = lines.get_size();

    while (left <= right) {
        size_t m = left + (right - left) / 2;

        if (lines[m].get_key() == key) {
            return lines[m];
        }

        if (lines[m].get_key() < key) {
            left = m + 1;

        } else {
           right = m - 1; 
        }  
    }

    return Line<T>(key, "\0");
}