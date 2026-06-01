#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(i) == k) {
                sum += nums[i];
            }
        }

        return sum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {5,10,1,5,2};
    int k1 = 1;
    cout << solution.sumIndicesWithKSetBits(nums1, k1) << endl;

    // test cases 2
    vector<int> nums2 = {4,3,2,1};
    int k2 = 2;
    cout << solution.sumIndicesWithKSetBits(nums2, k2) << endl;

    return 0;
}