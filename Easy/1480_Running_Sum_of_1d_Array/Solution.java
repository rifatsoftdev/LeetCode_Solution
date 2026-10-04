import java.util.*;


public class Solution {
    public int[] runningSum(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 3, 4};
        int[] result1 = solution.runningSum(nums1);
        System.out.println(Arrays.toString(result1));

        // test cases 2
        int[] nums2 = {1, 1, 1, 1};
        int[] result2 = solution.runningSum(nums2);
        System.out.println(Arrays.toString(result2));
    }
}