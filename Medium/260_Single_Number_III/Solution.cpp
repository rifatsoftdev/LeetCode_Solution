#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Single Number III (Hash Map):
    1. Use a hash map to store the frequency of each element in the array.
    2. Iterate through the array and update the count for each element.
    3. Iterate through the hash map and identify the elements that have a frequency of 1.
    4. Store these elements in a result vector and return it.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 1) {
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,2,1,3,2,5};
    vector<int> ans1 = solution.singleNumber(nums1);
    printVec(ans1);

    vector<int> nums2 = {-1,0};
    vector<int> ans2 = solution.singleNumber(nums2);
    printVec(ans2);

    vector<int> nums3 = {0,1};
    vector<int> ans3 = solution.singleNumber(nums3);
    printVec(ans3);

    return 0;
}