#ifndef INCLUDE_TREE_HPP
#define INCLUDE_TREE_HPP

#include "Node.hpp"

template <typename T>
class Tree {
    private:
        Node<T>* root = nullptr;
        int counter = 0;

        Node<T>* insert(const T&, Node<T>*);
        void bypass(Node<T>*);
        void clearTree(Node<T>*);

    public: 
        Tree() = default;;
        Tree(const T&);
        ~Tree();

        void insert(const T&);
        void bypass();
        void task();
};

#include "../src/Tree.cpp"

#endif