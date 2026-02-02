template<typename T, usize L>
void bubble_sort(T(&arr)[L]) {
    if (L < 2) return;

    usize i, j;
    T temp;
    bool no_swap;
    for (i = L - 1; i > 0; i--) {
        no_swap = 1;
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                no_swap = 0;
            }
        }
        if (no_swap) break;
    }
}

template<typename T>
void bubble_sort(Vec<T> &arr) {
    if (arr.len < 2) return;

    usize i, j;
    T temp;
    bool no_swap;
    for (i = arr.len - 1; i > 0; i--) {
        no_swap = 1;
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                no_swap = 0;
            }
        }
        if (no_swap) break;
    }
}

template<typename T>
void bubble_sort(List<T> &lst) {
    if (lst.len < 2) return;

    usize i, j;
    T temp;
    bool no_swap;
    for (i = lst.len - 1; i > 0; i--) {
        no_swap = 1;
        for (j = 0; j < i; j++) {
            if (lst[j] > lst[j + 1]) {
                temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
                no_swap = 0;
            }
        }
        if (no_swap) break;
    }
}