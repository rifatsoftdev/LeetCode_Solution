

public class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxNum = 0;
        int count = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxNum = Math.max(maxNum, count);
            } else {
                count = 0;
            }
        }

        return maxNum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 1, 0, 1, 1, 1};
        System.out.println(solution.findMaxConsecutiveOnes(nums1)); // Expected output: 3

        // test cases 2
        int[] nums2 = {1, 0, 1, 1, 0, 1};
        System.out.println(solution.findMaxConsecutiveOnes(nums2)); // Expected output: 2
        
    }
}