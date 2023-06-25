#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include "Row.hpp"
#include <iostream>
#include <string>

class DataBase {
private:
    std::string path;

public:
    DataBase() = default;
    DataBase(const std::string& file_name);
    ~DataBase() = default;

    std::string create_file(const std::string& file_name = "db_1");
    void delete_file();
    void add_data(const Row& student);
    std::string make_dir(const std::string& dir_name);
    void task(const size_t class_number, const std::string& class_letter) const;
    void print() const;
};

#include "../src/DataBase.cpp"

#endif