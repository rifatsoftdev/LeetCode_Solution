#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Subsets II (Backtracking):
    1. Sort the input array to handle duplicates easily.
    2. Use a recursive backtracking function to explore all possible subsets.
    3. In each step, decide whether to include the current element in the subset.
    4. To avoid duplicate subsets, when excluding an element, skip all subsequent elements that have the same value.
    5. Base case: when the starting index reaches the end of the array, add the current subset to the result.

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
        int idx = start + 1;

        while (idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }

        allSubsets(nums, result, current, idx);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

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
    
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    printVec2D(result);

    return 0;
}