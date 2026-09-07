import java.util.*;


public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        List<Integer> ans = new ArrayList<>();
        int i1 = 0, i2 = 0;

        while (i1 < nums1.length && i2 < nums2.length) {
            if (nums1[i1] == nums2[i2]) {
                ans.add(nums1[i1]);
                i1++;
                i2++;
            } else if (nums1[i1] < nums2[i2]) {
                i1++;
            } else {
                i2++;
            }
        }

        return ans.stream().mapToInt(Integer::intValue).toArray();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1,2,2,1};
        int[] nums2 = {2,2};
        int[] result1 = solution.intersect(nums1, nums2);
        System.out.println(Arrays.toString(result1)); // Expected output: [2, 2]
        
        // test cases 2
        int[] nums3 = {4, 9, 5};
        int[] nums4 = {9, 4, 9, 8, 4};
        int[] result2 = solution.intersect(nums3, nums4);
        System.out.println(Arrays.toString(result2)); // Expected output: [4, 9]
        
    }
}