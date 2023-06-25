#include "../include/Tree.hpp"

Tree::Tree(): root(nullptr) {}

Tree::Tree(const std::string& expression) {
    std::string postfix = to_postfix(expression);
    root = create_tree(postfix);
}

Tree::~Tree() {
    delete_tree(root);
}

Node* Tree::get_root() const {
    return this->root;
}

bool isOperator(char c) {
    return (c == '+' || c == '-');
}

size_t getPriority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }    

    return 0;
}

std::string Tree::to_postfix(const std::string& expression) {
    std::string postfix = "";
    Stack<char> stack;

    for (size_t i = 0; i != expression.size(); ++i) {
        char c = expression[i];

        if (!isOperator(c) && c != '(' && c != ')') { 
            postfix += c;
        } else if (c == '('){
            stack.push(c);
        } else if (c == ')'){
            while (stack.top() != '('){
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.empty() && (getPriority(stack.top()) >= getPriority(c))){
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

void Tree::delete_tree(Node* node) {
    if (node == nullptr) return;

    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

Node* Tree::create_tree(const std::string& postfix) {
    if (postfix.length() == 0) return nullptr;

    Stack<Node*> stack;

    for (char c: postfix) {
        if (isOperator(c)) {
            Node* node_x = stack.top();
            stack.pop();

            Node* node_y = stack.top();
            stack.pop();

            Node* node = new Node(c, node_y, node_x);
            stack.push(node);
        } else {
            stack.push(new Node(c));
        }
    }

    return stack.top();
}

void Tree::print_tree(Node* root, const size_t height) const {
    if (root != nullptr){
        print_tree(root->right, height + 1);
        for (size_t i = 0; i < height; ++i) {
            std::cout << "\t";
        }
        std::cout << root->data << "\n";
        print_tree(root->left, height + 1);
    }
}

void Tree::task(Node* root) {
    if (root == nullptr) {
        return;
    }
    task(root->right);
    std::cout << root->data;
    task(root->left);
}
