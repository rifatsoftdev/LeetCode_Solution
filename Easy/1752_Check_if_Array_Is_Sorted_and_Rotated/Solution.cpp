#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {3,4,5,1,2};
    cout << solution.check(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {2,1,3,4};
    cout << solution.check(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {1,2,3};
    cout << solution.check(nums3) << endl;

    return 0;
}