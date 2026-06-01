

public class Solution {
    int maxNum(int[] nums) {
        int m = 0;
        for (int i : nums)  m = Math.max(m, i);
        return m;
    }

    public boolean isGood(int[] nums) {
        int maxVal = maxNum(nums);

        if (nums.length != maxVal + 1) return false;

        java.util.Arrays.sort(nums);
        int[] expected = new int[maxVal + 1];

        for (int i = 0; i < maxVal; i++) {
            expected[i] = i + 1;
        }
        expected[maxVal] = maxVal;

        return java.util.Arrays.equals(nums, expected);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {2, 1, 3};
        System.out.println(solution.isGood(nums1));

        // test cases 2
        int[] nums2 = {1, 3, 3, 2};
        System.out.println(solution.isGood(nums2));

        // test cases 3
        int[] nums3 = {1, 1};
        System.out.println(solution.isGood(nums3));

        // test cases 4
        int[] nums4 = {3, 4, 4, 1, 2, 1};
        System.out.println(solution.isGood(nums4));
        
    }
}