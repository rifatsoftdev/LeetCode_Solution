#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Jump Game (Greedy):
    1. Maintain a variable `maxReach` to track the farthest index that can be reached.
    2. Iterate through the array; if the current index `i` exceeds `maxReach`, it means this position is unreachable, so return false.
    3. Update `maxReach` at each step as `max(maxReach, i + nums[i])`.
    4. If the loop completes, it means the end of the array is reachable.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {2,3,1,1,4};
    cout << solution.canJump(nums1) << endl;

    vector<int> nums2 = {3,2,1,0,4};
    cout << solution.canJump(nums2) << endl;

    return 0;
}