

public class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        int[] frequency = new int[n + 1];
        int commonCount = 0;

        for (int i = 0; i < n; i++) {
            if (++frequency[A[i]] == 2) {
                commonCount++;
            }
            if (++frequency[B[i]] == 2) {
                commonCount++;
            }
            ans[i] = commonCount;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[] A1 = {1, 3, 2, 4};
        int[] B1 = {3, 1, 2, 4};
        int[] result1 = solution.findThePrefixCommonArray(A1, B1);
        for (int val : result1) System.out.print(val + " ");
        System.out.println();
        
        // test cases 2
        int[] A2 = {2, 3, 1};
        int[] B2 = {3, 1, 2};
        int[] result2 = solution.findThePrefixCommonArray(A2, B2);
        for (int val : result2) System.out.print(val + " ");
        System.out.println();
        
    }
}