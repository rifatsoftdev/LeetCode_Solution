

public class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long count = 0;
        long consecutiveZeros = 0;

        for (int num : nums) {
            if (num == 0) {
                consecutiveZeros++;
                count += consecutiveZeros;
            } else {
                consecutiveZeros = 0;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,3,0,0,2,0,0,4};
        System.out.println(solution.zeroFilledSubarray(nums1)); // Output: 6

        // test cases 2
        int[] nums2 = {0,0,0,2,0,0};
        System.out.println(solution.zeroFilledSubarray(nums2)); // Output: 10

        // test cases 3
        int[] nums3 = {2,10,2019};
        System.out.println(solution.zeroFilledSubarray(nums3)); // Output: 0
        
    }
}