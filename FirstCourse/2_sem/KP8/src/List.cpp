#include "../include/List.hpp"

template <typename T, typename Allocator>
List<T, Allocator>::List(const T& value) {
    Node* ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, ptr, value);
    head_ptr = ptr;
    head_ptr->next = block_element_ptr;
    ++size;
}

template <typename T, typename Allocator>
List<T, Allocator>::~List() {
    while (head_ptr) {
        if (head_ptr == block_element_ptr) {
            AllocTraits::deallocate(alloc, head_ptr, 1);
            return;
        }

        Node* new_head = head_ptr->next;
        AllocTraits::destroy(alloc, head_ptr);
        AllocTraits::deallocate(alloc, head_ptr, 1);
        head_ptr = new_head;
    }
}

template <typename T, typename Allocator>
size_t List<T, Allocator>::get_size() const {
    return size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_back(const T& value) {
    if (size == 0) {
        push_front(value);
        return;
    }

    Node* temp_ptr = head_ptr;

    while (temp_ptr->next != block_element_ptr) {
        temp_ptr = temp_ptr->next;
    }

    Node* new_node_ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, new_node_ptr, value);

    temp_ptr->next = new_node_ptr;
    new_node_ptr->next = block_element_ptr;
    ++size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::push_front(const T& value) {
    Node* swap_ptr = nullptr;
    Node* ptr = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, ptr, value);

    if (head_ptr == nullptr) {
        head_ptr = ptr;
        ptr->next = block_element_ptr;
    } else {
        swap_ptr = head_ptr;
        this->head_ptr = ptr;
        this->head_ptr->next = swap_ptr;
    }
    ++size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::pop_back() {
    if (size == 0) {
        return;
    }

    if (size == 1) {
        pop_front();
        return;
    }

    Iterator it = begin();

    while (it.current_node_ptr->next->next != block_element_ptr) {
        ++it;
    }


    AllocTraits::destroy(alloc, it.current_node_ptr->next);
    AllocTraits::deallocate(alloc, it.current_node_ptr->next, 1);

    it.current_node_ptr->next = block_element_ptr;
    --size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::pop_front() {
    if (head_ptr == nullptr) {
        return;
    }

    Node* temp_ptr = nullptr;
    temp_ptr = head_ptr;
    head_ptr = head_ptr->next;
    --size;

    if (head_ptr == block_element_ptr) {
        head_ptr = nullptr;
    }

    AllocTraits::destroy(alloc, temp_ptr);
    AllocTraits::deallocate(alloc, temp_ptr, 1);
}

template <typename T, typename Allocator>
template <typename... Args>
void List<T, Allocator>::emplace_back(const Args&... args) {
    push_back(T(args...));
}

template <typename T, typename Allocator>
void List<T, Allocator>::insert(const T& value, Iterator& iterator) {
    if (iterator.current_node_ptr == block_element_ptr) {
        return;
    }

    Node* ptr = iterator.current_node_ptr->next;
    Node* new_object = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, new_object, value);

    iterator.current_node_ptr->next = new_object;
    new_object->next = ptr;

    ++size;
}

template <typename T, typename Allocator>
void List<T, Allocator>::erase(Iterator& iter) {
    if (size == 0) {
        return;
    }

    Iterator it = this->begin();

    while (it.current_node_ptr->next != iter.current_node_ptr) {
        ++it;
    }

    Node* temp_ptr = iter.current_node_ptr->next;
    AllocTraits::destroy(alloc, it.current_node_ptr->next);
    AllocTraits::deallocate(alloc, it.current_node_ptr->next, 1);
    it.current_node_ptr->next = temp_ptr;
}

template <typename T, typename Allocator>
void List<T, Allocator>::erase(Iterator& start, Iterator& end) {
    Iterator it = this->begin();

    if (it != start) {
        while (it.current_node_ptr->next != start.current_node_ptr) {
            ++it;
        }
        it.current_node_ptr->next = end.current_node_ptr;

    } else {
        head_ptr = end.current_node_ptr;
    }

    while (start != end) {
        ++it;
        AllocTraits::destroy(alloc, start.current_node_ptr);
        AllocTraits::deallocate(alloc, start.current_node_ptr, 1);
        --size;
        start = it;
    }
}

template <typename T, typename Allocator>
std::ostream& List<T, Allocator>::operator<<(std::ostream& stream) {
    for (Iterator it = begin(); it != end(); ++it) {
        stream << *it;
    }

    return stream;
}

template <typename T, typename Allocator>
List<T, Allocator>::Node::Node(const T& value) {
    this->value = value; 
    this->next = nullptr;
}

template <typename T, typename Allocator>
List<T, Allocator>::Node::Node(const T& value, Node* next) {
    this->value = value; 
    this->next = next;
}

template <typename T, typename Allocator>
List<T, Allocator>::Iterator::Iterator(Node& node): current_node_ptr(std::addressof(node)) {}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator=(Node* node_ptr) {
    current_node_ptr = node_ptr;
    return *this;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator++() {
    if (current_node_ptr) {
        current_node_ptr = current_node_ptr->next;
    }
    return *this;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator& List<T, Allocator>::Iterator::operator++(int) {
    Iterator iterator = *this;
    ++*this;
    return iterator;
}

template <typename T, typename Allocator>
bool List<T, Allocator>::Iterator::operator!=(const Iterator& iterator) const {
    return current_node_ptr != iterator.current_node_ptr;
}

template <typename T, typename Allocator>
bool List<T, Allocator>::Iterator::operator==(const Iterator& iterator) const {
    return current_node_ptr == iterator.current_node_ptr;
}

template <typename T, typename Allocator>
T& List<T, Allocator>::Iterator::operator*() {
    return current_node_ptr->value;
}

template <typename T, typename Allocator>
const T& List<T, Allocator>::Iterator::operator*() const {
    return current_node_ptr->value;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator List<T, Allocator>::begin() const {
    Iterator iter(*head_ptr);
    return iter;
}

template <typename T, typename Allocator>
typename List<T, Allocator>::Iterator List<T, Allocator>::end() const {
    Iterator iter(*block_element_ptr);
    return iter;
}
