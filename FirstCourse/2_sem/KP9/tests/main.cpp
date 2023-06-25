#include <iostream>
#include "../include/Table.hpp"
#include <string>
#include "benchmark.cpp"

int main() {
    benchmark();

    Table<std::string> table;
    
    table.push_back("I", "Clash Royale");
    table.push_back("B", "Brawl Stars");
    table.push_back("K", "Drive Ahead");
    table.push_back("C", "Hay Day");
    table.push_back("Y", "Clash of Clans");
    table.push_back("E", "Beach Boom");
    table.push_back("K", "Minecraft");
    table.push_back("O", "Warface");
    table.push_back("Q", "Rust");
    table.push_back("W", "CS:GO");
    table.push_back("H", "Blockade 3D");
    table.push_back("A", "Free Fire");
    table.push_back("N", "Standoff 2");
    table.push_back("V", "Roblox");
    table.push_back("U", "Flappy bird");
    table.push_back("G", "Sub Way Surfes");
    table.push_back("P", "Fruit ninja");
    table.push_back("F", "PUBG");
    table.push_back("Z", "APEX Legends");
    table.push_back("A", "SUPER STRIKE MEGA BIG SIMULATOR 3000");

    table.sort();

    std::cout << table << std::endl;

    std::string str = "A";
    Line<std::string> search_res = table.search(str);

    if (search_res.get_value() != "\0") {
        std::cout << "Object with key '" << search_res.get_key()
                    << "' found! Data inside is '" << search_res.get_value()
                    << "'" << std::endl;

    } else {
        std::cout << "Object with key '" << search_res.get_key()
                    << "' not found!" << std::endl;
    }

    return 0;
}