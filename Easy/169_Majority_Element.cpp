#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Majority Element:
    1. Use a hash map to store the frequency of each element in the array.
    2. Iterate through the array and increment the count for each element in the map.
    3. For each element, check if its count has reached the majority threshold (n/2).
    4. Return the element that meets the majority criteria.

Time Complexity: O(n) (where n is the number of elements in the array)
Space Complexity: O(n) (to store the frequencies in the map)

Note: This problem can also be solved in O(1) space using Boyer-Moore Voting Algorithm.
*/

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int, int> mp;
//         int n = nums.size();
//         int majority = 0;
//         int max = 0;

//         if (n % 2 == 0) majority = (nums.size() / 2);
//         else majority = (nums.size() / 2) + 1;

//         for (int i = 0; i < n; i++) {
//             mp[nums[i]]++;

//             if (mp[nums[i]] >= majority) {
//                 max = nums[i];
//             }
//         }

//         return max;
//     }
// };




/* ================================================================================
Solution 2:

Boyer-Moore Voting Algorithm:
    1. Initialize a candidate `ans` and a counter `freq` to 0.
    2. Iterate through the array:
        a. If `freq` is 0, set the current element as the candidate `ans`.
        b. If the current element is the same as `ans`, increment `freq`.
        c. Otherwise, decrement `freq`.
    3. The candidate remaining at the end is the majority element.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {3,2,3};
    cout << solution.majorityElement(nums1) << endl;

    vector<int> nums2 = {2,2,1,1,1,2,2};
    cout << solution.majorityElement(nums2) << endl;

    return 0;
}