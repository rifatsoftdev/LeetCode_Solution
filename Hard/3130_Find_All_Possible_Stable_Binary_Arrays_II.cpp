#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find All Possible Stable Binary Arrays II (Dynamic Programming with Prefix Sums):
    1. Define `dp[i][j][0]` as the number of stable arrays with `i` zeros and `j` ones ending in 0, and `dp[i][j][1]` ending in 1.
    2. The recurrence for `dp[i][j][0]` is the sum of all stable arrays of size `(i-1, j)` minus those that would violate the `limit` constraint (more than `limit` consecutive zeros).
    3. Specifically, `dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i-limit-1][j][1]`.
    4. The subtraction `dp[i-limit-1][j][1]` removes cases where we previously had exactly `limit` zeros and just added one more, which is only possible if the sequence before those `limit` zeros ended in a 1.
    5. Base cases are initialized for arrays containing only zeros or only ones up to the `limit`.

Time Complexity: O(zero * one)
Space Complexity: O(zero * one)
*/

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<array<long,2>>> dp(
            zero+1, vector<array<long,2>>(one+1, {0LL,0LL}));

        for (int i = 1; i <= min(zero,limit); i++) dp[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                long over0 = (i-limit >= 1) ? dp[i-limit-1][j][1] : 0;
                long over1 = (j-limit >= 1) ? dp[i][j-limit-1][0] : 0;
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] - over0 + MOD) % MOD;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1] - over1 + MOD) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.numberOfStableArrays(1, 1, 2) << endl;
    cout << solution.numberOfStableArrays(1, 2, 1) << endl;
    cout << solution.numberOfStableArrays(3, 3, 2) << endl;


    return 0;
}