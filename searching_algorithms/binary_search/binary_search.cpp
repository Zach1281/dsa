#include <iostream>

int binarySearch(int*, int, int);
void printArr(int*, int);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 10, 15, 20, 225};
    const int SIZE = sizeof(arr) / sizeof(int);
    printArr(arr, SIZE);
    std::cout << binarySearch(arr, SIZE, -8) << std::endl;
    return 0;
}

// remember, only works on sorted arrays
// it splits the array in half using two pointers on starting from the beginning and one from the end
// on init, low will be declared as the 0 index and high will be the max index
// each loop will find the midpoint between these two pointers
// set the midVal variable to the midpoint element
// then check if midVal equals the search value or if not the search value check if the search value is higher or lower than the middle element
// if higher, we abandon the low pointer and set it to the midpoint index + 1 (because the midpoint has already been checked)
// if lower, we abandon the high pointer and set it to the midpoint index -1 (midpoint has been checked)
// if anything else happens (which is shouldn't we get a return -1
// all this while the low pointer is only less than or equal to the high pointer 
// once they swap positions we quit the loop and say that the value is not inside the array

// worst case time complexity is O(log(n)), space complexity is O(1) because you're not scaling your memory usage on the input
// you define low, high, mid and midval each time no matter the size of the array, you're also not allocating memory for a new array
// you're operating on the same array, just moving the two pointers around on the array, making subarrays along the way

int binarySearch(int* arr, int length, int needle) {
    int low = 0, high = length - 1;
    
    do {
        int mid = (low + high) / 2;
        int midVal = arr[mid];
        if(midVal == needle) {
            return midVal;
        } else if(needle < midVal) {
            high = mid - 1;
        } else if(needle > midVal) {
            low = mid + 1;
        } else {
            return -1; 
        }
    } while(low <= high);

    return -1;
}

void printArr(int* arr, int length) {
    for(int i = 0; i < length; i++){
        if(i == length - 1) {
            std::cout << arr[i] << std::endl;
        } else {
            std::cout << arr[i] << ", ";
        }
    }
}