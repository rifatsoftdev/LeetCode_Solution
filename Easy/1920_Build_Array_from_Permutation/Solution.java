import java.util.*;


public class Solution {
    public int[] buildArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {0,2,1,5,3,4};
        int[] result1 = solution.buildArray(nums1);
        System.out.println(result1.toString());

        // test cases 2
        int[] nums2 = {5,0,1,2,3,4};
        int[] result2 = solution.buildArray(nums2);
        System.out.println(result2.toString());
        
    }
}