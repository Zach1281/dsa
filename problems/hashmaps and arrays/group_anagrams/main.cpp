#include <iostream>
#include <algorithm>

using namespace std;

/*
    -- GROUP ANAGRAMS --
    given an array of strings, group the anagrams together
    an anagram is a word or phrase formed by rearranging the order of the letters to make a different word
*/

vector<vector<string>> groupAnagrams(vector<string> &);

int main()
{
    vector<string> strings = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> anagrams = groupAnagrams(strings);
    cout << "[";
    for (int i = 0; i < anagrams.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < anagrams[i].size(); j++)
        {
            if (i == anagrams.size() - 1)
            {
                cout << anagrams[i][j] << endl;
                break;
            }
            cout << anagrams[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    return 0;
}

// sort all strings within the arraylist
// group all strings that match
// loop through the strings arraylist, sort each string and insert them into the unordered map
// the key will be the sorted string, the value will be an arraylist of original strings
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    const int SIZE = strs.size();
    unordered_map<string, vector<string>> map;
    vector<vector<string>> anagrams;

    for (int i = 0; i < SIZE; i++)
    {
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        map[strs[i]].push_back(temp);
    }
    for (auto values : map)
    {
        anagrams.push_back(values.second);
    }
    return anagrams;
}