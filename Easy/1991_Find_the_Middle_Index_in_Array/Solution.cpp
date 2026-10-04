#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - nums[i] - leftSum;

            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {2,3,-1,8,4};
    cout << solution.findMiddleIndex(nums1) << endl; // Expected output: 3

    // test cases 2
    vector<int> nums2 = {1,-1,4};
    cout << solution.findMiddleIndex(nums2) << endl; // Expected output: 2

    // test cases 3
    vector<int> nums3 = {2,5};
    cout << solution.findMiddleIndex(nums3) << endl; // Expected output: -1

    return 0;
}