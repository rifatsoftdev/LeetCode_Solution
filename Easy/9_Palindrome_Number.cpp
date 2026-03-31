#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Palindrome Number (Reversing the Integer):
    1. If the number is negative, it cannot be a palindrome (e.g., -121 becomes 121-).
    2. Reverse the digits of the integer.
    3. Compare the reversed integer with the original integer. If they are equal, the number is a palindrome.

Time Complexity: O(log10(n)), where n is the input integer. We iterate through the digits of the number.
Space Complexity: O(1), as we only use a few variables to store the reversed number and temporary values.
*/

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