import java.util.*;


public class Solution {
    public int removeDuplicates(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int index = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], 1);
                nums[index++] = nums[i];
            } else if (map.get(nums[i]) < 2) {
                map.put(nums[i], map.get(nums[i]) + 1);
                nums[index++] = nums[i];
            }
        }

        return index;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,1,1,2,2,3};
        System.out.println(solution.removeDuplicates(nums1)); // Output: 5

        // test cases 2
        int[] nums2 = {0,0,1,1,1,1,2,3,3};
        System.out.println(solution.removeDuplicates(nums2)); // Output: 7
        
    }
}