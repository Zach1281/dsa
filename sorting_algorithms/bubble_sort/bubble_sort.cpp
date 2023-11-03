#include <iostream>
#include <algorithm>

void bubbleSort(int*, int);
void printArr(int*, int);
void swap(int*, int, int);

int main() {
    int arr[] = {2, 3, 5, 9, 10, 12, 25, 15, 22, 1};
    const int SIZE = sizeof(arr) / sizeof(int);
    printArr(arr, SIZE);
    bubbleSort(arr, SIZE);
    return 0;
}

void printArr(int *arr, int length) {
    for(int i = 0; i < length; i++){
        if(i == length - 1) {
            std::cout << arr[i] << std::endl;
        } else {
            std::cout << arr[i] << ", ";
        }        
    }
}

void swap(int *arr, int left, int right) {
    int temp = arr[right];
    arr[right] = arr[left];
    arr[left] = temp;
}

/*
BUBBLE SORT
1. point two consecutive values in the array. (on init, start with the first two values) compare first item with the second
2. if left is greater than right, swap. otherwise, do nothing.
3. move pointers to right by one
4. repeat 1-3 until end of array, or if we reach the valuess that have already been sorted
5. move two pointers back to the first two values, execute another pass-through of the array by running 1-4 again. keep passing until we do not swap anymore
*/
void bubbleSort(int *arr, int length) {
    int unsorted_until_index = length - 1;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for(int i = 0; i < unsorted_until_index; i++) {
            if(arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                sorted = false;
            }
        }
        unsorted_until_index--;
    }
    printArr(arr, length);
}

