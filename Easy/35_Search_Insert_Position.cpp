#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Searching Algorithm: Linear Search
1. Iterate through the array from the beginning.
2. For each element, compare it with the target value.
3. If the current element is greater than or equal to the target, return its index as the insertion position.
4. If the loop completes without finding an element greater than or equal to the target, return the size of the array as the insertion position (i.e., the target should be inserted at the end of the array).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.size();
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << solution.searchInsert(nums1, target1) << endl; // Output: 2

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << solution.searchInsert(nums2, target2) << endl; // Output: 1

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << solution.searchInsert(nums3, target3) << endl; // Output: 4

    return 0;
}