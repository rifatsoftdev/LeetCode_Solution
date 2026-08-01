#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[ans] = nums[i];
                ans++;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {3,2,2,3};
    int val1 = 3;
    cout << solution.removeElement(nums1, val1) << endl; // Output: 2

    // test cases 2
    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    cout << solution.removeElement(nums2, val2) << endl; // Output: 5

    return 0;
}