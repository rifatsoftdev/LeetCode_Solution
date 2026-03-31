#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Flip Square Submatrix Vertically:
    1. Given an `n x n` binary grid and a square submatrix defined by its top-left corner `(x, y)` and side length `k`.
    2. To flip the submatrix vertically, we swap the rows within the submatrix range.
    3. The rows to be swapped range from `x` to `x + k - 1`.
    4. For each row `i` from `0` to `k/2`, swap the elements in the submatrix at `grid[x + i][y...y+k-1]` with `grid[x + k - 1 - i][y...y+k-1]`.

Time Complexity: O(k^2), where k is the side length of the submatrix.
Space Complexity: O(1) as the flip is performed in-place.
*/

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int start = x;
        int end = x+k-1;

        while (start < end) {
            int right = y+k;

            for (int left = y; left < right; left ++) {
                swap(grid[start][left], grid[end][left]);
            }

            start++;
            end--;
        }

        return grid;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> ans1 = solution.reverseSubmatrix(grid1, 1, 0, 3);
    printVec2D(ans1);

    vector<vector<int>> grid2 = {{3,4,2,3},{2,3,4,2}};
    vector<vector<int>> ans2 = solution.reverseSubmatrix(grid2, 0, 2, 2);
    printVec2D(ans2);

    return 0;
}