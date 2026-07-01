


public class Solution {
    public int findKOr(int[] nums, int k) {
        int sum = 0;

        for (int i = 0; i < 32; i++){
            int c = 0;

            for (int val : nums) {
                if ((val & (1 << i)) != 0) c++;
            }

            if (c >= k) sum += Math.pow(2, i);
        }
        
        return sum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {7, 12, 9, 8, 9, 15};
        int k1 = 4;
        System.out.println(solution.findKOr(nums1, k1)); // Output: 9
        
        // test cases 2
        int[] nums2 = {2, 12, 1, 11, 4, 5};
        int k2 = 6;
        System.out.println(solution.findKOr(nums2, k2)); // Output: 0

        // test cases 3
        int[] nums3 = {10, 8, 5, 9, 11, 6, 8};
        int k3 = 1;
        System.out.println(solution.findKOr(nums3, k3)); // Output: 15
        
    }
}