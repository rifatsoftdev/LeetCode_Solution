#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Maximum Distance Between a Pair of Values (Two Pointers):
    1. Since both `nums1` and `nums2` are sorted in non-increasing order, we can use a two-pointer approach.
    2. Initialize two pointers, `i` for `nums1` and `j` for `nums2`, both starting at 0.
    3. If `nums1[i] <= nums2[j]`, it's a valid pair. Calculate the distance `j - i`, update the maximum distance, and increment `j` to see if a larger distance is possible with the same `i`.
    4. If `nums1[i] > nums2[j]`, the current `nums1[i]` is too large for any index $\ge j$. Increment `i` to find a smaller value in `nums1`.
    5. The process continues until either pointer reaches the end of its respective array.

Time Complexity: O(n + m), where n and m are the lengths of nums1 and nums2.
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {55,30,5,4,2}, nums2 = {100,20,10,10,5};
    cout << solution.maxDistance(nums1, nums2) << endl;

    vector<int> nums3 = {2,2,2}, nums4 = {10,10,1};
    cout << solution.maxDistance(nums3, nums4) << endl;

    vector<int> nums5 = {30,29,19,5}, nums6 = {25,25,25,25,25};
    cout << solution.maxDistance(nums5, nums6) << endl;

    return 0;
}