#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }

        int start = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[start], nums[i]);
                start += 1;
            }
        }

        return nums;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,2,2,1,1,0};
    vector<int> ans1 = solution.applyOperations(nums1);
    printVec(ans1);

    // test cases 2
    vector<int> nums2 = {0,1};
    vector<int> ans2 = solution.applyOperations(nums2);
    printVec(ans2);

    return 0;
}