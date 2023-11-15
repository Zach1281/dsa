#include "merge_sort.h"

int main()
{
    int arr[] = {5, 4, 1, 3, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: \n";
    display(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted Array: \n";
    display(arr, size);
    return 0;
}