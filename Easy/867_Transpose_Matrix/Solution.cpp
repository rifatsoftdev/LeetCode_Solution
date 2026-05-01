#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Transpose Matrix:
    1. Given a 2D integer array `matrix`, return the transpose of `matrix`.
    2. The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
    3. Create a new matrix `transposed` with dimensions `n x m` where the original matrix was `m x n`.
    4. Iterate through each element at `matrix[i][j]` and assign it to `transposed[j][i]`.

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
Space Complexity: O(m * n) to store the transposed matrix.
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix[0].size();
        int cols = matrix.size();

        vector<vector<int>> transposed(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed[i][j] = matrix[j][i];
            }
        }
        return transposed;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans1 = solution.transpose(matrix1);
    printVec2D(ans1);

    vector<vector<int>> matrix2 = {{1,2,3},{4,5,6}};
    vector<vector<int>> ans2 = solution.transpose(matrix2);
    printVec2D(ans2);

    return 0;
}