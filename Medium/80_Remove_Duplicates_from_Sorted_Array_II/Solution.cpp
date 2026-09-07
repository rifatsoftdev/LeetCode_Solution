#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] < 2) {
                mp[nums[i]]++;
                nums[ans++] = nums[i];
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
    vector<int> nums1 = {1,1,1,2,2,3};
    cout << solution.removeDuplicates(nums1) << endl; // Output: 5

    // test cases 2
    vector<int> nums2 = {0,0,1,1,1,1,2,3,3};
    cout << solution.removeDuplicates(nums2) << endl; // Output: 7

    return 0;
}