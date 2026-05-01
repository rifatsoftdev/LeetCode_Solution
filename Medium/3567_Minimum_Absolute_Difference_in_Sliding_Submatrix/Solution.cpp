#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum Absolute Difference in Sliding Submatrix (Brute Force):
    1. Iterate through all possible top-left corners (i, j) of a k x k submatrix.
    2. For each submatrix, collect all k * k elements into a list.
    3. Sort the list of elements to easily find the minimum absolute difference between any two distinct elements.
    4. Iterate through the sorted list and calculate the difference between adjacent elements.
    5. If all elements in the submatrix are the same, the minimum absolute difference is 0.
    6. Store the result for each submatrix in a 2D result matrix.

Time Complexity: O((m-k+1) * (n-k+1) * (k^2 log k^2))
Space Complexity: O(k^2) to store elements of the current submatrix.
*/

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> nums;

                // collect k x k elements
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        nums.push_back(grid[r][c]);
                    }
                }

                sort(nums.begin(), nums.end());

                int minDiff = INT_MAX;

                // find minimum difference
                for (int x = 1; x < nums.size(); x++) {
                    if (nums[x] != nums[x - 1]) {
                        minDiff = min(minDiff, nums[x] - nums[x - 1]);
                    }
                }

                // if all elements same
                if (minDiff == INT_MAX) minDiff = 0;

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}