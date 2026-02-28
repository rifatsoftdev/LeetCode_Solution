#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimal solution (Backtracking):
1. We can use backtracking to generate all possible permutations of the input array.
2. We define a recursive function that takes the current index and the input array. If the current index is equal to the size of the array, we add the current permutation to the result.
3. We iterate through the array starting from the current index, swapping the current index with the iterating index and recursively calling the function with the next index.
4. After the recursive call, we swap back to restore the original array for the next iteration.

Time complexity: O(n*n!)
Space complexity: O(n*n!)
*/

class Solution {
public:
    void getPermute(vector<int>& nums, int idx, set<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.insert({nums});
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPermute(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;

        getPermute(nums, 0, ans);

        vector<vector<int>> ansVct(ans.begin(), ans.end());
        return ansVct;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = solution.permuteUnique(nums);
    printVec2D(ans);

    return 0;
}