#include <iostream>
#include <vector>
#include<algorithm>
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
Space Complexity: O(n^2) including output
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = (long long)nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                long long sum = (long long)nums[i] + nums[j] + nums[k];

                if (llabs(sum - target) < llabs(ans - target))
                    ans = sum;

                if (sum < target) j++;
                else if (sum > target) k--;
                else return target;   // exact match
            }
        }

        return (int)ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> nums = {-1,2,1,-4};
    cout << solution.threeSumClosest(nums, 1) << endl;

    return 0;
}