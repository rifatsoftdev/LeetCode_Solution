#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 2; i < n; i++) {
            float half = nums[i-1] / 2.0;
            float sum = nums[i-2] + nums[i];

            if (sum == half) {
                ans++;
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
    vector<int> nums1 = {1,2,1,4,1};
    cout << solution.countSubarrays(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {1,1,1};
    cout << solution.countSubarrays(nums2) << endl;

    // [-1,-4,-1,4]

    return 0;
}