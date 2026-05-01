#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum Absolute Distance Between Mirror Pairs (Brute Force):
    1. A mirror pair is defined as two numbers where one is the reverse of the other.
    2. Iterate through all possible pairs (i, j) in the array.
    3. For each pair, check if `nums[i]` is the reverse of `nums[j]`.
    4. If they are mirror pairs, calculate the absolute distance `abs(i - j)`.
    5. Keep track of the minimum distance found across all mirror pairs.
    6. If no mirror pairs are found, return -1.

Time Complexity: O(n^2 * d), where n is the number of elements and d is the number of digits in the integers.
Space Complexity: O(1)
*/

// class Solution {
//     int reverseInteger(int n) {
//         int reversed = 0;

//         while (n != 0) {
//             int remainder = n % 10;
//             reversed = reversed * 10 + remainder;
//             n /= 10;
//         }

//         return reversed;
//     }

// public:
//     int minMirrorPairDistance(vector<int>& nums) {
//         int minNum = INT_MAX;

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i+1; j < nums.size(); j++) {
//                 if (reverseInteger(nums[i]) == nums[j]) {
//                     minNum = min(minNum, abs(i-j));
//                 }
//             }
//         }

//         if (minNum == INT_MAX) return -1;

//         return minNum;
//     }
// };




/* ================================================================================
Solution 2:

Minimum Absolute Distance Between Mirror Pairs (Hash Map):
    1. Use a hash map to store the index of the reverse of each number encountered so far.
    2. For each number `nums[i]`, check if it exists in the hash map.
    3. If it exists, it means we have found a mirror pair where the current `nums[i]` is the reverse of a previously seen number.
    4. Calculate the distance `i - mp[nums[i]]` and update the minimum distance.
    5. Store the reverse of the current number `reverseInteger(nums[i])` in the map with the current index `i`.
    6. Return the minimum distance found, or -1 if no mirror pairs exist.

Time Complexity: O(n * d), where n is the number of elements and d is the number of digits.
Space Complexity: O(n) to store indices in the hash map.
*/

class Solution {
    int reverseInteger(int n) {
        int reversed = 0;

        while (n != 0) {
            int remainder = n % 10;
            reversed = reversed * 10 + remainder;
            n /= 10;
        }

        return reversed;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int rev = reverseInteger(nums[i]);

            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};



int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {12,21,45,33,54};
    cout << solution.minMirrorPairDistance(nums1) << endl;

    vector<int> nums2 = {120,21};
    cout << solution.minMirrorPairDistance(nums2) << endl;

    vector<int> nums3 = {21,120};
    cout << solution.minMirrorPairDistance(nums3) << endl;

    return 0;
}