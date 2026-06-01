

public class Solution {
    public int[] transformArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int zero = 0;
        int one = n-1;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans[zero] = 0;
                zero++;
            } else {
                ans[one] = 1;
                one--;
            }
        }

        return ans; 
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {4, 3, 2, 1};
        int[] result1 = solution.transformArray(nums1);
        for (int num : result1) System.out.print(num + " ");
        System.out.println();
        
        // test cases 2
        int[] nums2 = {1, 5, 1, 4, 2};
        int[] result2 = solution.transformArray(nums2);
        for (int num : result2) System.out.print(num + " ");
        System.out.println();
        
    }
}