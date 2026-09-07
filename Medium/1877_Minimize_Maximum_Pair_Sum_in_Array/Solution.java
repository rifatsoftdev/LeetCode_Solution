import java.util.*;


public class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);

        int n = nums.length;
        int maxPairSum = 0;

        for (int i = 0; i < n / 2; ++i) {
            int pairSum = nums[i] + nums[n - 1 - i];
            maxPairSum = Math.max(maxPairSum, pairSum);
        }

        return maxPairSum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {3,5,2,3};
        System.out.println(solution.minPairSum(nums1)); // Output: 7

        // test cases 2
        int[] nums2 = {3,5,4,2,4,6};
        System.out.println(solution.minPairSum(nums2)); // Output: 8
        
    }
}