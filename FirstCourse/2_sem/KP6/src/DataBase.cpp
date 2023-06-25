#include "../include/DataBase.hpp"
#include "../../KP7/include/Vector.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

DataBase::DataBase(const std::string& filename) {
    path = create_file(filename);
}

std::string DataBase::make_dir(const std::string& dir_name) {
    std::string dir_path = std::string("/Users/kirille/Desktop/Kolokviym/MAI_109B_22/Efimenko/KP6/dirs/" + dir_name);

    if (!std::filesystem::is_directory(dir_path.c_str())) {
        std::filesystem::create_directories(dir_path.c_str());
    }

    return dir_path;
}

std::string DataBase::create_file(const std::string& filename) {
    std::fstream file;
    std::string curr_path = make_dir("Databases") + "/" + filename + ".txt";
    file.open(curr_path, std::ios::app);
    if (!file) {
        throw std::runtime_error("Problems with file creation");
    }
    file.close();
    return curr_path;
}

void DataBase::delete_file() {
    std::fstream file;
    if (file) file.close();
    remove(path.data());
}

void DataBase::add_data(const Row& student) {
    std::fstream file;
    if (!file) {
        throw std::runtime_error("File doesn't exist");
    }
    file.open(path.data(), std::ios::out | std::ios::app);
    file << student;
    file.close();
}

bool find(const Vector<std::string>& vec, const std::string& value) {
    for (size_t i = 0; i < vec.get_size(); ++i) {
        if (vec[i] == value) {
            return true;
        }
    }

    return false;
}

void DataBase::task(const size_t class_number, const std::string& class_letter) const {
    std::fstream file;
    Vector<std::string> families;
    file.open(path.data(), std::ios::in);
    Row student;
    while (file.peek() != EOF) {
        file >> student;
        if (find(families, student.surname)) {
            std::cout << "namesakes is exist\n";
            file.close();
            return;
        }
        families.push_back(student.surname);
    }
    std::cout << "namesakes doesn't exist\n";
    file.close();
}