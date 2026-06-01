#include <iostream>
#include <vector>
#include <algorithm>
#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    void getPermute(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back({nums});
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPermute(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        getPermute(nums, 0, ans);

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = solution.permute(nums);
    printVec2D(ans);

    return 0;
}