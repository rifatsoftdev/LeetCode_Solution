#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        long long tmp = 0;
        long long maxVal = 0;

        for (int i = 0; i < n; i++) {
            totalSum = totalSum + nums[i];
        }

        for (int i = 0; i < n; i++) {
            tmp = tmp + (i * nums[i]);
        }

        maxVal = tmp;

        for (int i = 1; i < n; i++) {
            tmp = tmp + totalSum - n * nums[n - i];
            maxVal = max(maxVal, tmp);
        }

        return maxVal;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    // test cases 1
    vector<int> nums1 = {4, 3, 2, 6};
    cout << solution.maxRotateFunction(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {100};
    cout << solution.maxRotateFunction(nums2) << endl;

    return 0;
}