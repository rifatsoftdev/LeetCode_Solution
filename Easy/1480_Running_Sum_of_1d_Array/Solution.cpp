#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.runningSum(nums1);
    printVec(result1);

    // test cases 2
    vector<int> nums2 = {1, 1, 1, 1};
    vector<int> result2 = solution.runningSum(nums2);
    printVec(result2);

    return 0;
}