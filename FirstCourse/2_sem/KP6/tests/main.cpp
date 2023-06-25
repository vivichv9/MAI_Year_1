#include "../include/DataBase.hpp"

int main() {
    DataBase db("students");
    Row r1 (
            "Kudryashov",
            "B.A.",
            "M",
            11,
            "A",
            "HSE",
            "RZD" 
    );

    Row r2 (
            "Valentinov",
            "S.T.",
            "M",
            9,
            "D",
            "MAI",
            "Yandex"
    );
    Row r3(
           "Valentinov",
            "Y.T.",
            "M",
            9,
            "D",
            "Innopolis",
            "Tinkoff"
    );
    Row r4(
            "Samarskaya",
            "U.I.",
            "W",
            11,
            "A",
            "HSE",
            "RZD"
    );
    Row r5(
            "Petrov",
            "B.A.",
            "M",
            11,
            "C",
            "MFTI",
            "RZD"
    );

    size_t number_of_classes = 9;
    std::string letter_of_class = "D";

    db.add_data(r1);
    db.add_data(r2);
    db.add_data(r3);
    db.add_data(r4);
    db.add_data(r5);

    db.task(number_of_classes, letter_of_class);
}    