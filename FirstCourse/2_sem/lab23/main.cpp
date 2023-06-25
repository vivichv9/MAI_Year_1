#include <iostream>
#include "/Users/kirille/Desktop/labs/lab_23/include/Tree.hpp"
#include "/Users/kirille/Desktop/labs/lab_23/include/vector.hpp"

int main() {
    Tree<int> bt;
    
    bt.insert(50);
    bt.insert(30);
    bt.insert(40);
    bt.insert(20);
    bt.insert(10);
    bt.insert(70);
    bt.insert(60);
    bt.insert(120);
    bt.insert(80);

    bt.task();

    return 0;
}