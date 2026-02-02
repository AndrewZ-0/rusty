#pragma once

#include <scalars/scalars.h>
#include <compounds/vec.h>

template<typename T, usize L>
void insertion_sort(T(&arr)[L]);

template<typename T>
void insertion_sort(Vec<T> &arr);

template<typename T>
void insertion_sort(List<T> &lst);

#include "insertion_sort.tpp"