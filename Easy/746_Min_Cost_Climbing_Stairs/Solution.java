import java.util.*;


public class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int dp[] = new int[n + 1];

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + Math.min(dp[i-1], dp[i-2]);
        }

        return Math.min(dp[n-1], dp[n-2]);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] cost1 = {10, 15, 20};
        int result1 = solution.minCostClimbingStairs(cost1);
        System.out.println(result1);

        // test cases 2
        int[] cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        int result2 = solution.minCostClimbingStairs(cost2);
        System.out.println(result2);
        
    }
}