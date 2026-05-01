#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Subsets (Backtracking):
    1. Use a recursive backtracking function to explore all possible subsets of the input array.
    2. At each step, decide whether to include the current element in the subset or not.
    3. Base case: when the starting index reaches the end of the array, add the current subset to the result.
    4. This approach explores all 2^n combinations.

Time Complexity: O(n * 2^n) - There are 2^n possible subsets, and each takes O(n) to copy to the result.
Space Complexity: O(n) - For the recursion stack and the vector storing the current subset.
*/

class Solution {
private:
    void allSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int start) {
        if (start == nums.size()) {
            result.push_back(current);
            return;
        }

        // Include the current number and move to the next
        current.push_back(nums[start]);
        allSubsets(nums, result, current, start + 1);

        // Backtrack: remove the current number and move to the next
        current.pop_back();
        allSubsets(nums, result, current, start + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        allSubsets(nums, result, current, 0);
        
        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);
    printVec2D(result);

    return 0;
}