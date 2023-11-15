#include <algorithm>
#include <iostream>

std::vector<int> intersection(int *, int, int *, int);

int main()
{
    int arr1[] = {1, 2, 3, 4, 5}, arr2[] = {0, 2, 4, 6, 8};
    const int size1 = sizeof(arr1) / sizeof(int), size2 = sizeof(arr2) / sizeof(int);
    std::vector<int> arr3 = intersection(arr1, size1, arr2, size2);
    for (int i = 0; i < arr3.size(); i++)
    {
        std::cout << arr3[i] << ", ";
    }
    return 0;
}

std::vector<int> intersection(int *arr1, int size1, int *arr2, int size2)
{
    int *largerArr = nullptr;
    int *smallerArr = nullptr;
    int size = 0;
    std::unordered_map<int, bool> map;
    std::vector<int> arr3 = {};
    if (size1 >= size2)
    {
        largerArr = arr1;
        smallerArr = arr2;
        size = size1;
    }
    else
    {
        largerArr = arr2;
        smallerArr = arr1;
        size = size2;
    }
    // insert larger array into map
    for (int i = 0; i < size; i++)
    {
        map[largerArr[i]] = true;
    }

    for (int i = 0; i < map.size(); i++)
    {
        if (map[smallerArr[i]] == true)
        {
            arr3.push_back(smallerArr[i]);
        }
    }
    return arr3;
}
