


public class Solution {
    public int countQuadruplets(int[] nums) {
        int count = 0;
        int n = nums.length;

        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int c = b + 1; c < n; c++) {
                    for (int d = c + 1; d < n; d++) {
                        if (nums[a] + nums[b] + nums[c] == nums[d]) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,2,3,6};
        System.out.println(solution.countQuadruplets(nums1)); // Output: 1

        // test cases 2
        int[] nums2 = {3,3,6,4,5};
        System.out.println(solution.countQuadruplets(nums2)); // Output: 0

        // test cases 3
        int[] nums3 = {1,1,1,3,5};
        System.out.println(solution.countQuadruplets(nums3)); // Output: 4

    }
}