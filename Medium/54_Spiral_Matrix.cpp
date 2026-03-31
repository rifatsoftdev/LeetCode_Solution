#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Spiral Matrix (Layer-by-Layer Simulation):
    1. Maintain four boundaries: `top`, `down`, `left`, and `right`.
    2. Traverse from `left` to `right` along the `top` row, then increment `top`.
    3. Traverse from `top` to `down` along the `right` column, then decrement `right`.
    4. If boundaries still permit, traverse from `right` to `left` along the `down` row, then decrement `down`.
    5. If boundaries still permit, traverse from `down` to `top` along the `left` column, then increment `left`.
    6. Repeat until the boundaries cross.

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns.
Space Complexity: O(1) (excluding the output vector).
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int top = 0, down = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;

        while (top <= down && left <= right) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= down) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            
            if (left <= right) {
                for (int i = down; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans1 = solution.spiralOrder(matrix1);
    printVec(ans1);

    vector<vector<int>> matrix2 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> ans2 = solution.spiralOrder(matrix2);
    printVec(ans2);

    return 0;
}