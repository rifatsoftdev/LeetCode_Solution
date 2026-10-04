import java.util.*;


public class Solution {
    public int[] concatWithReverse(int[] nums) {
        int n = nums.length;
        int[] result = new int[2 * n];

        for (int i = 0; i < n; i++) {
            result[i] = nums[i];
            result[2 * n - 1 - i] = nums[i];
        }

        return result;
    }

    private static void printArr(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {1, 2, 3};
        int[] result1 = solution.concatWithReverse(nums1);
        printArr(result1);

        // test cases 2
        int[] nums2 = {1};
        int[] result2 = solution.concatWithReverse(nums2);
        printArr(result2);
    }
}