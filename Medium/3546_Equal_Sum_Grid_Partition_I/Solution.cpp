#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Equal Sum Grid Partition I (Horizontal and Vertical Cuts):
    1. Calculate the total sum of all elements in the grid. If the total sum is odd, it's impossible to partition it into two equal integer sums, so return false.
    2. To partition the grid with a single horizontal or vertical cut, we check if any prefix sum (row-wise or column-wise) equals exactly half of the total sum.
    3. For a horizontal cut: Iterate through the rows, accumulating the sum of elements. If the sum after any row (except the last one) equals total/2, return true.
    4. For a vertical cut: Iterate through the columns, accumulating the sum of elements. If the sum after any column (except the last one) equals total/2, return true.
    5. If no such cut is found after checking both directions, return false.

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns.
Space Complexity: O(1) auxiliary space.
*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        
        int m = grid.size();
        int n = grid[0].size();

        // total sum
        for (auto &row : grid) {
            for (int x : row) total += x;
        }

        if (total % 2 != 0) return false;

        long long prefix = 0;

        // horizontal cut
        for (int i = 0; i < m; i++) {
            for (int x : grid[i]) prefix += x;
            if (prefix * 2 == total && i < m - 1)
                return true;
        }

        // vertical cut
        prefix = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                prefix += grid[i][j];
            }
            if (prefix * 2 == total && j < n - 1)
                return true;
        }

        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{1,4},{2,3}};
    cout << solution.canPartitionGrid(grid1) << endl;

    vector<vector<int>> grid2 = {{1,3},{2,4}};
    cout << solution.canPartitionGrid(grid2) << endl;

    return 0;
}