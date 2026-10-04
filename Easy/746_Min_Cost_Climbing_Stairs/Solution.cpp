#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> cost1 = {10,15,20};
    int result1 = solution.minCostClimbingStairs(cost1);
    cout << result1 << endl;

    // test cases 2
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    int result2 = solution.minCostClimbingStairs(cost2);
    cout << result2 << endl;

    return 0;
}