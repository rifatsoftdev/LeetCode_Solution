#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Optimal Solution (Expand Around Center):
    1. For each character in the string, consider it as a potential center of a palindrome.
    2. Since palindromes can be of odd length (one center character) or even length (two center characters), expand outwards from the center as long as the characters match.
    3. Keep track of the maximum length found and the corresponding start and end indices.
    4. Finally, return the substring using the identified start and end positions.

Time Complexity: O(n^2) - We iterate through the string and for each character, we expand outwards, which takes O(n) in the worst case.
Space Complexity: O(1) - We only use a few variables to store the indices and lengths.
*/

class Solution {
private:
    int expand(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);     // odd
            int len2 = expand(s, i, i + 1); // even

            int len = max(len1, len2);

            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.longestPalindrome("babad") << endl;
    cout << solution.longestPalindrome("cbbd") << endl;

    return 0;
}