

public class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {

            if (nums[i] == target) {
                ans = Math.min(ans, Math.abs(i - start));
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 3, 4, 5};
        System.out.println(solution.getMinDistance(nums1, 5, 3)); // Expected: 1

        // test cases 2
        int[] nums2 = {1};
        System.out.println(solution.getMinDistance(nums2, 1, 0)); // Expected: 0

        // test cases 3
        int[] nums3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        System.out.println(solution.getMinDistance(nums3, 1, 0)); // Expected: 0
    }
}