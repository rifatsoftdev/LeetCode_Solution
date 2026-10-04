#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> result = nums;

        for (int i = nums.size() - 1; i >= 0; --i) {
            result.push_back(nums[i]);
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> result1 = solution.concatWithReverse(nums1);
    printVec(result1);

    // test cases 2
    vector<int> nums2 = {1};
    vector<int> result2 = solution.concatWithReverse(nums2);
    printVec(result2);

    return 0;
}