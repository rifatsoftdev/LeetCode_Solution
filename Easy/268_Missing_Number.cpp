#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Missing Number (Sorting):
    1. Sort the input array `nums` in ascending order.
    2. Iterate through the array and check if the element at index `i` is equal to `i`.
    3. If `nums[i]` is not equal to `i`, then `i` is the missing number.
    4. If the loop completes without finding a mismatch, the missing number is `n` (the size of the array).

Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(1) or O(n) depending on the sorting algorithm's space requirements.

Note: This problem can be solved in O(n) time and O(1) space using the sum formula (n*(n+1)/2) or XOR operations.
*/

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             if (nums[i] != i) return i;
//         }

//         return n;
//     }
// };




/* ================================================================================
Solution 2:

Missing Number (Sum Formula):
    1. Calculate the expected sum of the first n natural numbers using the formula: sum = n * (n + 1) / 2.
    2. Iterate through the given array and subtract each element from the expected sum.
    3. The remaining value in the sum is the missing number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = n * (n + 1) / 2;

        for (int i = 0; i < n; i++) {
            sum -= nums[i];
        }

        return sum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {3,0,1};
    cout << solution.missingNumber(nums1) << endl;

    vector<int> nums2 = {0,1};
    cout << solution.missingNumber(nums2) << endl;

    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    cout << solution.missingNumber(nums3) << endl;

    return 0;
}