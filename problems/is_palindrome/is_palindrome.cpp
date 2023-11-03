#include <iostream>

using namespace std;

bool isPalindrome(string);

int main() {
    string phrase = "racecas";
    cout << boolalpha << isPalindrome(phrase) << endl;
    return 0;
}

bool isPalindrome(string phrase) {
    const int SIZE = phrase.length();
    int left = 0, right = SIZE - 1;
    for(int i = 0; i < SIZE; i++){
        if(phrase[left] != phrase[right]){
            return false;
        }
        left++, right--;
        if(left == right){
            break;
        }
    }
    return true;
}