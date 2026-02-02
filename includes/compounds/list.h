#pragma once

#include <initializer_list>
#include <iostream>

#include <scalars/scalars.h>
#include <compounds/iter.h>

template<typename T>
struct Node {
    T val;
    Node* nxt = nullptr;
    Node* prev = nullptr;
};

template<typename T>
class List {
public:
    List();
    List(std::initializer_list<T> lst);
    List(const List& other);
    List(List&& other) noexcept;

    usize get_len() const;

    List& operator=(const List& other);

    ~List();

    void append(const T& val);
    void prepend(const T& val);

    List<T> slice(usize a, usize b);

    T& operator[](usize index);
    const T& operator[](usize index) const;

    friend std::ostream& operator<<(std::ostream& os, List& lst) {
        os << "[";
        Node<T> *curr = lst.head;
        for (usize i = lst.len; i > 1; i--) {
            os << curr->val << ",";
            curr = curr->nxt;
        }
        if (lst.tail) os << lst.tail->val;
        os << "]";
        return os;
    }

private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    usize len = 0;

    void clear();
};

#include "list.tpp"