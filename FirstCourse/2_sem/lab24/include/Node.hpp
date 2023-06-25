#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

class Tree;

class Node {
    friend class Tree;

private:
    char data;
    Node* left;
    Node* right;

public:
    Node();
    Node(const char data);
    Node(const char data, Node* left, Node* right);
};

#include "../src/Node.cpp"

#endif