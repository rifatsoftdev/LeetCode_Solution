#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Matrix Similarity After Cyclic Shifts:
    1. You are given an `m x n` matrix and an integer `k`.
    2. Even-indexed rows are shifted left `k` times, and odd-indexed rows are shifted right `k` times.
    3. A matrix is similar if it remains unchanged after these shifts.
    4. Instead of performing the shifts, we can check if each element `mat[i][j]` is equal to the element that would shift into its position.
    5. For even rows (left shift), the element at `(j - k)` (modulo `n`) must match. For odd rows (right shift), the element at `(j + k)` (modulo `n`) must match.
    6. If any element mismatch is found, return false. Otherwise, return true.

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
Space Complexity: O(1) as we compare elements in place.
*/

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // even row -> left shift
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                } else {
                    // odd row -> right shift
                    if (mat[i][j] != mat[i][(j + k) % n])
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
    
    vector<vector<int>> mat1 = {{1,2,3},{4,5,6},{7,8,9}};
    cout << solution.areSimilar(mat1, 4) << endl;

    vector<vector<int>> mat2 = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    cout << solution.areSimilar(mat2, 2) << endl;

    vector<vector<int>> mat3 = {{2,2},{2,2}};
    cout << solution.areSimilar(mat3, 3) << endl;

    return 0;
}