#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Fibonacci Number (Recursion):
    1. Use recursion to calculate the Fibonacci number.

Time Complexity: O(2^n)
Space Complexity: O(n) (due to the call stack)

Note: This approach is inefficient for large values of n due to the exponential growth of the number of function calls. It is not recommended for large inputs.
*/

// class Solution {
// public:
//     int fib(int n) {
//         // base case
//         if (n <= 1) return n;

//         return fib(n-1) + fib(n-2);
//     }
// };




/* ================================================================================
Solution 2:

Fibonacci Number (DP - Memoization):
    1. Use a helper function `memo` to perform the recursive calculation with memoization.
    2. Create a vector `dp` to store the results of previously computed Fibonacci numbers.
    3. In the `memo` function, check if the Fibonacci number for `n` has already been computed (i.e., if `dp[n]` is not -1). If it has, return the stored value.
    4. If it has not been computed, calculate it recursively and store the result in `dp[n]` before returning it.

Time Complexity: O(n) (each Fibonacci number from 0 to n is computed at most once)
Space Complexity: O(n) (due to the memoization array and the call stack)

Note: This approach is more efficient than the pure recursive solution, but it still uses O(n) space due to the call stack. For large values of n, this could lead to a stack overflow. The tabulation approach (Solution 3) can be used to avoid this issue.
*/

// class Solution {
// private:
//     int memo(int n, vector<int>& dp) {
//         // base case
//         if (n <= 1) return n;
//         // recursive case
//         if (dp[n] != -1) return dp[n];
//         dp[n] = memo(n-1, dp) + memo(n-2, dp);

//         return dp[n];
//     }

// public:
//     int fib(int n) {
//         vector<int> dp(n + 1, -1);
//         return memo(n, dp);
//     }
// };




/* ================================================================================
Solution 3:

Fibonacci Number (DP - Tabulation):
    1. Use an iterative approach to fill a vector `dp` where `dp[i]` represents the Fibonacci number for `i`.
    2. Initialize the base cases: `dp[0] = 0` and `dp[1] = 1`.
    3. Use a loop to fill the `dp` vector from index 2 to `n`, where each entry is the sum of the two preceding entries.
    4. Return `dp[n]` as the result.

Time Complexity: O(n) (each Fibonacci number from 0 to n is computed once)
Space Complexity: O(n) (due to the dp array)

Note: This approach is efficient and avoids the issues of stack overflow associated with the recursive approach. However, it still uses O(n) space. An optimized version can be implemented using O(1) space by only keeping track of the last two computed Fibonacci numbers instead of the entire dp array.
*/

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.fib(2) << endl;
    cout << solution.fib(3) << endl;
    cout << solution.fib(4) << endl;

    return 0;
}