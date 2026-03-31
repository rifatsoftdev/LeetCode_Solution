#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Largest Submatrix With Rearrangements:
    1. For each row, calculate the height of consecutive 1s ending at that row for each column. If `matrix[i][j]` is 1, `height[j]` increases by 1; otherwise, it resets to 0.
    2. After updating the heights for a row, sort the heights in descending order.
    3. The maximum area for a submatrix ending at the current row can be found by iterating through the sorted heights: `area = height[j] * (j + 1)`.
    4. Keep track of the maximum area found across all rows.

Time Complexity: O(m * n log n), where m is the number of rows and n is the number of columns (due to sorting n elements for each of the m rows).
Space Complexity: O(n) to store the heights of the columns.
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> h(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) h[j]++;
                else h[j] = 0;
            }

            vector<int> sh = h;
            sort(sh.rbegin(), sh.rend());

            for (int j = 0; j < n; j++) {
                if (sh[j] == 0) break;
                maxArea = max(maxArea, sh[j] * (j + 1));
            }
        }

        return maxArea;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}