import java.util.Arrays;


class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int idx = m + n - 1;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            } else {
                nums1[idx--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int m1 = 3, n1 = 3;
        int[] nums11 = {1,2,3,0,0,0}, nums12 = {2,5,6};
        solution.merge(nums11, m1, nums12, n1);
        System.out.println(Arrays.toString(nums11));

        // test cases 2
        int m2 = 1, n2 = 0;
        int[] nums21 = {1}, nums22 = {};
        solution.merge(nums21, m2, nums22, n2);
        System.out.println(Arrays.toString(nums21));

        // test cases 3
        int m3 = 0, n3 = 1;
        int[] nums31 = {0}, nums32 = {1};
        solution.merge(nums31, m3, nums32, n3);
        System.out.println(Arrays.toString(nums31));
    }
}