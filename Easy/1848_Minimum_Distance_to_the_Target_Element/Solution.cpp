#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
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
    vector<int> nums1 = {1,2,3,4,5};
    int target1 = 5;
    int start1 = 3;
    cout << solution.getMinDistance(nums1, target1, start1) << endl;

    // test cases 2
    vector<int> nums2 = {1};
    int target2 = 1;
    int start2 = 0;
    cout << solution.getMinDistance(nums2, target2, start2) << endl;

    // test cases 3
    vector<int> nums3 = {1,1,1,1,1,1,1,1,1,1};
    int target3 = 1;
    int start3 = 0;
    cout << solution.getMinDistance(nums3, target3, start3) << endl;

    return 0;
}