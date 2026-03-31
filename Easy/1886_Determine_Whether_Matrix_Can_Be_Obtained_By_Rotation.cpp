#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Determine Whether Matrix Can Be Obtained By Rotation:
    1. A matrix can be rotated 90 degrees clockwise by transforming each element at `mat[i][j]` to `newMat[j][n - 1 - i]`.
    2. To determine if `mat` can be rotated to match `target`, perform up to four 90-degree rotations (0, 90, 180, and 270 degrees).
    3. After each rotation, compare the current state of `mat` with `target`.
    4. If they match at any point, return true. If no match is found after four rotations, return false.

Time Complexity: O(n^2), where n is the number of rows/columns, as we perform a constant number of rotations (4), each taking O(n^2) time.
Space Complexity: O(n^2) to store the temporary rotated matrix.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - i - 1] = mat[i][j];
            }
        }

        mat = temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}