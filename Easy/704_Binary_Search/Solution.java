import java.util.*;


public class Solution {
    int binSearch(int[] nums, int target, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] <= target) {
                return binSearch(nums, target, mid + 1, right);
            } else if (nums[mid] >= target) {
                return binSearch(nums, target, left, mid - 1);
            }
        }

        return -1;
    }

    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        return binSearch(nums, target, left, right);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {-1, 0, 3, 5, 9, 12};
        int target1 = 9;
        System.out.println(solution.search(nums1, target1)); // Output: 4

        // test cases 1
        int[] nums2 = {-1, 0, 3, 5, 9, 12};
        int target2 = 2;
        System.out.println(solution.search(nums2, target2)); // Output: -1
    }
}