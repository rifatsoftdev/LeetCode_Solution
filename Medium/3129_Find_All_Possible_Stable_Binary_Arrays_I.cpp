#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find All Possible Stable Binary Arrays I (Dynamic Programming):
    1. Use a 3D DP table `dp[i][j][k]` where `i` is the number of zeros used, `j` is the number of ones used, and `k` is the last digit placed (0 or 1).
    2. Initialize base cases for arrays containing only zeros or only ones up to the given `limit`.
    3. For each state `(i, j)`, the number of stable arrays ending in 0 is the sum of stable arrays of size `(i-1, j)` ending in 0 or 1, minus those that would violate the `limit` (more than `limit` consecutive zeros).
    4. Similarly, calculate the number of stable arrays ending in 1 by considering the state `(i, j-1)` and subtracting invalid sequences of ones.
    5. The result is the sum of stable arrays of size `(zero, one)` ending in either 0 or 1, modulo 10^9 + 7.

Time Complexity: O(zero * one)
Space Complexity: O(zero * one)
*/

#define MOD 1000000007

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<array<int, 2>>> dp(zero + 1, vector<array<int, 2>>(one + 1, {0, 0}));

        for (int i = 1; i <= min(zero, limit); i++) dp[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                long long val0 = (0LL + dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                if (i > limit) val0 = (val0 - dp[i - limit - 1][j][1] + MOD) % MOD;
                dp[i][j][0] = val0;
                long long val1 = (0LL + dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                if (j > limit) val1 = (val1 - dp[i][j - limit - 1][0] + MOD) % MOD;
                dp[i][j][1] = val1;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.numberOfStableArrays(2, 3, 1) << endl;
    cout << solution.numberOfStableArrays(5, 0, 3) << endl;
    cout << solution.numberOfStableArrays(3, 1, 2) << endl;

    return 0;
}