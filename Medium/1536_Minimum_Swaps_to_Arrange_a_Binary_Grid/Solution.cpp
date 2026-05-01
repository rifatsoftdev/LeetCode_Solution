#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum Swaps to Arrange a Binary Grid:
    1. Count Trailing Zeros: For each row, count the number of trailing zeros and store it in an array.
    2. Determine Required Zeros: For each row i, determine how many trailing zeros are needed (which is n - i - 1).
    3. Find Suitable Row: For each row i, find the first row j (starting from i) that has enough trailing zeros. If no such row exists, return -1.
    4. Swap Rows: If a suitable row j is found, swap it with row i and increment the swap count. Continue this process until all rows are arranged correctly.
    5. Return the Total Swaps: After processing all rows, return the total number of swaps made.

Time Complexity: O(n^2) - We may need to check each row for each row, and swapping can also take O(n) in the worst case.
Space Complexity: O(n) - We use an additional array to store the count of trailing zeros for each row.
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--)
                count++;
            zeros[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;
            while (j < n && zeros[j] < needed) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{0,0,1},{1,1,0},{1,0,0}};
    cout << solution.minSwaps(grid1) << endl; // Output: 3

    vector<vector<int>> grid2 = {{0,1,1},{1,0,1},{1,1,0}};
    cout << solution.minSwaps(grid2) << endl; // Output: 0

    return 0;
}