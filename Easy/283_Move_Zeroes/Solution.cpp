#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int start = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[start], nums[i]);
                start += 1;
            }
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    printVec(nums1); // Expected: [1, 3, 12, 0, 0]
    
    // test cases 2
    vector<int> nums2 = {0};
    solution.moveZeroes(nums2);
    printVec(nums2); // Expected: [0]
    
    return 0;
}