import java.util.*;


public class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (i == sumFoDigit(nums[i])) {
                return i;
            }
        }

        return -1;
    }

    private int sumFoDigit(int n) {
        int ans = 0;

        while (n != 0) {
            int d = n % 10;
            ans += d;
            n /= 10;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,3,2};
        System.out.println(solution.smallestIndex(nums1));

        // test cases 2
        int[] nums2 = {1,10,11};
        System.out.println(solution.smallestIndex(nums2));

        // test cases 3
        int[] nums3 = {1,2,3};
        System.out.println(solution.smallestIndex(nums3));
        
    }
}