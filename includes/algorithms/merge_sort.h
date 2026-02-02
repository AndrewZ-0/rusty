#pragma once

#include <scalars/scalars.h>
#include <compounds/vec.h>

template<typename T, usize L>
void merge_sort(T(&arr)[L]);

template<typename T>
void merge_sort(T *arr, usize len);

template<typename T>
void merge_sort(Vec<T> &arr);

template<typename T>
void merge_sort(List<T> &lst);

#include "merge_sort.tpp"