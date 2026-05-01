import java.util.Arrays;
import java.util.HashMap;
// import devlibs.java.JavaHelper;


public class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            if (seen.containsKey(complement)) {
                return new int[] {seen.get(complement), i};
            }

            seen.put(nums[i], i);
        }

        return new int[] {};
    }

    public static void main(String[] args) {

        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {2,7,11,15};
        int[] ans1 = solution.twoSum(nums1, 9);
        // JavaHelper.printArray(ans1);
        System.out.println(Arrays.toString(ans1));

        // test cases 2
        int[] nums2 = {3,2,4};
        int[] ans2 = solution.twoSum(nums2, 6);
        System.out.println(Arrays.toString(ans2));

        // test cases 3
        int[] nums3 = {3,3};
        int[] ans3 = solution.twoSum(nums3, 6);
        System.out.println(Arrays.toString(ans3));
    }
}
