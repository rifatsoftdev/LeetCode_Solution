#include <iostream>
#include <vector>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimal Solution (2 Pointer Approach):
1. Sort the input array to facilitate the two-pointer technique and to easily skip duplicates.
2. Iterate through the sorted array, fixing one element and using two pointers to find pairs that sum to the negative of the fixed element.
3. Move the left pointer to the right if the sum is less than zero, and move the right pointer to the left if the sum is greater than zero.
4. If a triplet is found, add it to the result and move both pointers while skipping duplicates to avoid repeating the same triplet.

Time Complexity: O(n^2)
Space Complexity: O(log n) auxiliary
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] ==  nums[i-1]) continue;

            for (int j = i+1; j < n; ) {
                int k = j+1, l = n-1;

                while (k < l) {
                    long long sum = (long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[l];

                    if (sum < target)
                        k++;
                    else if (sum > target)
                        l--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k-1]) k++;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j-1]) j++;
            }
        }
        
        return ans;
    }
};


int main() {
    Solution solution;

    vector<int> nums1 = {1,0,-1,0,-2,2};
    vector<vector<int>> ans1 = solution.fourSum(nums1, 0);
    printVec2D(ans1);

    vector<int> nums2 = {2,2,2,2,2};
    vector<vector<int>> ans2 = solution.fourSum(nums2, 8);
    printVec2D(ans2);

    return 0;
}