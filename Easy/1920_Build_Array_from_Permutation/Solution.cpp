#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {0,2,1,5,3,4};
    vector<int> result1 = solution.buildArray(nums1);
    printVec(result1);

    // test cases 2
    vector<int> nums2 = {5,0,1,2,3,4};
    vector<int> result2 = solution.buildArray(nums2);
    printVec(result2);

    return 0;
}