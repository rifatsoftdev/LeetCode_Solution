#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

House Robber (Memoization (Top-Down)):
    1. Use a memoization table to store the results of subproblems and avoid redundant calculations.
    2. For each house, the robber has two choices: rob the current house and move to the house two steps back, or skip the current house and move to the previous house.
    3. The recursive relation is: `rob(i) = max(nums[i] + rob(i - 2), rob(i - 1))`.
    4. Base cases: if the index is less than 0, return 0.

Time Complexity: O(n)
Space Complexity: O(n)

*/

// class Solution {
// private:
//     int robHelper(int i, vector<int>& nums, vector<int>& memo) {
//         if (i < 0) return 0; // no house left
//         if (memo[i] != -1) return memo[i]; // already calculated

//         // pick current house or skip
//         int pick = nums[i] + robHelper(i - 2, nums, memo);
//         int skip = robHelper(i - 1, nums, memo);

//         memo[i] = max(pick, skip);
//         return memo[i];
//     }

// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> memo(n, -1);
//         return robHelper(n - 1, nums, memo);
//     }
// };




/* ================================================================================
Solution 2:

House Robber (Tabulation (Bottom-Up)):
    1. Build a DP table bottom-up to store the maximum amount that can be robbed up to each house.
    2. The state transition is:
        dp[i] = max(nums[i] + dp[i-2], dp[i-1])

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,2,3,1};
    cout << solution.rob(nums1) << endl;

    vector<int> nums2 = {2,7,9,3,1};
    cout << solution.rob(nums2) << endl;

    return 0;
}