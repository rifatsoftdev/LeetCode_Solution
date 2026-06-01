

public class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length;
        int ans = 0;

        for (int i = 2; i < n; i++) {
            double half = nums[i-1] / 2.0;
            double sum = nums[i-2] + nums[i];

            if (sum == half) {
                ans++;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,2,1,4,1};
        System.out.println(solution.countSubarrays(nums1)); // Output: 1
    
        // test cases 2
        int[] nums2 = {1, 1, 1};
        System.out.println(solution.countSubarrays(nums2)); // Output: 0
        
    }
}