import java.util.Arrays;


public class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);

        int ans = 0;
        int cnt = 0;

        for (int i = cost.length - 1; i >= 0; i--) {
            cnt++;

            if (cnt % 3 != 0) {
                ans += cost[i];
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] cost1 = {1, 2, 3};
        System.out.println(solution.minimumCost(cost1)); // Output: 5

        // test cases 2
        int[] cost2 = {6, 5, 7, 9, 2, 2};
        System.out.println(solution.minimumCost(cost2)); // Output: 23

        // test cases 3
        int[] cost3 = {5, 5};
        System.out.println(solution.minimumCost(cost3)); // Output: 10
        
    }
}