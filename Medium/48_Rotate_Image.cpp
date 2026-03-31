#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Optimal Solution (Transpose and Reverse):
    1. To rotate the image by 90 degrees clockwise, we can first transpose the matrix.
    2. Transposing involves swapping elements at `matrix[i][j]` with `matrix[j][i]`.
    3. After transposing, we reverse each row of the matrix to achieve the 90-degree rotation.

Time Complexity: O(n^2) - We traverse the matrix twice (once for transpose and once for reversing rows).
Space Complexity: O(1) - The rotation is performed in-place.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    solution.rotate(matrix1);
    printVec2D(matrix1);

    vector<vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    solution.rotate(matrix2);
    printVec2D(matrix2);

    return 0;
}