


public class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        int count = 0;

        for (int i = 0; i < nums1.length; ++i) {
            for (int j = 0; j < nums2.length; ++j) {
                if (nums1[i] % (nums2[j] * k) == 0) {
                    count++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1_1 = {1, 3, 4};
        int[] nums2_1 = {1, 3, 4};
        int k1 = 1;
        System.out.println(solution.numberOfPairs(nums1_1, nums2_1, k1)); // Output: 5
        
        // test cases 2
        int[] nums1_2 = {1, 2, 4, 12};
        int[] nums2_2 = {2, 4};
        int k2 = 3;
        System.out.println(solution.numberOfPairs(nums1_2, nums2_2, k2)); // Output: 2
        
    }
}