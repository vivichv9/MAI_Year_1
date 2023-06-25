#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <iostream>

template<typename T>
class Tree;

template<typename T>
class Node {
    friend class Tree<T>;

    T data;
    Node<T>* leftNode = nullptr;
    Node<T>* rightNode = nullptr;

    Node(const T&);
    T& getData();
};

#include "../src/Node.cpp"

#endif


