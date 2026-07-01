

public class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] ans = new int[2 * n];

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 1};
        int[] result1 = solution.getConcatenation(nums1);
        for (int num : result1) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        // test cases 2
        int[] nums2 = {1, 3, 2, 1};
        int[] result2 = solution.getConcatenation(nums2);
        for (int num : result2) {
            System.out.print(num + " ");
        }
        System.out.println();
        
    }
}