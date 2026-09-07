import java.util.*;


public class Solution {
    public int[] findDegrees(int[][] matrix) {
        int n = matrix.length;
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int tmp = 0;

            for (int j = 0; j < matrix[i].length; j++) {
                tmp += matrix[i][j];
            }

            result[i] = tmp;
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[][] matrix1 = {{0,1,1},{1,0,1},{1,1,0}};
        int[] result1 = solution.findDegrees(matrix1);
        System.out.println(result1.toString());

        // test cases 2
        int[][] matrix2 = {{0,1,0},{1,0,0},{0,0,0}};
        int[] result2 = solution.findDegrees(matrix2);
        System.out.println(result2.toString());

        // test cases 2
        int[][] matrix3 = {{0}};
        int[] result3 = solution.findDegrees(matrix3);
        System.out.println(result3.toString());
        
        
    }
}