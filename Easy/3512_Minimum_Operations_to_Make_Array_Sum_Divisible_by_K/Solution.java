import java.util.*;


public class Solution {
    public int minOperations(int[] nums, int k) {
        long sum = 0;

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }

        return (int)(sum % k);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {3, 9, 7};
        int k1 = 5;
        System.out.println(solution.minOperations(nums1, k1));

        // test cases 2
        int[] nums2 = {4, 1, 3};
        int k2 = 4;
        System.out.println(solution.minOperations(nums2, k2));

        // test cases 3
        int[] nums3 = {3, 2};
        int k3 = 6;
        System.out.println(solution.minOperations(nums3, k3));
        
        
    }
}