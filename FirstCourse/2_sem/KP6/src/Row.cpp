#include "../include/Row.hpp"

Row::Row(
            const std::string& surname,
            const std::string& initials,
            const std::string& sex,
            const size_t class_number,
            const std::string& class_letter,
            const std::string& university,
            const std::string& job
        ) {
            this->surname = surname;
            this->initials = initials;
            this->sex = sex;
            this->class_number = class_number;
            this->class_letter = class_letter;
            this->university = university;
            this->job = job;
        }

std::ostream& operator<<(std::ostream &out, const Row& students) {
    out.write(students.surname.c_str(), students.surname.length() + 1);
    out.write(students.initials.c_str(), students.initials.length() + 1);
    out.write(students.sex.c_str(), students.sex.length() + 1);
    out.write((char *) &students.class_number, sizeof(students.class_number));
    out.write(students.class_letter.c_str(), students.class_letter.length() + 1);
    out.write(students.university.c_str(), students.university.length() + 1);
    out.write((char *) &students.job, sizeof(students.job));

    return out;
}


std::istream& operator>>(std::istream &in, Row &students) {
    getline(in, students.surname, '\0');
    getline(in, students.initials, '\0');
    getline(in, students.sex, '\0');
    in.read((char *) &students.class_number, sizeof(students.class_number));
    getline(in, students.class_letter, '\0');
    getline(in, students.university, '\0');
    getline(in, students.job, '\0');
    return in;
}