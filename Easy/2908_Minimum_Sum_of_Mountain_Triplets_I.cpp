#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Looping):
1. For each element in the array, check if there exists a smaller element to its left and a smaller element to its right.
2. If such elements exist, calculate the sum of the triplet and keep track of the minimum sum found.

Time Complexity: O(n^2) (due to the nested loops)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return -1;

        vector<int> leftMin(n), rightMin(n);

        // Step 1: Fill leftMin
        leftMin[0] = nums[0];
        for(int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i-1], nums[i-1]);
        }

        // Step 2: Fill rightMin
        rightMin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i+1], nums[i+1]);
        }

        int ans = INT_MAX;

        // Step 3: Check every j
        for(int j = 1; j < n-1; j++) {
            if(leftMin[j] < nums[j] && rightMin[j] < nums[j]) {
                ans = min(ans, leftMin[j] + nums[j] + rightMin[j]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {8,6,1,5,3};

    cout << solution.minimumSum(nums) << endl;

    return 0;
}