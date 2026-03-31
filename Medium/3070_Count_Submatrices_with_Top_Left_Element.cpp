#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Count Submatrices with Top-Left Element (2D Prefix Sum):
    1. Use a 2D prefix sum approach to calculate the sum of all submatrices starting from (0, 0) to (i, j).
    2. The sum of a submatrix ending at (i, j) is calculated as: `sum(i, j) = grid[i][j] + sum(i-1, j) + sum(i, j-1) - sum(i-1, j-1)`.
    3. Iterate through each cell (i, j) in the grid, compute the prefix sum, and check if it is less than or equal to k.
    4. If the condition is met, increment the count.

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns.
Space Complexity: O(m * n) to store the prefix sums.
*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> pre(m, vector<long long>(n, 0));
        
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                pre[i][j] = grid[i][j];

                if (i > 0) pre[i][j] += pre[i-1][j];
                if (j > 0) pre[i][j] += pre[i][j-1];
                if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];

                if (pre[i][j] <= k) ans++;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{7,6,3},{6,6,1}};
    cout << solution.countSubmatrices(grid1, 18) << endl;

    vector<vector<int>> grid2 = {{7,2,9},{1,5,0},{2,6,6}};
    cout << solution.countSubmatrices(grid2, 20) << endl;

    return 0;
}