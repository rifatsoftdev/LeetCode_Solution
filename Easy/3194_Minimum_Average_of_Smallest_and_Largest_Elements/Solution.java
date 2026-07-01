import java.util.Arrays;



public class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);

        double minimumNum = 50.0;
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            double ave = (nums[left] + nums[right]) / 2.0;
            minimumNum = Math.min(minimumNum, ave);
            left++;
            right--;
        }

        return minimumNum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {7, 8, 3, 4, 15, 13, 4, 1};
        System.out.println(solution.minimumAverage(nums1)); // Output: 5.5
        
        // test cases 2
        int[] nums2 = {1, 9, 8, 3, 10, 5};
        System.out.println(solution.minimumAverage(nums2)); // Output: 5.5

        // test cases 3
        int[] nums3 = {1, 2, 3, 7, 8, 9};
        System.out.println(solution.minimumAverage(nums3)); // Output: 5.0
        
    }
}