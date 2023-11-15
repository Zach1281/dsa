#include <iostream>
#include <algorithm>

using namespace std;

/*
    -- TOP K FREQUENT ELEMENTS --
    given an integer array and an integer
    return the most frequent elements
        can be returned in any order
*/

vector<int> topKFrequent(vector<int> &, int);
void sort(unordered_map<int, int> &);

bool cmp(pair<int, int> &a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> top = topKFrequent(arr, k);
    cout << "[";
    for (int i = 0; i < top.size(); i++)
    {
        if (i == top.size() - 1)
        {
            cout << top[i];
            break;
        }
        cout << top[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}

/*
    -- STRATEGY --
        - Data Structure : map to group data together
        - return a vector of the top k most frequent elements
        1. gather the relevant data, so key being the element in the array and value being the frequency of that number
        2. find the top k most frequent elements from the map
            1. loop through the map to get all of the keys
            2. compare the values for each key to find the top k frequencies
*/
vector<int> topKFrequent(vector<int> &nums, int k)
{
    int SIZE = nums.size();
    unordered_map<int, int> map;
    vector<int> topNums;

    // group the number with their frequency
    for (int i = 0; i < SIZE; i++)
    {
        map[nums[i]]++;
    }

    // arraylist of pairs where the pairs are the number and it's frequency in the nums array
    vector<pair<int, int>> freqKey;
    for (auto it : map)
    {
        freqKey.push_back(make_pair(it.first, it.second));
    }
    // sort using custom comparison function where it sorts in decending order on the frequency of each pair
    sort(freqKey.begin(), freqKey.end(), cmp);
    // loop through the frequencyKey vector of pairs
    // in order to stay within bounds, we either loop through the whole vector if k is larger than the size of the freqKey vector
    // or if k is smaller, return the topNums vector
    for (auto it : freqKey)
    {
        if (k == 0)
        {
            return topNums;
        }
        topNums.push_back(it.first);
        k--;
    }
    return topNums;
}
