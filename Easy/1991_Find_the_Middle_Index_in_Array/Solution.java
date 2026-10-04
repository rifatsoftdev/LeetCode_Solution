import java.util.*;


public class Solution {
    public int findMiddleIndex(int[] nums) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.length; i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {2,3,-1,8,4};
        System.out.println(solution.findMiddleIndex(nums1)); // Expected output: 3

        // test cases 2
        int[] nums2 = {1,-1,4};
        System.out.println(solution.findMiddleIndex(nums2)); // Expected output: 2

        // test cases 3
        int[] nums3 = {2,5};
        System.out.println(solution.findMiddleIndex(nums3)); // Expected output: -1
        
        
    }
}