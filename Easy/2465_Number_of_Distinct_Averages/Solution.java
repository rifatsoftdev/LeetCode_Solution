


public class Solution {
    public int distinctAverages(int[] nums) {
        java.util.Arrays.sort(nums);
        java.util.Set<Double> averages = new java.util.HashSet<>();
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            double avg = (nums[left] + nums[right]) / 2.0;
            averages.add(avg);
            left++;
            right--;
        }

        return averages.size();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {4, 1, 4, 0, 3, 5};
        System.out.println(solution.distinctAverages(nums1)); // Output: 2

        // test cases 2
        int[] nums2 = {1, 100};
        System.out.println(solution.distinctAverages(nums2)); // Output: 1
        
    }
}