

public class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int fast = 0;
        int last = n - 1;
        int idx = n - 1;
        int[] result = new int[n];

        while (fast <= last) {
            int fast_sq = nums[fast] * nums[fast];
            int last_sq = nums[last] * nums[last];

            if (fast_sq < last_sq) {
                result[idx] = last_sq;
                last--;
            } else {
                result[idx] = fast_sq;
                fast++;
            }
            idx--;
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {-4, -1, 0, 3, 10};
        int[] result1 = solution.sortedSquares(nums1);
        for (int n : result1) System.out.print(n + " ");
        System.out.println();
        
        // test cases 2
        int[] nums2 = {-7, -3, 2, 3, 11};
        int[] result2 = solution.sortedSquares(nums2);
        for (int n : result2) System.out.print(n + " ");
        System.out.println();
        
    }
}