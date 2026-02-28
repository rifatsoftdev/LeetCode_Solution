#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Selection Sort: O(n^2)
1. Iterate through the array from the last element to the first.
2. For each position, find the maximum element in the unsorted portion of the array (from the start to the current position).
3. Swap the maximum element with the element at the current position.

Time Complexity: O(n^2) due to the nested loops.
Space Complexity: O(1) as we are sorting the array in place without using any additional data structures.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = nums.size()-1; i >= 0; i--) {
            int max_idx = i;
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[max_idx]) {
                    max_idx = j;
                }
            }
            swap(nums[i], nums[max_idx]);
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {2,0,2,1,1,0};
    solution.sortColors(nums1);
    printVec(nums1);

    vector<int> nums2 = {2,0,1};
    solution.sortColors(nums2);
    printVec(nums2);

    return 0;
}