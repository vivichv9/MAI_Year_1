#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED
#include <iostream>
#include "Table.hpp"

template<typename T>
class Table;

template <typename T>
class Line {
private:
    T key;
    std::string value;

public:
    friend class Table<T>;

    Line() = default;
    Line(const T& key, const std::string& data);
    Line(const Line<T>& line);
    ~Line() = default;

    T& get_key();
    std::string& get_value();

    bool operator>(const Line<T>& line) const;
};

#include "../src/Line.cpp"

#endif