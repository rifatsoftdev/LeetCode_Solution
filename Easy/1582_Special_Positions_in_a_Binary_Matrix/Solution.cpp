#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Special Positions in a Binary Matrix:
    1. You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). A position (i,j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (soldiers can only be part of one special position).
    2. Return the number of special positions in mat.

Time Complexity: O(m*n*(m+n)) where m is the number of rows and n is the number of columns in the matrix. This is because for each element in the matrix, we check its entire row and column.
Space Complexity: O(1) as we are using only a constant amount of extra space for the check function.
*/

class Solution {
private:
    bool check(vector<vector<int>>& mat, int i, int j) {
        // Check if the current position is the only 1 in its row
        for (int k = 0; k < mat[0].size(); k++) {
            if (k != j && mat[i][k] == 1) {
                return false;
            }
        }
        // Check if the current position is the only 1 in its column
        for (int k = 0; k < mat.size(); k++) {
            if (k != i && mat[k][j] == 1) {
                return false;
            }
        }
        return true;
    }

public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n =  mat[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (check(mat, i, j)) {
                        ans++;
                    }
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
    
    vector<vector<int>> mat1 = {{1,0,0}, {0,0,1}, {1,0,0}};
    cout << solution.numSpecial(mat1) << endl;

    vector<vector<int>> mat2 = {{1,0,0}, {0,1,0}, {0,0, 1}};
    cout << solution.numSpecial(mat2) << endl;

    return 0;
}