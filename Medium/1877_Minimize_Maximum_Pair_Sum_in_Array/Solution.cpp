#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxPairSum = 0;

        for (int i = 0; i < n / 2; ++i) {
            int pairSum = nums[i] + nums[n - 1 - i];
            maxPairSum = max(maxPairSum, pairSum);
        }

        return maxPairSum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {3,5,2,3};
    cout << solution.minPairSum(nums1) << endl; // Output: 7

    // test cases 2
    vector<int> nums2 = {3,5,4,2,4,6};
    cout << solution.minPairSum(nums2) << endl; // Output: 8

    return 0;
}