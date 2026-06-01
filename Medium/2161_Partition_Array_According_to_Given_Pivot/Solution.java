import java.util.ArrayList;
import java.util.List;


public class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        List<Integer> smaller = new ArrayList<>();
        List<Integer> equal = new ArrayList<>();
        List<Integer> greater = new ArrayList<>();

        for (int num : nums) {
            if (num < pivot) {
                smaller.add(num);
            } else if (num == pivot) {
                equal.add(num);
            } else {
                greater.add(num);
            }
        }

        int[] result = new int[smaller.size() + equal.size() + greater.size()];
        int index = 0;

        for (int num : smaller) {
            result[index++] = num;
        }
        for (int num : equal) {
            result[index++] = num;
        }
        for (int num : greater) {
            result[index++] = num;
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] nums1 = {9, 12, 5, 10, 14, 3, 10};
        int pivot1 = 10;
        int[] result1 = solution.pivotArray(nums1, pivot1);
        for (int num : result1) {
            System.out.print(num + " ");
        }
        System.out.println();

        // test cases 2
        int [] nums2 = {-3, 4, 3, 2};
        int pivot2 = 2;
        int[] result2 = solution.pivotArray(nums2, pivot2);
        for (int num : result2) {
            System.out.print(num + " ");
        }
        System.out.println();
        
    }
}