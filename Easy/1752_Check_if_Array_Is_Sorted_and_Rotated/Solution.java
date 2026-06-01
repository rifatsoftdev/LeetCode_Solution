

public class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {3, 4, 5, 1, 2};
        System.out.println(solution.check(nums1)); // true

        // test cases 2
        int[] nums2 = {2, 1, 3, 4};
        System.out.println(solution.check(nums2)); // false
        
        // test cases 3
        int[] nums3 = {1, 2, 3};
        System.out.println(solution.check(nums3)); // true
    }
}