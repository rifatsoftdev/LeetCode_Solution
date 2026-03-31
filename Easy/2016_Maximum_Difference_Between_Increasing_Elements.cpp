#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Maximum Difference Between Increasing Elements (Brute Force):
    1. Use nested loops to iterate through all possible pairs (i, j) such that 0 <= i < j < n.
    2. Check if nums[i] < nums[j].
    3. If the condition is met, calculate the difference (nums[j] - nums[i]) and update the maximum difference found so far.
    4. If no such pair exists, return -1.

Time Complexity: O(n^2) (where n is the number of elements in the array)
Space Complexity: O(1)

Note: This problem can be solved in O(n) time by keeping track of the minimum element seen so far as we iterate through the array.
*/

// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int maxDiff = -1;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[j] > nums[i]) {
//                     maxDiff = max(maxDiff, nums[j] - nums[i]);
//                 }
//             }
//         }

//         return maxDiff;
//     }
// };




/* ================================================================================
Solution 2:

Maximum Difference Between Increasing Elements (Optimal):
    1. Initialize `minVal` with the first element of the array and `ans` as -1.
    2. Iterate through the array starting from the second element.
    3. If the current element `nums[i]` is greater than `minVal`, update `ans` with the maximum of its current value and the difference `nums[i] - minVal`.
    4. Update `minVal` to be the minimum of `minVal` and the current element `nums[i]`.
    5. Return `ans`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0];
        int ans = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minVal) {
                ans = max(ans, nums[i] - minVal);
            }
            minVal = min(minVal, nums[i]);
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {7,1,5,4};
    cout << solution.maximumDifference(nums1) << endl;

    vector<int> nums2 = {9,4,3,2};
    cout << solution.maximumDifference(nums2) << endl;

    vector<int> nums3 = {1,5,2,10};
    cout << solution.maximumDifference(nums3) << endl;


    return 0;
}