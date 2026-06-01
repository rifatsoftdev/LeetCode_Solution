#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int zero = 0;
        int one = n-1;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans[zero] = 0;
                zero++;
            } else {
                ans[one] = 1;
                one--;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {4,3,2,1};
    vector<int> ans1 = solution.transformArray(nums1);
    printVec(ans1);

    // test cases 2
    vector<int> nums2 = {1,5,1,4,2};
    vector<int> ans2 = solution.transformArray(nums2);
    printVec(ans2);

    return 0;
}