import java.util.*;

public class Solution {

    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] ans = new int[n];

        if (k == 0) {
            return ans;
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;

            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
            } else {
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n];
                }
            }

            ans[i] = sum;
        }

        return ans;
    }

    private static void printVec(int[] arr) {
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

        int[] code1 = {5, 7, 1, 4};
        int[] result1 = solution.decrypt(code1, 3);
        printVec(result1);

        int[] code2 = {1, 2, 3, 4};
        int[] result2 = solution.decrypt(code2, 0);
        printVec(result2);

        int[] code3 = {2, 4, 9, 3};
        int[] result3 = solution.decrypt(code3, -2);
        printVec(result3);
    }
}