#include <iostream>
#include <algorithm>

using namespace std;

/*
 -- PRODUCT OF ARRAY EXCEPT SELF --
    given an integer array nums, return an array such that ans[i] is equal to the product of all elements of the integer array except nums[i]
    run in linear time
*/

vector<int> productExceptSelf(vector<int> &);

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> answer = productExceptSelf(nums);
    cout << "[";
    for (int i = 0; i < answer.size(); i++)
    {
        if (i == answer.size() - 1)
        {
            cout << answer[i];
            break;
        }
        cout << answer[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    const int SIZE = nums.size();
    vector<int> output(SIZE);
    output[0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        output[i] = output[i - 1] * nums[i - 1];
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            cout << output[i] << endl;
            break;
        }
        cout << output[i] << ", ";
    }
    int right = 1;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        cout << "\nright: " << right << endl;
        output[i] *= right;
        cout << output[i] << ", ";
        right *= nums[i];
    }
    cout << endl;
    return output;
}