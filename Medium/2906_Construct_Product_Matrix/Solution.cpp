#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Construct Product Matrix (Prefix and Suffix Products):
    1. The goal is to construct a matrix `p` where `p[i][j]` is the product of all elements in the grid except `grid[i][j]`, modulo 12345.
    2. Since we cannot use division (due to the modulo not being prime and potential zeros), we use the prefix and suffix product technique.
    3. First, traverse the matrix in reverse (from bottom-right to top-left) to calculate the suffix product for each cell.
    4. Then, traverse the matrix normally (from top-left to bottom-right) to calculate the prefix product and multiply it with the previously stored suffix product.
    5. All calculations are performed modulo 12345.

Time Complexity: O(n * m) where n is the number of rows and m is the number of columns.
Space Complexity: O(1) auxiliary space (excluding the space required for the output matrix).
*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> p(n, vector<int>(m, 0));
        
        // 1) Suffix product from bottom-right
        long long suf = 1;
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                p[i][j] = suf;
                suf = (suf * grid[i][j]) % mod;
            }
        }
        
        // 2) Multiply by prefix product from top-left
        long long pre = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = (p[i][j] * pre) % mod;
                pre = (pre * grid[i][j]) % mod;
            }
        }
        
        return p;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{1,2},{3,4}};
    printVec2D(solution.constructProductMatrix(grid1));

    vector<vector<int>> grid2 = {{12345},{2},{1}};
    printVec2D(solution.constructProductMatrix(grid2));

    return 0;
}