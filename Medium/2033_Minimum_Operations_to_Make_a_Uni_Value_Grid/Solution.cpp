#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0;
        vector<int> arr;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        int base = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            if ((arr[i] - base) % x != 0) return -1;
        }

        for (int i = 0; i < arr.size(); i++) {
            ans += abs(arr[i] - arr[arr.size() / 2]) / x;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    // test cases 1
    vector<vector<int>> grid1 = {{2, 4}, {6, 8}};
    cout << solution.minOperations(grid1, 2) << endl;

    // test cases 2
    vector<vector<int>> grid2 = {{1, 5}, {2, 3}};
    cout << solution.minOperations(grid2, 1) << endl;

    // test cases 3
    vector<vector<int>> grid3 = {{1, 2}, {3, 4}};
    cout << solution.minOperations(grid3, 2) << endl;

    return 0;
}