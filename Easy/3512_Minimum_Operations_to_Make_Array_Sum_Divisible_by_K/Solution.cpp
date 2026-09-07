#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        return sum % k;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {3,9,7};
    int k1 = 5;
    cout << solution.minOperations(nums1, k1) << endl;

    // test cases 2
    vector<int> nums2 = {4,1,3};
    int k2 = 4;
    cout << solution.minOperations(nums2, k2) << endl;

    // test cases 3
    vector<int> nums3 = {3,2};
    int k3 = 6;
    cout << solution.minOperations(nums3, k3) << endl;

    return 0;
}