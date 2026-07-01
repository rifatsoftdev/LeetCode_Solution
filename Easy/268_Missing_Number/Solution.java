


class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n * (n + 1) / 2;

        for (int i = 0; i < n; i++) {
            sum -= nums[i];
        }

        return sum;  
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {3, 0, 1};
        System.out.println(solution.missingNumber(nums1)); // Expected: 2
        
        // test cases 2
        int[] nums2 = {0, 1};
        System.out.println(solution.missingNumber(nums2)); // Expected: 2

        // test cases 3
        int[] nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
        System.out.println(solution.missingNumber(nums3)); // Expected: 8
        
    }
}
