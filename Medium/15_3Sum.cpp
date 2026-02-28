#include <iostream>
#include <vector>
#include <set>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Solution (3 Nested Loops):
1. Use three nested loops to iterate through all possible triplets in the array.
2. For each triplet, check if the sum is zero. If it is, add the triplet to a set to ensure uniqueness.
3. Convert the set of triplets to a vector and return it.

Time Complexity: O(n^3)
Space Complexity: O(n) for set to store unique triplets
*/

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         set<vector<int>> s;

//         for (int i = 0; i < n; i++) {
//             for (int j = i+1; j < n; j++) {
//                 for (int k = j+1; k < n; k++) {
//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         vector<int> trip = {nums[i], nums[j], nums[k]};
//                         sort(trip.begin(), trip.end());
                        
//                         if (s.find(trip) == s.end()) {
//                             s.insert(trip);
//                             ans.push_back(trip);
//                         }
//                     }
//                 }
//             }
//         }
        
//         return ans;
//     }
// };


/*
Better Solution (Hashing):
1. Iterate through the array and for each element, use a hash set to find pairs that sum to the negative of the current element.
2. For each pair found, create a triplet and sort it to avoid duplicates.
3. Use a set to store unique triplets and return the result as a vector of vectors.

Time Complexity: O(n^2)
Space Complexity: O(n) for set to store unique triplets
*/

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> unicTriplics;

//         for (int i = 0; i < n; i++) {
//             int tar = -nums[i];
//             set<int> s;

//             for (int j = i+1; j < n; j++) {
//                 int third = tar - nums[j];
                
//                 if (s.find(third) != s.end()) {
//                     vector<int> trip = {nums[i], nums[j], third};
//                     sort(trip.begin(), trip.end());

//                     unicTriplics.insert(trip);
//                 }

//                 s.insert(nums[j]);
//             }
//         }
        
//         vector<vector<int>> ans(unicTriplics.begin(), unicTriplics.end());
//         return ans;
//     }
// };


/*
Optimal Solution (2 Pointer Approach):
1. Sort the input array to facilitate the two-pointer technique and to easily skip duplicates.
2. Iterate through the sorted array, fixing one element and using two pointers to find pairs that sum to the negative of the fixed element.
3. Move the left pointer to the right if the sum is less than zero, and move the right pointer to the left if the sum is greater than zero.
4. If a triplet is found, add it to the result and move both pointers while skipping duplicates to avoid repeating the same triplet.

Time Complexity: O(n^2)
Space Complexity: O(log n) auxiliary
Space Complexity: O(n^2) including output
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] ==  nums[i-1]) continue;

            int j = i+1, k = n-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j-1]) j++;
                }
            }
            
        }
        
        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = solution.threeSum(nums);

    printVec2D(ans);

    return 0;
}