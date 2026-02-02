template<typename T, usize L>
void insertion_sort(T(&arr)[L]) {
    if (L < 2) return;

    usize i, j, largest_i;
    T temp, largest;
    for (i = L - 1; i > 0; i--) {
        largest = arr[i];
        largest_i = i;
        for (j = i; j-- > 0;) {
            if (arr[j] > largest) {
                largest = arr[j];
                largest_i = j;
            }
        }
        arr[largest_i] = arr[i];
        arr[i] = largest;
    }
}

template<typename T>
void insertion_sort(Vec<T> &arr) {
    if (arr.get_len() < 2) return;

    usize i, j, largest_i;
    T temp, largest;
    for (i = arr.get_len() - 1; i > 0; i--) {
        largest = arr[i];
        largest_i = i;
        for (j = i; j-- > 0;) {
            if (arr[j] > largest) {
                largest = arr[j];
                largest_i = j;
            }
        }
        arr[largest_i] = arr[i];
        arr[i] = largest;
    }
}

template<typename T>
void insertion_sort(List<T> &lst) {
    if (lst.get_len() < 2) return;

    usize i, j, largest_i;
    T temp, largest;
    for (i = lst.get_len() - 1; i > 0; i--) {
        largest = lst[i];
        largest_i = i;
        for (j = i; j-- > 0;) {
            if (lst[j] > largest) {
                largest = lst[j];
                largest_i = j;
            }
        }
        lst[largest_i] = lst[i];
        lst[i] = largest;
    }
}