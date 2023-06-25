#ifndef DEQUE_HPP_INCLUDED
#define DEQUE_HPP_INCLUDED

#include "Node.hpp"

template <typename T, typename Allocator = std::allocator<T>>
class Deque {
private:
    Node<T>* head_ptr = nullptr;
    Node<T>* block_ptr = nullptr;
    size_t size = 0;

public:
    class Iterator;

    using Alloc = typename std::allocator_traits<Allocator>::template rebind_alloc<Node<T>>;
    Alloc alloc;
    using AllocTraits = std::allocator_traits<Alloc>;

    Deque();
    Deque(const std::initializer_list<T>& list);
    ~Deque();

    bool empty() const;
    size_t get_size() const;
    void insert(Iterator& it, const T& value);
    void erase(Iterator& it);
    void erase(Iterator& start, Iterator& end);
    void clear();
    void push_front(const T& value);
    void pop_front();
    void push_back(const T& value);
    void pop_back();
    void swap_nodes(Iterator& it_1, Iterator& it_2);
    void set_val(Iterator& it, T& value);
    void task_procedure(Iterator& it, bool& flag, Deque<T, Allocator>& deque);
    void insert_sort();

    template <typename... Args>
    void emplace_back(const Args&... args);

    T& operator[](size_t index);
    Iterator& at(size_t index);
    Iterator begin();
    Iterator end();

    class Iterator {
        friend class Deque<T, Allocator>;
    private:
        Node<T>* current_node_ptr = nullptr;

    public:
        Iterator(Node<T>* ptr);
        T& operator*();
        Iterator& operator=(const Iterator& it);
        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        Iterator& operator+=(size_t n);
        Iterator& operator-=(size_t n);

        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
    };    
};

#include "../src/Deque.cpp"

#endif