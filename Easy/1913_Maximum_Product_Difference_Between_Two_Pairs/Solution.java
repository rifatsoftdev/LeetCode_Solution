

public class Solution {
    public int maxProductDifference(int[] nums) {
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;

        for (int n : nums) {
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max2 = n;
            }

            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }

        return (max1 * max2) - (min1 * min2);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {5, 6, 2, 7, 4};
        System.out.println(solution.maxProductDifference(nums1)); // Expected: 34
        
        // test cases 2
        int[] nums2 = {4, 2, 5, 9, 7, 4, 8};
        System.out.println(solution.maxProductDifference(nums2)); // Expected: 64
        
    }
}