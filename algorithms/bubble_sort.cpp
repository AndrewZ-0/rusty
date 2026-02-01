#include "../scalars/scalars.h"
#include "../compounds/vec.cpp"

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

template<typename T, usize L>
void bubble_sort(Vec<T, L> &arr) {
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

int main() {
    int arr[4] = {1, 5, 2, -1};
    bubble_sort(arr);

    return 0;
}