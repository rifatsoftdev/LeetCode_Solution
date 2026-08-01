


public class Solution {
    public int sumOfSquares(int[] nums) {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                ans += nums[i] * nums[i];
            }
        }
        
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,2,3,4};
        System.out.println(solution.sumOfSquares(nums1));

        // test cases 2
        int[] nums2 = {2,7,1,19,18,3};
        System.out.println(solution.sumOfSquares(nums2));
        
    }
}