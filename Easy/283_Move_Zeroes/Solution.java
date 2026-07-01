

public class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int start = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                int tmp = nums[start];
                nums[start] = nums[i];
                nums[i] = tmp;
                start += 1;
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {0, 1, 0, 3, 12};
        solution.moveZeroes(nums1);
        for (int num : nums1) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        // test cases 2
        int[] nums2 = {0};
        solution.moveZeroes(nums2);
        for (int num : nums2) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        
    }
}