


public class Solution {
    public int removeElement(int[] nums, int val) {
        int ans = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[ans] = nums[i];
                ans++;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {3,2,2,3};
        int val1 = 3;
        System.out.println(solution.removeElement(nums1, val1)); // Output: 2

        // test cases 2
        int[] nums2 = {0,1,2,2,3,0,4,2};
        int val2 = 2;
        System.out.println(solution.removeElement(nums2, val2)); // Output: 5
    }
}