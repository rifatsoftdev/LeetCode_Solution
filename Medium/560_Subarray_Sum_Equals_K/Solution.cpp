#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Subarray Sum Equals K (Brute Force):
    1. Iterate through all possible starting points `i` of a subarray.
    2. For each starting point, iterate through all possible ending points `j`.
    3. Calculate the sum of the subarray from `i` to `j`.
    4. If the sum equals `k`, increment the count.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if (sum == k) count++;
//             }
//         }

//         return count;
//     }
// };




/* ================================================================================
Solution 2:

Optimal Solution (Hash Map with Prefix Sum):
    1. Use a hash map to store the frequency of prefix sums encountered so far.
    2. Maintain a running `sum` as you iterate through the array.
    3. For each element, check if `sum - k` exists in the hash map. If it does, it means there is a subarray ending at the current index that sums to `k`.
    4. Increment the total count by the frequency of `sum - k` found in the map.
    5. Update the hash map with the current prefix sum.

Time Complexity: O(n) as we traverse the array once.
Space Complexity: O(n) to store the prefix sums in the hash map.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count += mp[sum-k];
            mp[sum]++;
        }

        return count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,1,1};
    cout << solution.subarraySum(nums1, 2) << endl;

    vector<int> nums2 = {1,2,3};
    cout << solution.subarraySum(nums2, 3) << endl;

    return 0;
}