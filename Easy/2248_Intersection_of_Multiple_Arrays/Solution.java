import java.util.ArrayList;
import java.util.List;


public class Solution {
    public List<Integer> intersection(int[][] nums) {
        int n = nums.length;
        int[] count = new int[1001];
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].length; j++) {
                count[nums[i][j]]++;
            }
        }

        for (int i = 0; i < 1001; i++) {
            if (count[i] == n) {
                result.add(i);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[][] nums1 = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
        List<Integer> result1 = solution.intersection(nums1);
        System.out.println(result1); // Output: [3, 4]

        // test cases 2
        int[][] nums2 = {{1,2,3},{4,5,6}};
        List<Integer> result2 = solution.intersection(nums2);
        System.out.println(result2); // Output: []
        
    }
}