#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Longest Palindrome:
    1. Count the frequency of each character in the string (both lowercase and uppercase).
    2. For each character frequency, if it is even, all occurrences can be part of the palindrome.
    3. If the frequency is odd, we can use `frequency - 1` occurrences (making it even) to maintain symmetry.
    4. If there is at least one character with an odd frequency, we can place exactly one such character in the center of the palindrome.
    5. The total length is the sum of all even parts plus one if any odd frequency was encountered.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as the frequency arrays have a fixed size of 26.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (char c : s) {
            if (islower(c)) {
                lower[c - 'a']++;
            } else {
                upper[c - 'A']++;
            }
        }

        int count = 0;
        bool odd = false;

        for (int i = 0; i < 26; i++) {
            // lower
            if (lower[i] % 2 == 0) {
                count += lower[i];
            } else {
                count += lower[i] - 1;
                odd = true;
            }

            // upper
            if (upper[i] % 2 == 0) {
                count += upper[i];
            } else {
                count += upper[i] - 1;
                odd = true;
            }
        }

        return odd ? count + 1 : count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.longestPalindrome("abccccdd") << endl;
    cout << solution.longestPalindrome("a") << endl;

    return 0;
}