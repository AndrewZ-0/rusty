#include <scalars/scalars.h>
#include <compounds/list.h>
#include <compounds/vec.h>
#include <algorithms/bubble_sort.h>
#include <algorithms/insertion_sort.h>

#include <iostream>

int main() {
    List<int> arr = {1, 5, 2, -1};
    insertion_sort(arr);

    std::cout << arr << std::endl;

    return 0;
}
