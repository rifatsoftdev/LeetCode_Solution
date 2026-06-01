

public class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {3, 4, 5, 1, 2};
        System.out.println(solution.findMin(nums1)); // Expected: 1

        // test cases 2
        int[] nums2 = {4, 5, 6, 7, 0, 1, 2};
        System.out.println(solution.findMin(nums2)); // Expected: 0

        // test cases 3
        int[] nums3 = {11, 13, 15, 17};
        System.out.println(solution.findMin(nums3)); // Expected: 11
        
    }
}