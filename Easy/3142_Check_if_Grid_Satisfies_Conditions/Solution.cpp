#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

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
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<vector<int>> grid1 = {{1, 0, 2}, {1, 0, 2}};
    cout << solution.satisfiesConditions(grid1) << endl; // Output: true

    // test cases 2
    vector<vector<int>> grid2 = {{1, 1, 1}, {0, 0, 0}};
    cout << solution.satisfiesConditions(grid2) << endl; // Output: false

    // test cases 3
    vector<vector<int>> grid3 = {{1}, {2}, {3}};
    cout << solution.satisfiesConditions(grid3) << endl; // Output: false

    return 0;
}