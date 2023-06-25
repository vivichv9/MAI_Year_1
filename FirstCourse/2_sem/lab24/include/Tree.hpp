#ifndef TREE_HPP_INCLUDED_
#define TREE_HPP_INCLUDED_

#include "Node.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>

class Tree {
private:
    Node* root;

public:
    Tree();
    Tree(const std::string& expression);
    ~Tree();

    Node* get_root() const;

    void delete_tree(Node* node);
    Node* create_tree(const std::string& postfix);
    std::string to_postfix(const std::string& expression);

    void print_tree(Node* root, const size_t height = 0) const;
    void task(Node* root);
};

#endif