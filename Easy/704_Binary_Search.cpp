#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Searching Algorithm: Binary Search
1. Initialize two pointers, left and right, to the beginning and end of the array, respectively.
2. While the left pointer is less than or equal to the right pointer:
    a. Calculate the middle index (mid) as the average of left and right.
    b. If the element at mid is equal to the target, return mid (target found).
    c. If the element at mid is less than the target, move the left pointer to mid + 1 (search in the right half).
    d. If the element at mid is greater than the target, move the right pointer to mid - 1 (search in the left half).
3. If the loop ends without finding the target, return -1 (target not found).

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found at index mid
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        return -1; // Target not found
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    cout << solution.search(nums1, target1) << endl; // Output: 4

    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    cout << solution.search(nums2, target2) << endl; // Output: -1
    
    return 0;
}