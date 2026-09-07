import java.util.*;


public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        double maxSum = 0;

        for (int i = 0; i < k; ++i) {
            maxSum += nums[i];
        }

        double currentSum = maxSum;

        for (int i = k; i < n; ++i) {
            currentSum += nums[i] - nums[i - k];
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum / k;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 12, -5, -6, 50, 3};
        int k1 = 4;
        System.out.println(solution.findMaxAverage(nums1, k1));

        // test cases 2
        int[] nums2 = {5};
        int k2 = 1;
        System.out.println(solution.findMaxAverage(nums2, k2));
    }
}