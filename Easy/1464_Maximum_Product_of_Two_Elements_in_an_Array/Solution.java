import java.util.*;


public class Solution {
    public int maxProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {3, 4, 5, 2};
        System.out.println(solution.maxProduct(nums1)); // Output: 12

        // test cases 2
        int[] nums2 = {1, 5, 4, 5};
        System.out.println(solution.maxProduct(nums2)); // Output: 16
        
    }
}