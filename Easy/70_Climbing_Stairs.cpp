#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Climbing Stairs (DP - Tabulation):
    1. This problem can be broken down into subproblems: to reach the nth step, you can either come from the (n-1)th step (by taking 1 step) or from the (n-2)th step (by taking 2 steps).
    2. Therefore, the total number of ways to reach the nth step is the sum of the ways to reach the (n-1)th and (n-2)th steps: `dp[n] = dp[n-1] + dp[n-2]`.
    3. Initialize base cases: `dp[1] = 1` and `dp[2] = 2`.
    4. Use a loop to fill the `dp` array up to `n`.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int state = 3; state <= n; state++) {
            dp[state] = dp[state - 1] + dp[state - 2];
        }

        return dp[n];
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.climbStairs(2) << endl;
    cout << solution.climbStairs(3) << endl;

    return 0;
}