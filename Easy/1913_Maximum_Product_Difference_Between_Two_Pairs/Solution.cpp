#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n-1] * nums[n-2]) - (nums[0] * nums[1]);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {5,6,2,7,4};
    cout << solution.maxProductDifference(nums1) << endl;   // 34

    // test cases 2
    vector<int> nums2 = {4,2,5,9,7,4,8};
    cout << solution.maxProductDifference(nums2) << endl;   // 64

    return 0;
}