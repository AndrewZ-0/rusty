#include <initializer_list>
#include <iostream>

#include "scalars.h"
#include "iter.cpp"

template<typename T>
struct Node {
    T val;
    Node* nxt = nullptr;
    Node* prev = nullptr;
};

template<typename T>
class List {
public:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    usize len = 0;

    List() = default;
    List(std::initializer_list<T> lst) {
        for (const T& e : lst) append(e);
    }
    List(const List& other) {
        for (Node<T>* curr = other.head; curr; curr = curr->nxt)
            append(curr->val);
    }
    List(List&& other) noexcept: head(other.head), tail(other.tail), len(other.len) {
        other.head = other.tail = nullptr;
        other.len = 0;
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            for (Node<T>* curr = other.head; curr; curr = curr->nxt)
                append(curr->val);
        }
        return *this;
    }

    ~List() {clear();}

    void append(const T& val) {
        Node<T>* n = new Node<T>;
        n->val = val;
        n->prev = tail;

        if (tail) {
            tail->nxt = n;
            tail = n;
        } else {
            head = tail = n;
        }
        len++;
    }
    void prepend(const T& val) {
        Node<T>* n = new Node<T>;
        n->val = val;
        n->nxt = head;

        if (head) {
            head->prev = n;
            head = n;
        } else {
            head = tail = n;
        }
        len++;
    }

    T operator[](usize index) {
        if (index >= len) throw std::out_of_range("Index out of bounds");
        
        Node<T>* curr;
        if (index < len >> 1) {
            curr = head;
            for (usize i = 0; i < index; i++) curr = curr->nxt;
        } else {
            curr = tail;
            for (usize i = len - 1; i > index; i--) curr = curr->prev;
        }
        return curr->val;
    }
    T operator[](usize index) const {
        if (index >= len) throw std::out_of_range("Index out of bounds");
        
        Node<T>* curr;
        if (index < len >> 1) {
            curr = head;
            for (usize i = 0; i < index; i++) curr = curr->nxt;
        } else {
            curr = tail;
            for (usize i = len - 1; i > index; i--) curr = curr->prev;
        }
        return curr->val;
    }

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
    void clear() {
        Node<T>* curr = head;
        while (curr) {
            Node<T>* nxt = curr->nxt;
            delete curr;
            curr = nxt;
        }
        head = tail = nullptr;
        len = 0;
    }
};
