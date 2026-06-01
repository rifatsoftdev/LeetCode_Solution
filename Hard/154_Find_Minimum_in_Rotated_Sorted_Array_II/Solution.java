

public class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if ((nums[mid] < nums[right])) {
                right = mid;
            } else {
                right--;
            }
        }

        return nums[left];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,3,5};
        System.out.println(solution.findMin(nums1));

        // test cases 2
        int[] nums2 = {2,2,2,0,1};
        System.out.println(solution.findMin(nums2));
    }
}