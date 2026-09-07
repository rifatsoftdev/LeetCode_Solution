import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;


public class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> missing = new ArrayList<>();
        Map<Integer, Integer> countMap = new HashMap<>();
        int minNum = Integer.MAX_VALUE;
        int maxNum = Integer.MIN_VALUE  ;

        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
            minNum = Math.min(minNum, num);
            maxNum = Math.max(maxNum, num);
        }

        for (int i = minNum; i <= maxNum; i++) {
            if (!countMap.containsKey(i)) {
                missing.add(i);
            }
        }

        return missing;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,4,2,5};
        List<Integer> missing1 = solution.findMissingElements(nums1);
        System.out.println(missing1); // Expected output: [3]

        // test cases 2
        int[] nums2 = {7,8,6,9};
        List<Integer> missing2 = solution.findMissingElements(nums2);
        System.out.println(missing2); // Expected output: []

        // test cases 3
        int[] nums3 = {5,1};
        List<Integer> missing3 = solution.findMissingElements(nums3);
        System.out.println(missing3); // Expected output: [2,3,4]    

    }
}