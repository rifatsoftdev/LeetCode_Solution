

public class Solution {
    public int minElement(int[] nums) {
        int minSum = Integer.MAX_VALUE;

        for (int n : nums) {
            int ds = 0;

            while (n != 0) {
                int d = n % 10;
                ds += d;
                n /= 10;
            }

            minSum = Math.min(minSum, ds);
        }

        return minSum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // test cases 1
        int[] nums1 = {10,12,13,14};
        System.out.println(solution.minElement(nums1));

        // test cases 2
        int[] nums2 = {1,2,3,4};
        System.out.println(solution.minElement(nums2));

        // test cases 3
        int[] nums3 = {999,19,199};
        System.out.println(solution.minElement(nums3));
    }
}