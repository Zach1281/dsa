#include <iostream>
#include <algorithm>
// #include <random>

using namespace std;

/*
    -- CONTAINS DUPLICATE --
    given an integer array, return true of any value appears at least twice in the array
    return falce if every element is distinct
*/

bool containsDuplicate(int *, int);

int main()
{
    // create an array with a random size between 0 - 100
    const int SIZE = rand() % 100;
    int *array = new int[SIZE];

    // fill array with numbers between 0 - 200
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 250000;
    }

    // print array for verification
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            cout << array[i] << endl;
            break;
        }
        cout << array[i] << ", ";
    }

    cout << "Is there a duplicated number in the array?" << endl;
    if (containsDuplicate(array, SIZE))
    {
        cout << "Yes!" << endl;
        return 0;
    }
    cout << "No :(" << endl;

    array = nullptr;
    delete array;
    return 0;
}

bool containsDuplicate(int *arr, int SIZE)
{
    unordered_map<int, int> map;
    for (int i = 0; i < SIZE; i++)
    {
        if (map[arr[i]] == true)
        {
            return true;
        }
        map[arr[i]] = true;
    }
    return false;
}
