#include <iostream>

using namespace std;

/*
    -- VALID PALINDROME --
        after converting to lowercase and removing all non-alphanumeric characters, reads the same backward and forward
        alphanumeric characters are letters and numbers

        given a string, return true if it is a palindrome otherwise return false
*/

bool isPalindrome(string);

int main()
{
    string s = "A man, a plao, a canal: Panama";
    cout << "Is this a palindrome?" << endl;
    if (isPalindrome(s))
    {
        cout << "Yes it is!" << endl;
        return 0;
    }
    cout << "No it is not!" << endl;
    return 0;
}

bool isPalindrome(string s)
{
    const int SIZE = s.length();
    int lo = 0, hi = SIZE - 1;

    while (lo <= hi)
    {
        if (!isalnum(s[lo]))
        {
            lo++;
            continue;
        }
        if (!isalnum(s[hi]))
        {
            hi--;
            continue;
        }
        if (tolower(s[lo]) != tolower(s[hi]))
        {
            return false;
        }
        else
        {
            lo++;
            hi--;
        }
        }
    return true;
}