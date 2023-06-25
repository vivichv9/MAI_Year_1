#include "Tree.hpp"
#include "../src/Tree.cpp"

int main() {
    std::string expr = "2+3+1+4";
    Tree tree(expr);
    tree.task(tree.get_root());
}