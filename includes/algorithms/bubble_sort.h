#pragma once

#include <scalars/scalars.h>
#include <compounds/vec.h>

template<typename T, usize L>
void bubble_sort(T(&arr)[L]);

template<typename T>
void bubble_sort(Vec<T> &arr);

template<typename T>
void bubble_sort(List<T> &lst);

#include "bubble_sort.tpp"