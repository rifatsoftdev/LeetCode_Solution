#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Maximum Non-Negative Product in a Matrix (Dynamic Programming):
    1. Since the grid contains both positive and negative numbers, a negative product multiplied by another negative number can become a large positive number.
    2. We maintain two DP tables: `dpMax[i][j]` to store the maximum product and `dpMin[i][j]` to store the minimum product reaching cell `(i, j)`.
    3. For each cell, the current value is multiplied by the max and min products from the cell above and the cell to the left.
    4. If the current value is negative, the new maximum comes from the previous minimum, and the new minimum comes from the previous maximum.
    5. If the maximum product at the bottom-right cell is negative, return -1; otherwise, return the result modulo 10^9 + 7.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const long MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();

        // dpMin and dpMax store the min/max product up to each cell
        vector<vector<long>> dpMin(m, vector<long>(n)), dpMax(m, vector<long>(n));

        dpMin[0][0] = dpMax[0][0] = grid[0][0];

        // first column
        for (int i = 1; i < m; ++i) {
            dpMin[i][0] = dpMax[i][0] = dpMax[i-1][0] * grid[i][0];
        }
        // first row
        for (int j = 1; j < n; ++j) {
            dpMin[0][j] = dpMax[0][j] = dpMax[0][j-1] * grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                long v = grid[i][j];
                long a = dpMin[i-1][j], b = dpMin[i][j-1];
                long c = dpMax[i-1][j], d = dpMax[i][j-1];

                if (v >= 0) {
                    dpMax[i][j] = max(c, d) * v;
                    dpMin[i][j] = min(a, b) * v;
                } else {
                    dpMax[i][j] = min(a, b) * v;
                    dpMin[i][j] = max(c, d) * v;
                }
            }
        }

        long ans = dpMax[m-1][n-1];

        return ans < 0 ? -1 : (int)(ans % MOD);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
    cout << solution.maxProductPath(grid1) << endl; // Output: -1

    vector<vector<int>> grid2 = {{1,-2,1},{1,-2,1},{3,-4,1}};
    cout << solution.maxProductPath(grid2) << endl; // Output: 8

    vector<vector<int>> grid3 = {{1,3},{0, -4}};
    cout << solution.maxProductPath(grid3) << endl; // Output: 0

    return 0;
}