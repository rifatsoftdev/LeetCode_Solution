#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {3, 4, 5, 2};
    cout << solution.maxProduct(nums1) << endl; // Output: 12

    // test cases 2
    vector<int> nums2 = {1, 5, 4, 5};
    cout << solution.maxProduct(nums2) << endl; // Output: 16

    return 0;
}