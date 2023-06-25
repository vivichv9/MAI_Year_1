#ifndef ROW_HPP_INCLUDED
#define ROW_HPP_INCLUDED

#include <iostream>
#include <string>

class DataBase;

class Row {
    friend class DataBase;
    
private:
    std::string surname;
    std::string initials;
    std::string sex;
    size_t class_number;
    std::string class_letter;
    std::string university;
    std::string job;

public:
    Row() = default;
    ~Row() = default;
    Row(
            const std::string& surname,
            const std::string& initials,
            const std::string& sex,
            const size_t class_number,
            const std::string& class_letter,
            const std::string& university,
            const std::string& job
        );

    friend std::ostream& operator<<(std::ostream& out, const Row& student);
    friend std::istream& operator>>(std::istream& in, Row& student);

    friend class Database;
};

#include "../src/Row.cpp"

#endif