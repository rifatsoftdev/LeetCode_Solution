#include <iostream>
#include <vector>
#include <unordered_map>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Linear Search):
1. Iterate through the array and check for each element if it has a duplicate.
2. Return the element that does not have a duplicate.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//          
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if (nums[i] + nums[j] == target) {
//                     result.push_back(i);
//                     result.push_back(j);
//                     return result;
//                 }
//             }
//         }
// 
//         return result;
//     }
// };


/*
Optimal Approach (Hash Map):
1. Use an unordered_map to store the indices of the elements we have seen so far.
2. For each element, calculate its complement (target - current element) and check if it exists in the map.
3. If it exists, return the indices of the current element and its complement.
4. If it does not exist, add the current element and its index to the map.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }
        return {}; // Shouldn't reach here as per problem statement
    }
};


int main() {
    Solution solution;
    
    vector<int> nums = {2,7,11,15};
    vector<int> ans = solution.twoSum(nums, 9);

    printVec(ans);


    return 0;
}