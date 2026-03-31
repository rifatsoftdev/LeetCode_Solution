#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find Missing and Repeated Values:
    1. You are given a 0-indexed 2D integer matrix `grid` of size n x n with values in the range [1, n^2].
    2. Each integer appears exactly once except for one number `a` which appears twice and one number `b` which is missing.
    3. Use a hash map to track the frequency of each number to identify the duplicate `a`.
    4. Calculate the expected sum of numbers from 1 to n^2 using the formula: sum = N * (N + 1) / 2, where N = n^2.
    5. Calculate the actual sum of elements in the grid.
    6. The missing number `b` can be found using the relation: missing = expectedSum - (actualSum - duplicate).

Time Complexity: O(n^2), where n is the dimension of the grid, as we visit each element once.
Space Complexity: O(n^2) to store the frequency of elements in the map.
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> result;
        map<int, int> mp;
        long long n = grid.size() * grid[0].size();
        long long sum1 = (n * (n + 1)) / 2;
        long long sum2 = 0;
        int duplicate = -1;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mp[grid[i][j]]++;
                
                sum2 += grid[i][j];
            
                if (mp[grid[i][j]] == 2) {
                    result.push_back(grid[i][j]);
                    duplicate = grid[i][j];
                }
            }
        }

        result.push_back(sum1 - (sum2 - duplicate));
        
        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> grid1 = {{1,3},{2,2}};
    vector<int> ans1 = solution.findMissingAndRepeatedValues(grid1);
    printVec(ans1);

    vector<vector<int>> grid2 = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ans2 = solution.findMissingAndRepeatedValues(grid2);
    printVec(ans2);

    return 0;
}