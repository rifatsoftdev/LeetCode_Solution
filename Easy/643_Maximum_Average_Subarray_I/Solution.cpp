#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxSum = 0;

        for (int i = 0; i < k; ++i) {
            maxSum += nums[i];
        }

        double currentSum = maxSum;

        for (int i = k; i < n; ++i) {
            currentSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum / k;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << solution.findMaxAverage(nums1, k1) << endl;

    // test cases 2
    vector<int> nums2 = {5};
    int k2 = 1;
    cout << solution.findMaxAverage(nums2, k2) << endl;

    return 0;
}