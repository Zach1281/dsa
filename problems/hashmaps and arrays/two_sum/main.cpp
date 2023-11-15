#include <iostream>
#include <algorithm>

using namespace std;

/*
    -- TWO SUM --
    given an array of integers and an integer target, return the indices of the two numbers such that
    they add up to the target
    each solution will have exactly one solution, the same element must not be used twice
    return indices in any order
*/

vector<int> twoSum(vector<int> &, int);

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 17;

    vector<int> arr = twoSum(nums, target);
    const int SIZE = 2;

    cout << "[";
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            cout << arr[i];
            break;
        }
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // map w/ keys veing nums and values being indexes
    // must find the complement of another value n's complement = target - n
    // if it exists in the map then return true otherwise false
    const int SIZE = nums.size();
    vector<int> arr;
    unordered_map<int, int> map;
    for (int i = 0; i < SIZE; i++)
    {
        // for each num in array, add to map with value being the index
        int complement = target - nums[i];
        if (map.count(complement) && map[complement] != i)
        {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}