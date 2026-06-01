import java.util.List;

public class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (Integer.bitCount(i) == k) {
                sum += nums.get(i);
            }
        }

        return sum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        List<Integer> nums1 = List.of(5, 10, 1, 5, 2);
        int k1 = 1;
        System.out.println(solution.sumIndicesWithKSetBits(nums1, k1)); // Output: 13
        
        // test cases 2
        List<Integer> nums2 = List.of(4, 3, 2, 1);
        int k2 = 2;
        System.out.println(solution.sumIndicesWithKSetBits(nums2, k2)); // Output: 1
        
    }
}