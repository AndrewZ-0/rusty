#include <scalars/scalars.h>
#include <compounds/list.h>
#include <compounds/vec.h>
#include <algorithms/bubble_sort.h>

#include <iostream>

int main() {
    Vec<int> arr = {1, 5, 2, -1};
    bubble_sort(arr);

    std::cout << arr << std::endl;

    return 0;
}
