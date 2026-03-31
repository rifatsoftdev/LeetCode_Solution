#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Count Submatrices With Equal Frequency (2D Prefix Sum):
    1. Use two 2D prefix sum matrices, `x` and `y`, to store the cumulative counts of 'X' and 'Y' characters from the top-left (0, 0) to each cell (i, j).
    2. For each cell (i, j), calculate the prefix sum: `count(i, j) = current_cell + count(i-1, j) + count(i, j-1) - count(i-1, j-1)`.
    3. A submatrix starting at (0, 0) and ending at (i, j) is valid if the count of 'X' is greater than 0 and equal to the count of 'Y'.
    4. Iterate through the grid, update the prefix sums, and increment the answer whenever the condition is met.

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns.
Space Complexity: O(m * n) to store the prefix sum matrices.
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> x(m, vector<int>(n, 0));
        vector<vector<int>> y(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int isX = (grid[i][j] == 'X');
                int isY = (grid[i][j] == 'Y');
                
                x[i][j] = isX;
                y[i][j] = isY;
                
                if(i > 0) {
                    x[i][j] += x[i-1][j];
                    y[i][j] += y[i-1][j];
                }
                if(j > 0) {
                    x[i][j] += x[i][j-1];
                    y[i][j] += y[i][j-1];
                }
                if(i > 0 && j > 0) {
                    x[i][j] -= x[i-1][j-1];
                    y[i][j] -= y[i-1][j-1];
                }
                
                if(x[i][j] > 0 && x[i][j] == y[i][j]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<char>> grid1 = {{'X','Y','.'},{'Y','.','.'}};
    cout << solution.numberOfSubmatrices(grid1) << endl;

    vector<vector<char>> grid2 = {{'X','X'},{'X','Y'}};
    cout << solution.numberOfSubmatrices(grid2) << endl;

    vector<vector<char>> grid3 = {{'.','.'},{'.','.'}};
    cout << solution.numberOfSubmatrices(grid3) << endl;

    return 0;
}