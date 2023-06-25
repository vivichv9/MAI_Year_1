#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include "../../KP7/include/Vector.hpp"
#include "Line.hpp"

template<typename T>
class Table {
private:
    Vector<Line<T>> lines;

public:
    Table() = default;
    ~Table() = default;

    void swap(size_t index1, size_t index2);
    void push_back(const T& key, const std::string& data);
    void sort();
    Line<T> search(const T& key);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, Table<U>& table);
};

#include "../src/Table.cpp"

#endif