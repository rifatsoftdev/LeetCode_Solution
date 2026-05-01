#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Spiral Matrix II (Layer-by-Layer Simulation):
    1. Initialize an `n x n` matrix with zeros and a counter `data` starting at 1.
    2. Maintain four boundaries: `top`, `down`, `left`, and `right`.
    3. Fill the `top` row from `left` to `right`, then increment `top`.
    4. Fill the `right` column from `top` to `down`, then decrement `right`.
    5. Fill the `down` row from `right` to `left`, then decrement `down`.
    6. Fill the `left` column from `down` to `top`, then increment `left`.
    7. Repeat the process until `data` reaches `n * n`.

Time Complexity: O(n^2) where n is the given integer.
Space Complexity: O(1) (excluding the output matrix).
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int top = 0, down = n-1;
        int left = 0, right = n-1;
        int data = 1;

        while (top <= down && left <= right) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = data;
                data++;
            }
            top++;

            for (int i = top; i <= down; i++) {
                ans[i][right] = data;
                data++;
            }
            right--;

            if (top <= down) {
                for (int i = right; i >= left; i--) {
                    ans[down][i] = data;
                    data++;
                }
                down--;
            }
            
            if (left <= right) {
                for (int i = down; i >= top; i--) {
                    ans[i][left] = data;
                    data++;
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
    
    vector<vector<int>> ans1 = solution.generateMatrix(3);
    printVec2D(ans1);

    vector<vector<int>> ans2 = solution.generateMatrix(1);
    printVec2D(ans2);

    return 0;
}