#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum Number of Flips to Make the Binary String Alternating (Brute Force):
    1. For each possible rotation of the string `s`, calculate the number of flips required to make it alternating.
    2. An alternating string can start with either '0' or '1' (e.g., "0101..." or "1010...").
    3. For each rotation, compare it with both possible alternating patterns and count the mismatches.
    4. The minimum count across all rotations and both patterns is the answer.

Time Complexity: O(n^2)
Space Complexity: O(n)

Note: This approach will result in a Time Limit Exceeded (TLE) error for large inputs.
*/

// class Solution {
// public:
//     int minFlips(string s) {
//         int n = s.size();
//         int ans = INT_MAX;

//         for(int i = 0; i < n; i++) {

//             string rotated = s.substr(i) + s.substr(0, i);

//             int flip1 = 0, flip2 = 0;

//             for(int j = 0; j < n; j++) {

//                 char expected1 = (j % 2 == 0) ? '0' : '1';
//                 char expected2 = (j % 2 == 0) ? '1' : '0';

//                 if(rotated[j] != expected1) flip1++;
//                 if(rotated[j] != expected2) flip2++;
//             }

//             ans = min(ans, min(flip1, flip2));
//         }

//         return ans;
//     }
// };




/* ================================================================================
Solution 1:

Minimum Number of Flips to Make the Binary String Alternating (Sliding Window):
    1. To handle the "Type 1" operation (moving the first character to the end), concatenate the string with itself (s + s).
    2. Create two target alternating patterns of length 2*n: one starting with '0' and another starting with '1'.
    3. Use a sliding window of size `n` to traverse the concatenated string.
    4. Maintain the count of differences between the current window and both target patterns.
    5. As the window slides, subtract the difference contribution of the character leaving the window and add the contribution of the character entering it.
    6. The minimum difference encountered across all windows of size `n` is the result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        string alt1 = "", alt2 = "";

        for(int i = 0; i < 2*n; i++) {
            alt1 += (i % 2 == 0) ? '0' : '1';
            alt2 += (i % 2 == 0) ? '1' : '0';
        }

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        int l = 0;

        for(int r = 0; r < 2*n; r++) {

            if(ss[r] != alt1[r]) diff1++;
            if(ss[r] != alt2[r]) diff2++;

            if(r - l + 1 > n) {
                if(ss[l] != alt1[l]) diff1--;
                if(ss[l] != alt2[l]) diff2--;
                l++;
            }

            if(r - l + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}