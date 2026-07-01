

public class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }

        int start = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                int tmp = nums[start];
                nums[start] = nums[i];
                nums[i] = tmp;
                start += 1;
            }
        }

        return nums;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 2, 1, 1, 0};
        int[] result1 = solution.applyOperations(nums1);
        for (int num : result1) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        // test cases 2
        int[] nums2 = {0, 1};
        int[] result2 = solution.applyOperations(nums2);
        for (int num : result2) {
            System.out.print(num + " ");
        }
        System.out.println();
        
    }
}