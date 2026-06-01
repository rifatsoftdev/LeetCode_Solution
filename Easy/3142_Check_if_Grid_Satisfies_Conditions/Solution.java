

public class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 < m && grid[i][j] == grid[i][j + 1]) {
                     return false;
                }

                if (i + 1 < n && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        int[][] grid1 = {{1, 0, 2}, {1, 0, 2}};
        System.out.println(solution.satisfiesConditions(grid1)); // Output: true

        // test cases 2
        int[][] grid2 = {{1, 1, 1}, {0, 0, 0}};
        System.out.println(solution.satisfiesConditions(grid2)); // Output: false

        // test cases 3
        int[][] grid3 = {{1}, {2}, {3}};
        System.out.println(solution.satisfiesConditions(grid3)); // Output: false
    }
}