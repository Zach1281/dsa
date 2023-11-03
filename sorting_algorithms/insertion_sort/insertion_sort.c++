#include <iostream>

void insertionSort(int *, int);
void printArr(int *, int);

int main() {
    int arr[] = {5, 4, 1, 2, 9, 3};
    const int SIZE = sizeof(arr) / sizeof(int);
    std::cout << "Unsorted Array: " << std::endl;
    printArr(arr, SIZE);
    insertionSort(arr, SIZE);
    return 0;
}

void insertionSort(int *arr, int length) {
    for(int i = 1; i < length; i++) {
        int key = arr[i];
        // insert arr[i] into the sorted subarray arr[1:i-1]
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    std::cout << "Sorted Array: " << std::endl;
    printArr(arr, length);
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