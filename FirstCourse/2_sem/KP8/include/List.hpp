#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include <iostream>

template <typename T, typename Allocator = std::allocator<T>>
class List {
private:
    class Node {
    public:
        T value;
        Node* next = nullptr;

        Node(const T& value);
        Node(const T& value, Node* next);
    };

    using Alloc = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
    Alloc alloc;
    using AllocTraits = std::allocator_traits<Alloc>;

    Node* head_ptr = nullptr;
    Node* const block_element_ptr = AllocTraits::allocate(alloc, 1);
    size_t size = 0;

public:
    class Iterator;

    size_t get_size() const;

    List() = default;
    List(const T& value);
    ~List();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    void insert(const T& value, Iterator& it);
    void erase(Iterator& iter);
    void erase(Iterator& start, Iterator& end);

    template <typename... Args>
    void emplace_back(const Args&... args);

    std::ostream& operator<<(std::ostream& stream);

    class Iterator {    
    public:
        Node* current_node_ptr = nullptr;

        Iterator(Node& node);

        Iterator& operator=(Node* node_ptr);
        Iterator& operator++();
        Iterator& operator++(int);

        T& operator*();
        const T& operator*() const ;

        bool operator!=(const Iterator& iterator) const;
        bool operator==(const Iterator& iterator) const; 
    };

    Iterator begin() const;
    Iterator end() const;
};

#include "../src/List.cpp"

#endif