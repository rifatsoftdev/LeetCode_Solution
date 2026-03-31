#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Majority Element II (Hash Map):
    1. Use a hash map to store the frequency of each element in the array.
    2. Iterate through the array and update the count for each element.
    3. If an element's count exceeds n/3, add it to a set to ensure uniqueness.
    4. Convert the set to a vector and return it as the result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m;

        int n = nums.size();
        int majority = (nums.size() / 3) + 1;
        
        set<int> s;

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;

            if (m[nums[i]] >= majority) {
                s.insert(nums[i]);
            }
        }
        vector<int> ans(s.begin(), s.end());

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> nums1 = {3,2,3};
    vector<int> ans1 = solution.majorityElement(nums1);
    printVec(ans1);

    vector<int> nums2 = {1};
    vector<int> ans2 = solution.majorityElement(nums2);
    printVec(ans2);

    vector<int> nums3 = {1,2};
    vector<int> ans3 = solution.majorityElement(nums3);
    printVec(ans3);
    
    return 0;
}