#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                result += nums[i];
            } else {
                result -= nums[i];
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,3,5,7};
    cout << solution.alternatingSum(nums1) << endl; // Output: -4

    // test cases 2
    vector<int> nums2 = {100};
    cout << solution.alternatingSum(nums2) << endl; // Output: 100

    return 0;
}