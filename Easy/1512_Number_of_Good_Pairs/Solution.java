import java.util.*;


public class Solution {
    public int numIdenticalPairs(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 0;

        for (int num : nums) {
            if (map.containsKey(num)) {
                count += map.get(num);
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 3, 1, 1, 3};
        int result1 = solution.numIdenticalPairs(nums1);
        System.out.println(result1);

        // test cases 2
        int[] nums2 = {1, 1, 1, 1};
        int result2 = solution.numIdenticalPairs(nums2);
        System.out.println(result2);

        // test cases 3
        int[] nums3 = {1, 2, 3};
        int result3 = solution.numIdenticalPairs(nums3);
        System.out.println(result3);
        
    }
}