#include <iostream>
#include <algorithm>

using namespace std;

/*
    -- VALID ANAGRAM --
    given two strings, return true if one is an anagram of the other
    return false otherwise
*/

bool isAnagram(string, string);

int main()
{
    string s = "anagram", t = "nagarom";

    cout << "Are " << s << " and " << t << " anagrams?" << endl;
    if (isAnagram(s, t))
    {
        cout << "Yes they are!" << endl;
        return 0;
    }
    cout << "No :(" << endl;
    return 0;
}

bool isAnagram(string s, string t)
{
    const int sSize = s.size();
    const int tSize = t.size();
    if (sSize != tSize)
    {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < sSize; i++)
    {
        if (s[i] != t[i])
        {
            return false;
        }
    }

    return true;
}