#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force: O(n^2)
1. Iterate through each element in the array as the starting point of a subarray.
2. For each starting point, iterate through the subsequent elements to calculate the sum of the subarray.
3. Keep track of the maximum sum encountered during the iterations.

Time Complexity: O(n^2) due to the nested loops.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int max_sum = nums[0];
//         for (size_t i = 0; i < nums.size(); ++i) {
//             int current_sum = 0;
//             for (size_t j = i; j < nums.size(); ++j) {
//                 current_sum += nums[j];
//                 max_sum = max(max_sum, current_sum);
//             }
//         }

//         return max_sum;
//     }
// };


/*
Kadane's Algorithm: O(n)
1. Initialize two variables, `current_sum` and `max_sum`, to the value of the first element of the array.
2. Iterate through the array starting from the second element:
   - Update `current_sum` to be the maximum of the current element and the sum of `current_sum` and the current element. This step decides whether to start a new subarray at the current element or to continue the existing subarray.
   - Update `max_sum` to be the maximum of `max_sum` and `current_sum`.
3. After iterating through the array, `max_sum` will contain the maximum sum of a contiguous subarray.

Time Complexity: O(n) as we traverse the array once.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << solution.maxSubArray(nums1) << endl; // Output: 6

    vector<int> nums2 = {1};
    cout << solution.maxSubArray(nums2) << endl; // Output: 1

    vector<int> nums3 = {5,4,-1,7,8};
    cout << solution.maxSubArray(nums3) << endl; // Output: 23


    return 0;
}