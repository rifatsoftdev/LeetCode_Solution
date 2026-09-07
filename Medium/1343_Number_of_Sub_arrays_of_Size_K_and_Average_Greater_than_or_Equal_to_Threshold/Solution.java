import java.util.*;


public class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if (sum >= threshold * k) {
            ans++;
        }

        for (int i = k; i < arr.length; i++) {
            sum -= arr[i-k];
            sum += arr[i];

            if (sum >= threshold * k) {
                ans++;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] arr1 = {2,2,2,2,5,5,5,8};
        int k1 = 3, threshold1 = 4;
        System.out.println(solution.numOfSubarrays(arr1, k1, threshold1));

        // test cases 2
        int[] arr2 = {11,13,17,23,29,31,7,5,2,3};
        int k2 = 3, threshold2 = 5;
        System.out.println(solution.numOfSubarrays(arr2, k2, threshold2));
         
    }
}