#include <scalars/scalars.h>
#include <compounds/list.h>
#include <compounds/vec.h>
#include <algorithms/insertion_sort.h>
#include <algorithms/bubble_sort.h>
#include <algorithms/merge_sort.h>

#include <iostream>

int main() {
    //int arr[] = {1, 5, 2, -1};
    //Vec<int> arr = {1, 5, 2, -1};
    List<int> arr = {1, 5, 2, -1};
    merge_sort(arr);

    //Vec<int> arr2 = arr.slice(2, 3);
    //std::cout << arr[0] << arr[1] << arr[2] << arr[3] << std::endl;
    std::cout << arr << std::endl;

    return 0;
}
