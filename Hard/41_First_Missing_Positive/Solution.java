import java.util.Arrays;


public class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int target = 1;

        for (int num : nums) {
            if (num == target) {
                target++;
            } else if (num > target) {
                break;
            }
        }

        return target;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,2,0};
        System.out.println(solution.firstMissingPositive(nums1));
        
        // test cases 2
        int[] nums2 = {3,4,-1,1};
        System.out.println(solution.firstMissingPositive(nums2));
        
        // test cases 3
        int[] nums3 = {7,8,9,11,12};
        System.out.println(solution.firstMissingPositive(nums3));
        
    }
}