#include <iostream>
#include <vector>

using namespace std;

/*
    -- TWO SUM II - INPUT ARRAY IS SORTED
        same as regular two sum but the array is sorted and they want the return indices to start at 1 instead of 0
*/

vector<int> twoSum(vector<int> &, int);

int main()
{
    vector<int> input = {2, 7, 8, 9};
    int target = 9;
    vector<int> output = twoSum(input, target);
    for (auto &it : output)
    {
        cout << it << " ";
    }
    return 0;
}

// classic two pointer question, though you can answer it the same way as if it were not sorted
// it is more efficient to use two integers instead of a map
vector<int> twoSum(vector<int> &numbers, int target)
{
    int lo = 0, hi = numbers.size() - 1, sum = numbers[lo] + numbers[hi];
    while (lo < hi && target != sum)
    {
        sum = numbers[lo] + numbers[hi];
        if (target < sum)
        {
            hi--;
        }
        else if (target > sum)
        {
            lo++;
        }
    }
    return {lo + 1, hi + 1};
}
