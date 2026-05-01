#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../devlibs/cpphelper.h"

using namespace std;


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

        return {};
    }
};


int main() {
    Solution solution;
    
    // test cases 1
    vector<int> nums1 = {2,7,11,15};
    vector<int> ans1 = solution.twoSum(nums1, 9);
    printVec(ans1);

    // test cases 2
    vector<int> nums2 = {3,2,4};
    vector<int> ans2 = solution.twoSum(nums2, 6);
    printVec(ans2);

    // test cases 3
    vector<int> nums3 = {3,3};
    vector<int> ans3 = solution.twoSum(nums3, 6);
    printVec(ans3);

    return 0;
}