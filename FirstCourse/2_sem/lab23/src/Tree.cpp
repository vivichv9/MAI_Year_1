#include <iostream>
#include "../include/Tree.hpp"
#include "../include/Node.hpp"

template <typename T>
Tree<T>::Tree(const T& data) {
    root = new Node<T>(data);
}

template <typename T>
Node<T>* Tree<T>::insert(const T& data, Node<T>* node) {
    if(node == nullptr) {
        node = new Node<int>(data);
        node->leftNode = nullptr;
        node->rightNode = nullptr;
    }
    else if(data < node->data)
        node->leftNode = insert(data, node->leftNode);
    else if(data > node->data)
        node->rightNode = insert(data, node->rightNode);
    return node;
}

template <typename T>
void Tree<T>::insert(const T& data) {
    root = insert(data, root);
}

template <typename T>
void Tree<T>::bypass(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    bypass(node->leftNode);

    if (node->leftNode != nullptr and node->rightNode != nullptr) {
        counter++;
    }
    
    bypass(node->rightNode);
}

template <typename T>
void Tree<T>::task() {
    bypass(root);
    std::cout << "\nthe number of vertices of a binary tree having exactly two subtrees: " << counter << '\n';
}

template <typename T>
void Tree<T>::clearTree(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    
    clearTree(node->leftNode);
    clearTree(node->rightNode);
    delete node;
}

template <typename T>
void Tree<T>::bypass() {
    bypass(root);
}

template <typename T>
Tree<T>::~Tree() {
    clearTree(root);
}
