#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;

            if (mp[nums[i]] >= 2) {
                return true;
            }
        }
        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,2,3,1};
    cout << solution.containsDuplicate(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {1,2,3,4};
    cout << solution.containsDuplicate(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};
    cout << solution.containsDuplicate(nums3) << endl;

    return 0;
}