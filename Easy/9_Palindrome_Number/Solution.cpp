#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long rev = 0;
        int temp = x;

        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }

        return x == rev;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.isPalindrome(121) << endl;
    cout << solution.isPalindrome(-121) << endl;
    cout << solution.isPalindrome(10) << endl;

    return 0;
}