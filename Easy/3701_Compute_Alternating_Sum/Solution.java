import java.util.*;


public class Solution {
    public int alternatingSum(int[] nums) {
        int result = 0;

        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                result += nums[i];
            } else {
                result -= nums[i];
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 3, 5, 7};
        System.out.println(solution.alternatingSum(nums1)); // Output: -4

        // test cases 2
        int[] nums2 = {100};
        System.out.println(solution.alternatingSum(nums2)); // Output: 100
        
    }
}