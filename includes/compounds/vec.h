#pragma once

#include <initializer_list>
#include <iostream>

#include <scalars/scalars.h>

template<typename T>
class Vec {
public:
    Vec();
    Vec(std::initializer_list<T> lst);
    ~Vec();

    usize get_len() const;
    usize get_cap() const;

    void append(const T& val);
    template<usize L>
    void extend(const T(&vals)[L]);

    Vec<T> slice(usize a, usize b);

    Vec& operator=(const Vec& other);

    T& operator[](usize i);
    const T& operator[](usize i) const;


    friend std::ostream& operator<<(std::ostream& os, Vec& vec) {
        os << "[";
        T *pos = vec.arr;
        for (usize i = vec.len; i > 1; i--) {
            os << *pos++ << ", ";
        }
        os << *pos << "]";
        return os;
    }

private:
    T *arr = nullptr;
    usize len = 0;
    usize cap = 0;

    void grow();
    void batch_grow(usize target);
};

#include "vec.tpp"