#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;

        for (int n : nums) {
            int ds = 0;

            while (n != 0) {
                int d = n % 10;
                ds += d;
                n /= 10;
            }

            minSum = min(minSum, ds);
        }

        return minSum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test case 1
    vector<int> nums1 = {10,12,13,14};
    cout << solution.minElement(nums1) << endl;

    // test case 2
    vector<int> nums2 = {1,2,3,4};
    cout << solution.minElement(nums2) << endl;

    // test case 3
    vector<int> nums3 = {999,19,199};
    cout << solution.minElement(nums3) << endl;

    return 0;
}