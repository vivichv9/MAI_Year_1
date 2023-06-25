#include "../include/Node.hpp"

Node::Node(): data(0), left(nullptr), right(nullptr) {}

Node::Node(const char data): data(data), left(nullptr), right(nullptr) {}

Node::Node(const char data, Node* left, Node* right): data(data), left(left), right(right) {}